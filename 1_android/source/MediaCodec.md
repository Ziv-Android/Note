# Mediacodec

## State状态
同步模式
![mediacodec_state](source/pic/mediacodec_states.svg)
异步模式
![mediacodec_async_states](source/pic/mediacodec_async_states.svg)
### 状态详解
Stop：configured，uninitialized，error   
Executing：flushed，running，end-of-stream   
Released

MediaCodec状态流转
1. 创建执行MediaCodec.createEncoderByType()后Codec进入uninitialized状态
2. uninitialized状态下的Codec需要执行configure()进入configured状态后才能执行start()方法
3. 执行start()方法进入Executeing状态，Executeing包含三个子状态：flushed，running，end-of-stream
4. 调用start()后，Codec立即进入flushed状态并持有所有buffer
5. 执行dequeueInputBuffer()拿到第一个输入buffer时，Codec进入running状态（Codec整个生命周期中大部分时间都处在该状态）
6. 当输入buffer为end-of-stream标识时，Codec切换至end-of-stream状态，该状态不再接收输入，但任然会有输出buffer，直到输出buffer遇到end-of-stream
7. Executiing状态下可随时通过flush()方法，使Codec切换至flushed状态
8. 当调用stop()方法后，Codec返回到uninitialized状态，可再次configure
9. 使用结束后必须调用release()方法释放Codec资源
10. error状态Codec处理：使用reset()方法使Codec恢复至uninitalized状态，或者使用release()方法释放

