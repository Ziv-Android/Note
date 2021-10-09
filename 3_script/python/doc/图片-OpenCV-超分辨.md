## 超分辨率
超分辨率(super-resolution)分两种：SISR和VSR。前者叫做单图像超分辨率，后者叫做视频超分辨率。图像超分辨率是计算机视觉领域中一个非常重要的研究问题，广泛应用于医学图像分析、生物识别、视频监控和安全等领域。

## 环境
python支持需要安装 **OpenCV 3.4+** 及以上版本，推荐安装方式：
1. 下载安装对应平台的OpenCV https://opencv.org/releases/
2. 卸载之前安装的 opencv-python 相关
3. 执行`pip3 install opencv-contrib-python`

## OpenCV超分辨率模型
理论参考和模型下载地址见下表

_ | 描述 | 论文地址 | github地址
--- | --- | --- | ---
EDSR | 用于单图像超分辨率的增强型深度残差网络 | https://arxiv.org/abs/1707.02921 | https://github.com/Saafke/EDSR_Tensorflow
ESPCN | 卷积神经网络进行实时单图像和视频超分辨率 | https://arxiv.org/abs/1609.05158 | https://github.com/fannymonori/TF-ESPCN
FSRCNN | 加速超分辨率卷积神经网络 | https://arxiv.org/abs/1608.00367 | https://github.com/Saafke/FSRCNN_Tensorflow
LapSRN | 使用拉普拉斯金字塔网络实现 | https://github.com/fannymonori/TF-LAPSRN | https://github.com/fannymonori/TF-LAPSRN

有实验如下  
EDSR：这个是表现最好的模型。但是这个模型也是最大的，所以运行速度会比较慢。  
ESPCN：这个模型具有速度快，效果好的特点，并且模型较小。它可以进行对视频进行实时处理（取决于图像大小）。  
FSRCNN：这也是具有快速准确推断功能的小型模型。也可以进行实时视频升频。  
LapSRN：这是一个中等大小的模型，它的特点是最大可以将图像放大8倍。  


https://blog.csdn.net/LuohenYJ/article/details/108207700
