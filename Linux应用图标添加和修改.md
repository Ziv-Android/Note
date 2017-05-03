使用Ubuntu的过程中经常会遇到图标不见了变成一个灰色的框加中间的问号，虽然不影响使用，但非常影响心情，作为患有强迫症的我们…简直分分钟就在也不想使用这个软件了…
其实Ubuntu的启动图标都在`/usr/share/applications`目录下
cd进入这个目录后Leanote是我们要添加/修改的应用名
```bash
sudo vim Leanote.desktop
```
添加一下配置信息
```bash
[Desktop Entry]
Type=Application
Name=Leanote
Commect=Leanote note
Icon=/home/ziv/Application/Leanote/leanote.png
Exec=/home/ziv/Application/Leanote/Leanote
Terminal=false
Categories=Development;IDE;
```
大功告成