## Mediacodec使用(编码H264视频流，数据源：屏幕数据)
MediaCodec编码H.264
```
import android.media.MediaCodec;
import android.media.MediaCodecInfo;
import android.media.MediaFormat;
import android.util.Log;
import android.view.Surface;

import java.io.IOException;

public class VideoMediaCodec extends MediaCodecBase {
    public static final String TAG = "VideoMediaCodec";
    private Surface mSurface;

    private static final class Constant {
        public static final String MIME_TYPE = "video/avc";

        public static int VIDEO_WIDTH = 800; //横屏w 和 h互换
        public static int VIDEO_HEIGHT = 1280;

        public static int VIDEO_BITRATE = 2000 * 1000;
        public static int VIDEO_FRAME_RATE = 25;
        public static int VIDEO_IFRAME_INTER = 1;
    }

    public static final class Builder {
        private int width = Constant.VIDEO_WIDTH; //横屏w 和 h互换
        private int height = Constant.VIDEO_HEIGHT;

        private int bitRate = Constant.VIDEO_BITRATE;
        private int frameRate = Constant.VIDEO_FRAME_RATE;
        private int iFrameInter = Constant.VIDEO_IFRAME_INTER;

        public Builder setResolution(int width, int height) {
            this.width = width;
            this.height = height;
            return this;
        }

        public Builder setBitRate(int bitRate) {
            this.bitRate = bitRate;
            return this;
        }

        public Builder setFrameRate(int frameRate) {
            if (frameRate <= 1) {
                frameRate = 1;
            }
            if (frameRate >= 30) {
                Log.e(TAG, "Warning: Frame rate suggest in [15, 25]");
            }
            this.frameRate = frameRate;
            return this;
        }

        public Builder setKeyFrameInter(int iFrameInter) {
            this.iFrameInter = iFrameInter;
            return this;
        }

        public void build() {
            Constant.VIDEO_WIDTH = width;
            Constant.VIDEO_HEIGHT = height;

            Constant.VIDEO_BITRATE = bitRate;
            Constant.VIDEO_FRAME_RATE = frameRate;
            Constant.VIDEO_IFRAME_INTER = iFrameInter;
        }
    }

    public Surface getSurface() {
        return mSurface;
    }

    @Override
    public void prepare() {
        try {
            mMediaCodec = MediaCodec.createByCodecName(Constant.MIME_TYPE);
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (mMediaCodec == null) {
            return;
        }
        // 注：没有必要的配置不要乱设置，不要乱设置，不要乱设置
        MediaFormat videoFormat = MediaFormat.createVideoFormat(Constant.MIME_TYPE, Constant.VIDEO_WIDTH, Constant.VIDEO_HEIGHT);
        videoFormat.setInteger(MediaFormat.KEY_FRAME_RATE, Constant.VIDEO_FRAME_RATE);
        videoFormat.setInteger(MediaFormat.KEY_BIT_RATE, Constant.VIDEO_BITRATE);
        videoFormat.setInteger(MediaFormat.KEY_BITRATE_MODE, MediaCodecInfo.EncoderCapabilities.BITRATE_MODE_VBR);
        videoFormat.setInteger(MediaFormat.KEY_COLOR_FORMAT,  MediaCodecInfo.CodecCapabilities.COLOR_FormatSurface);
        videoFormat.setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, Constant.VIDEO_IFRAME_INTER);
        mMediaCodec.configure(videoFormat, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE);
        mSurface = mMediaCodec.createInputSurface();
        start();
    }

    private void start() {
        if (mMediaCodec == null) {
            return;
        }
        isRun = true;
        mMediaCodec.start();
    }

    @Override
    public void release() {
        isRun = false;
        if (mMediaCodec == null) {
            return;
        }
        mMediaCodec.stop();
        mMediaCodec.release();
        mMediaCodec = null;
    }
}
```
MediaCodec抽象，简单实现时可不创建
```
// 抽象类
import android.media.MediaCodec;

public abstract class MediaCodecBase {
    protected volatile boolean isRun = false;
    protected MediaCodec mMediaCodec;

    public abstract void prepare();
    public abstract void release();
}
```
获取屏幕数据，并填入Surface中(API 19)
```
// 将数据填入surface即可，如屏幕数据
import android.content.Context
import android.content.Intent
import android.hardware.display.DisplayManager
import android.hardware.display.VirtualDisplay
import android.media.projection.MediaProjectionManager
import android.os.Bundle
import android.util.DisplayMetrics
import android.util.Log
import android.view.WindowManager
import androidx.appcompat.app.AppCompatActivity
import com.ziv.mediacodecdemo.codec.VideoMediaCodec

class MainActivity : AppCompatActivity() {
    companion object {
        const val TAG = "MainActivity"
        const val REQUEST_CODE = 1002
    }

    private var mMediaCodec: VideoMediaCodec? = null
    private var mMediaProjectionManager: MediaProjectionManager? = null
    private var mVirtualDisplay: VirtualDisplay? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        mMediaProjectionManager =
            getSystemService(Context.MEDIA_PROJECTION_SERVICE) as MediaProjectionManager
        startActivityForResult(mMediaProjectionManager?.createScreenCaptureIntent(), REQUEST_CODE)

        VideoMediaCodec.Builder().setFrameRate(25).build()
        mMediaCodec = VideoMediaCodec()
        mMediaCodec?.prepare()
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if (requestCode == REQUEST_CODE && resultCode == RESULT_OK) {
            try {
                Log.d(TAG, "Permission success.")
                data?.let {
                    val mediaProjection =
                        mMediaProjectionManager?.getMediaProjection(resultCode, data)
                    val displayMetrics = DisplayMetrics()
                    (getSystemService(Context.WINDOW_SERVICE) as WindowManager).defaultDisplay.getMetrics(
                        displayMetrics
                    )
                    val screenDensity = displayMetrics.densityDpi
                    mVirtualDisplay = mediaProjection?.createVirtualDisplay(
                        "$TAG-display",
                        VideoMediaCodec.Constant.VIDEO_WIDTH, VideoMediaCodec.Constant.VIDEO_HEIGHT,
                        screenDensity, DisplayManager.VIRTUAL_DISPLAY_FLAG_AUTO_MIRROR,
                        mMediaCodec?.surface, null, null
                    );
                }
            } catch (e: Exception) {
                Log.e(TAG, "Start screen record service error: " + e.message)
                e.printStackTrace()
            }
        } else {
            Log.e(TAG, "Permission error: 未获得屏幕读取权限.")
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        mMediaCodec?.release()
    }
}
```
获取编码后的数据
```
int outputBufferIndex  = mEncoder.dequeueOutputBuffer(mBufferInfo, TIMEOUT_USEC);
if (outputBufferIndex == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
    MediaFormat outputFormat = mEncoder.getOutputFormat();
    byte[] AVCDecoderConfigurationRecord = Packager.H264Packager.generateAVCDecoderConfigurationRecord(outputFormat);
    int packetLen = Packager.FLVPackager.FLV_VIDEO_TAG_LENGTH +
        AVCDecoderConfigurationRecord.length;
    byte[] finalBuff = new byte[packetLen];
    Packager.FLVPackager.fillFlvVideoTag(finalBuff, 0, true, true, AVCDecoderConfigurationRecord.length);
    System.arraycopy(AVCDecoderConfigurationRecord, 0, finalBuff, Packager.FLVPackager.FLV_VIDEO_TAG_LENGTH, AVCDecoderConfigurationRecord.length);

    H264Data data = new H264Data(finalBuff, 1, 10);
    if (mH264Collector != null) {
        mH264Collector.collect(data);
    }
}

while (outputBufferIndex >= 0) {
    ByteBuffer outputBuffer = mEncoder.getOutputBuffer(outputBufferIndex);

    byte[] outData = new byte[mBufferInfo.size];
    outputBuffer.get(outData);
    if (mBufferInfo.flags == MediaCodec.BUFFER_FLAG_CODEC_CONFIG) {
        configbyte = new byte[mBufferInfo.size];
        configbyte = outData;
    } else if (mBufferInfo.flags == MediaCodec.BUFFER_FLAG_KEY_FRAME) {
        // 每一帧的视频数据
        byte[] keyframe = new byte[mBufferInfo.size + configbyte.length];
        System.arraycopy(configbyte, 0, keyframe, 0, configbyte.length);
        System.arraycopy(outData, 0, keyframe, configbyte.length, outData.length);
        H264Data data = new H264Data(keyframe, 1, mBufferInfo.presentationTimeUs * 1000);
        if (mH264Collector != null) {
            mH264Collector.collect(data);
        }
    } else {
        H264Data data = new H264Data(outData, 2, mBufferInfo.presentationTimeUs * 1000);
        if (mH264Collector != null) {
            mH264Collector.collect(data);
        }
    }
    mEncoder.releaseOutputBuffer(outputBufferIndex, true);
    outputBufferIndex = mEncoder.dequeueOutputBuffer(mBufferInfo, TIMEOUT_USEC);
}
```
## MediaCodec填坑记录
System.err: android.media.MediaCodec$CodecException: Failed to initialize OMX.qcom.video.encoder.avc, error 0xfffffff4   
错误原因： 创建MediaCodec实例超过限制

