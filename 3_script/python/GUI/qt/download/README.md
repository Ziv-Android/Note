# �ٶ�ͼƬ����������
![](https://raw.githubusercontent.com/Beeder/BaiduImageDownloader/master/BaiduImageDownloader.png)

ʹ��python3 + pyqt5 + eric6 + cx_Freeze4��ɣ���ϸ�����뿴[�ҵĲ���](http://www.bitjoy.net/2015/08/13/baidu-image-downloader-python3-pyqt5-eric6-cx_freeze4/)

# �ļ�����
```
|--__pycache__��python�����ļ�����
|
|--_eric6project��eric6��Ŀ�ļ�����
|
|--build��cx_Freeze4�������
|
|--dist��cx_Freeze4������ɵĿ�ִ���ļ�
|
|--BaiduImageDownloader.e4p��eric6��Ŀ�ļ�
|
|--BaiduImageDownloader.png�������ͼ
|
|--DownloadEngine.py��python3���߳�������
|
|--Ui_main.py��qt5���沼�ִ���
|
|--__init__.py���Զ����ɵ��ļ�����
|
|--main.py����Ŀ������
|
|--main.ui��qt gui�����ļ�
|
|--setup.py��cx_Freeze4����ű�
```
��Ҫ�ļ���main.py��DownloadEngine.py

# ʹ�÷���
#### ����Գ��

���ΰ�װ[python-3.4.3.amd64.msi](https://www.python.org/ftp/python/3.4.3/python-3.4.3.amd64.msi)��[PyQt5-5.5-gpl-Py3.4-Qt5.5.0-x64.exe](http://sourceforge.net/projects/pyqt/files/PyQt5/PyQt-5.5/PyQt5-5.5-gpl-Py3.4-Qt5.5.0-x64.exe)��[eric6-6.0.8.zip](http://downloads.sourceforge.net/project/eric-ide/eric6/stable/6.0.8/eric6-6.0.8.zip?r=http%3A%2F%2Fsourceforge.net%2Fprojects%2Feric-ide%2Ffiles%2Feric6%2Fstable%2F&ts=1439435222&use_mirror=nchc)��

1. ���ظ���Ŀ���д��룬�ڵ�ǰ·��ִ��`python main.py`
2. ���ظ���Ŀ���д��룬����eric6��ѡ��main.py����F2ִ��

#### ���ࣺ

WIN7 64λ�û�ֱ������[BaiduImageDownloader-0.2-amd64.msi](https://github.com/01joy/BaiduImageDownloader/blob/master/dist/BaiduImageDownloader-0.2-amd64.msi?raw=true)��װ���ڰ�װĿ¼��˫��main.exe���С�

# ��֪bug

1. ����洢Ŀ¼����Ϊĳ����Ŀ¼��ͼƬд��ʧ�ܣ���Ϊ��Ŀ¼��c:/����ʽ���ᵼ������c://a.jpg�������ļ�������д��ʧ�ܣ����˸�б��/�����������Ŀ¼c:/img����ƴ��Ϊc:/img/a.jpg��ȷ��
2. ~~�ؼ���Ϊ`У��`��ͼƬ�ߴ�Ϊ`�ش�`ʱ�����������[������JSON decode��ĳ������](http://stackoverflow.com/questions/15198426/fixing-invalid-json-escape)��~~
3. http://image.baidu.com/i?tn=resultjson&ie=utf-8&word=%s �ٶ�ͼƬȡjson��APIʧЧ��[����Ѱ����](http://blog.csdn.net/ttdevs/article/details/13768421)��