public class ClipUtil {
    private static final int MAX_RETRY_TIME = 3;
    private static final int FIRST_TIME_DELAY = 20;// 首次等待20ms
    private static final int DELAY_TIME_ADD = 20; // 每次增加20ms

    static class GetFormAndroidQTask implements Runnable {
        private int retryTime = 0;
        private Handler mHandler;
        private Context mContext;
        private GetClipCallback mGetClipCallback;
        GetFormAndroidQTask(Context context, Handler handler, GetClipCallback getClipCallback) {
            mHandler = handler;
            mContext = context;
            mGetClipCallback = getClipCallback;
        }

        public void run() {
          ClipboardManager clipboardManager = (ClipboardManager) mContext.getSystemService(Context.CLIPBOARD_SERVICE);
            ClipData clipData = clipboardManager != null ? clipboardManager.getPrimaryClip() : null;
            if (clipData != null) {
                String data = getData(clipboardManager, clipData);
                mGetClipCallback.execute(data);
                return;
            }
            retryTime++;
            if (retryTime < MAX_RETRY_TIME) {
                mHandler.postDelayed(this, FIRST_TIME_DELAY  + retryTime * DELAY_TIME_ADD);
            }
        }
    }

    public static void getClipData(Context context, GetClipCallback clipCallback) {
        String data = null;
        try {
            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.HONEYCOMB) {
                ClipboardManager clipboardManager = (ClipboardManager) context.getSystemService(Context.CLIPBOARD_SERVICE);
                ClipData clipData = clipboardManager != null ? clipboardManager.getPrimaryClip() : null;
                // 如果是android Q执行重试逻辑
                if (clipData == null && android.os.Build.VERSION.SDK_INT >= 29) {
                    Handler handler = new Handler(context.getMainLooper());
                    handler.postDelayed(new GetFormAndroidQTask(context, handler, clipCallback), FIRST_TIME_DELAY);
                    return;
                }
                data = getData(clipboardManager, clipData);
            }
        } catch (Throwable t) {
            t.printStackTrace();
        }
        clipCallback.execute(data);
    }

    private static String getData(ClipboardManager clipboardManager, ClipData clipData) {
        CharSequence data = null;
        if (clipData!= null && clipData.getItemCount() > 0) {
            data = clipData.getItemAt(0).getText();
        }
        // 清空剪切板
         clipboardManager.setPrimaryClip(ClipData.newPlainText(null, ""));
        return data != null ? data.toString() : null;
    }

    public interface GetClipCallback {
        void execute(String clipData);
    }
}