ACodec: [OMX.allwinner.video.encoder.avc] ERROR(0x80001009)   
错误原因：塞了错误的数据   
入队Frame数据时用了flag（BUFFER_FLAG_CODEC_CONFIG），但是入队的数据中没带sps，pps。或者相反，没用这个flag，数据中带了sps，pps   

Failed to initialize video/avc, error 0xfffffff4   
错误原因：MediaCodec没有调用release方法

Failed to initialize video/avc, error 0xfffffffe   
错误原因：MediaCodec.createByCodecName 只能传详细的编解码器名称(如：OMX.qcom.video.encoder.avc);不能传类型如：video/avc

ACodec: [OMX.rk.video_encoder.avc] stopping checking profiles after 32: 8/1   
ACodec: [OMX.rk.video_encoder.avc] configureCodec returning error -1010   
android.media.MediaCodec$CodecException: Error 0xfffffc0e   
错误原因：创建编码器时，不支持hightProfile属性；

ACodec: [OMX.rk.video_encoder.avc] configureCodec returning error -38   
android.media.MediaCodec$CodecException: Error 0x80001001   
错误原因：MediaFormat.KEY_BITRATE_MODE设置的值，当前设备不支持   

### configure相关
#### IllegalStateException
1. 未设置强制要求的MediaFormat信息
2. 排查Codec状态是否正常，没有在错误的状态调用方法，如release后没有configure就start
3. 解码时当获取MediaCodec.dequeueInputBuffer的值一直抛IllegalStateException时，检查视频流分辨率应小于设备支持最大分辨率（该情况还有可能伴随绿屏现象）

MediaFormat配置参数注意事项：(注：**all keys not marked **optional** are mandatory**)
https://developer.android.com/reference/android/media/MediaFormat.html  
Common video/audio keys
Name |  Value Type |  Description
--- | --- | ---
KEY_MIME | String |  The type of the format.
KEY_CODECS_STRING |  String |  **optional**, the RFC 6381 codecs string of the MediaFormat
KEY_MAX_INPUT_SIZE |  Integer |  **optional**, maximum size of a buffer of input data
KEY_PIXEL_ASPECT_RATIO_WIDTH |  Integer |  **optional**, the pixel aspect ratio width
KEY_PIXEL_ASPECT_RATIO_HEIGHT |  Integer |  **optional**, the pixel aspect ratio height
KEY_BIT_RATE |  Integer |  encoder-only, desired bitrate in bits/second
KEY_DURATION |  long |  the duration of the content (in microseconds)

Video keys
Name |  Value Type |  Description
--- | --- | ---
KEY_WIDTH |  Integer |  
KEY_HEIGHT |  Integer |  
KEY_COLOR_FORMAT |  Integer |  set by the user for encoders, readable in the output format of decoders
KEY_FRAME_RATE |  Integer or Float |  required for encoders, **optional** for decoders
KEY_CAPTURE_RATE |  Integer |  
KEY_I_FRAME_INTERVAL |  Integer (or Float) |  encoder-only, time-interval between key frames. Float support added in Build.VERSION_CODES.N_MR1
KEY_INTRA_REFRESH_PERIOD |  Integer |  encoder-only, **optional**
KEY_LATENCY |  Integer |  encoder-only, **optional**
KEY_MAX_WIDTH |  Integer |  decoder-only, **optional**, max-resolution width
KEY_MAX_HEIGHT |  Integer |  decoder-only, **optional**, max-resolution height
KEY_REPEAT_PREVIOUS_FRAME_AFTER |  Long |  encoder in surface-mode only, **optional**
KEY_PUSH_BLANK_BUFFERS_ON_STOP |  Integer(1) |  decoder rendering to a surface only, **optional**
KEY_TEMPORAL_LAYERING |  String |  encoder only, **optional**, temporal-layering schema

Audio Keys
Name |  Value Type |  Description
--- | --- | ---
KEY_CHANNEL_COUNT |  Integer |  
KEY_SAMPLE_RATE |  Integer |  
KEY_PCM_ENCODING |  Integer |  **optional**
KEY_IS_ADTS |  Integer |  **optional**, if decoding AAC audio content, setting this key to 1 indicates that each audio frame is prefixed by the ADTS header.
KEY_AAC_PROFILE |  Integer |  encoder-only, **optional**, if content is AAC audio, specifies the desired profile.
KEY_AAC_SBR_MODE |  Integer |  encoder-only, **optional**, if content is AAC audio, specifies the desired SBR mode.
KEY_AAC_DRC_TARGET_REFERENCE_LEVEL |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the target reference level.
KEY_AAC_ENCODED_TARGET_LEVEL |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the target reference level used at encoder.
KEY_AAC_DRC_BOOST_FACTOR |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the DRC boost factor.
KEY_AAC_DRC_ATTENUATION_FACTOR |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the DRC attenuation factor.
KEY_AAC_DRC_HEAVY_COMPRESSION |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies whether to use heavy compression.
KEY_AAC_MAX_OUTPUT_CHANNEL_COUNT |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the maximum number of channels the decoder outputs.
KEY_AAC_DRC_EFFECT_TYPE |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the MPEG-D DRC effect type to use.
KEY_AAC_DRC_OUTPUT_LOUDNESS |  Integer |  decoder-only, **optional**, if content is AAC audio, returns the DRC output loudness.
KEY_AAC_DRC_ALBUM_MODE |  Integer |  decoder-only, **optional**, if content is AAC audio, specifies the whether MPEG-D DRC Album Mode is active or not.
KEY_CHANNEL_MASK |  Integer |  **optional**, a mask of audio channel assignments
KEY_ENCODER_DELAY |  Integer |  **optional**, the number of frames to trim from the start of the decoded audio stream.
KEY_ENCODER_PADDING |  Integer |  **optional**, the number of frames to trim from the end of the decoded audio stream.
KEY_FLAC_COMPRESSION_LEVEL |  Integer |  encoder-only, **optional**, if content is FLAC audio, specifies the desired compression level.
KEY_MPEGH_PROFILE_LEVEL_INDICATION |  Integer |  decoder-only, **optional**, if content is MPEG-H audio, specifies the profile and level of the stream.
KEY_MPEGH_COMPATIBLE_SETS |  ByteBuffer |  decoder-only, **optional**, if content is MPEG-H audio, specifies the compatible sets (profile and level) of the stream.
KEY_MPEGH_REFERENCE_CHANNEL_LAYOUT |  Integer |  decoder-only, **optional**, if content is MPEG-H audio, specifies the preferred reference channel layout of the stream.
Subtitle formats have the following keys:
KEY_MIME |  String |  The type of the format.
KEY_LANGUAGE |  String |  The language of the content.
KEY_CAPTION_SERVICE_NUMBER |  int |  **optional**, the closed-caption service or channel number.

Image Keys
Name |  Value Type |  Description
--- | --- | ---
KEY_MIME |  String |  The type of the format.
KEY_WIDTH |  Integer |  
KEY_HEIGHT |  Integer |  
KEY_COLOR_FORMAT |  Integer |  set by the user for encoders, readable in the output format of decoders
KEY_TILE_WIDTH |  Integer |  required if the image has grid
KEY_TILE_HEIGHT |  Integer |  required if the image has grid
KEY_GRID_ROWS |  Integer |  required if the image has grid
KEY_GRID_COLUMNS |  Integer |  required if the image has grid


`cat`命令查看设备文件`/system/etc/media_codecs.xml`，依据设备编解码能力设置，多路大码流也会引起config失败问题，解决方式：1.尽量避免 2.引入软解 3.降低至720p或更低分辨率
```
<MediaCodecs>
    <Include href="media_codecs_google_audio.xml" />
    <Decoders>
        <MediaCodec name="OMX.rk.video_decoder.avc" type="video/avc">
            <Limit name="size" max="4096x2160" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x16"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.m2v" type="video/mpeg2">
            <Limit name="size" max="1920x1088" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x8"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.vp8" type="video/x-vnd.on2.vp8">
            <Limit name="size" max="1920x1088" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x16"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.google.vp9.decoder" type="video/x-vnd.on2.vp9">
            <Limit name="size" min="2x2" max="1280x720" />
            <Limit name="alignment" value="2x2" />
            <Limit name="block-size" value="16x16" />
            <Limit name="blocks-per-second" range="1-983040" />
            <Limit name="bitrate" range="1-40000000" />
            <Feature name="adaptive-playback" />
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.h263" type="video/3gpp">
            <Limit name="size" max="1920x1088" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x16"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.m4v" type="video/mp4v-es">
            <Limit name="size" max="1920x1088" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x16"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.flv1" type="video/flv">
            <Limit name="size" max="1920x1088" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x16"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.mjpeg" type="video/mjpeg">
            <Limit name="size" max="1920x1088" min="176x144"/>
            <Limit name="alignment" value="8x8"/>
            <Limit name="block-size" value="16x16"/>
            <Limit name="blocks-per-second" max="244800" min="1"/>
            <Limit name="bitrate" range="1-10000000"/>
            <Feature name="adaptive-playback"/>
        </MediaCodec>
        <MediaCodec name="OMX.rk.video_decoder.hevc" type="video/hevc">
                <Limit name="size" max="4096x2160" min="176x144"/>
                <Limit name="alignment" value="8x8"/>
                <Limit name="block-size" value="16x16"/>
                <Limit name="blocks-per-second" max="244800" min="1"/>
                <Limit name="bitrate" range="1-10000000"/>
                <Feature name="adaptive-playback"/>
        </MediaCodec>
    </Decoders>

    <Encoders>
        <MediaCodec name="OMX.rk.video_encoder.avc" type="video/avc" >
            <Limit name="size" min="176x144" max="1920x1088" />
            <Limit name="alignment" value="16x8" />
            <Limit name="bitrate" range="1-40000000" />
            <Feature name="bitrate-modes" value="VBR,CBR" />
        </MediaCodec>
    </Encoders>
    <Include href="media_codecs_rk_vpu.xml" />
    <Include href="media_codecs_google_video.xml" />
</MediaCodecs>
```

#### 关键帧
自动触发关键帧设置失效
```
format.setInteger(MediaFormat.KEY_FRAME_RATE, 25)
format.setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, 1)
```
上述配置为：25fps，关键帧间隔1s，即每25帧包含一帧关键帧，但当实际帧率低于25时，将导致关键帧间隔变长
```
// 判断输出数据是否是关键帧
boolean isKeyFrame = (bufferInfo.flags & MediaCodec.BUFFER_FLAGS_KEY_FRAME) != 0;
// 手动触发输出关键帧
if (System.currentTimeMillis() - timeStamp >= 1000) {
    timeStamp = System.currentTimeMillis();
    if (Build.VERSION.SDK_INT >= 23) {
        Bundle params = new Bundle();
        params.putInt(MediaCodec.PARAMETER_KEY_REQUEST_SYNC_FRAME, 0);
        mMediaCodec.setParameters(params);
    }
}
```
如果是通过Camera的PreviewCallback的方式来获取视频数据再喂给MediaCodec的方式是无法控制输出关键帧的数量的。
选择支持颜色格式为yuv420p的编码器时， KEY_I_FRAME_INTERVAL 设置无效
选择支持颜色格式为yuv420sp的编码器时，KEY_I_FRAME_INTERVAL 设置有效
想要控制输出输出关键帧数量就必须通过调用MediaCodec.createInputSurface()方法获取输入Surface，再通过Opengl渲染后喂给MediaCodec才能真正控制关键帧的数量。


花屏
1. 加速解码的丢帧处理，如果丢弃的是关键帧，那么直到下一个关键帧来临之前，全是花屏
2. MediaCodec解码到ByteBuffer中，然后再拿出来渲染，如果stride和width不匹配，色值空间不正确都会导致渲染异常引起的花屏

```
// 获取音视频文件
```

### 解码音频音频无数据

### 解码音频不是从0开始

https://blog.csdn.net/weixin_42462202/article/details/98986535?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-5.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-5.no_search_link

https://github.com/android/media-samples
https://github.com/googlearchive/android-BasicMediaDecoder

http://blog.mediacoderhq.com/h264-profiles-and-levels/
https://support.google.com/youtube/answer/2853702?hl=zh-Hans&ref_topic=9257892#zippy=%2Cp%2Ckp-fps%2Cp-fps

https://www.dnsdizhi.com/332.html
https://www.apiref.com/android-zh/android/media/MediaCodec.html
https://juejin.cn/post/6844903669670871053
https://blog.csdn.net/gb702250823/article/details/81669684
https://blog.csdn.net/junzia/article/details/106036509
https://www.jianshu.com/p/30e596112015
https://daimajiaoliu.com/daima/4ede27b521003f4
https://cloud.tencent.com/developer/article/1749679
https://zhuanlan.zhihu.com/p/71928833
https://zhuanlan.zhihu.com/p/36109778
https://blog.csdn.net/abc_1234d/article/details/80229526?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param
https://blog.csdn.net/u012345283/article/details/38357851
https://www.jianshu.com/p/3f5eaf9d1d9c

https://blog.csdn.net/u011686167/article/details/85256101
https://www.cnblogs.com/ningskyer/articles/7191053.html

https://www.kancloud.cn/owenoranba/jni/120442