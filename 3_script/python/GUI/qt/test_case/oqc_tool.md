## 背景

在这之前做的工具是使用C++&MFC开发.合作开发较为困难,增加\修改功能必须由特定的人去搞定.

另一个,工具在最初设计时没有考虑客户学习和使用成本.
很多功能就是码上了,没有流程和用户体验造成用户使用时还得配套其他(网页)等才能完成功能操作;

最后,工具开发还是使用尽可能便利的语言开发比较好,开发成本低复用性高;
工厂工具,自动化测试使用同一套测试;
往后老化软件,出厂工具可以增加测试项,hold住更多功能;扩大测试量扩大测试范围,稳定性也能够提升;
    
## 文件设计

1. mainwindow主窗口
    
    主要是一个QStackedWidget,用于包含其他QWidget;当在工具主页中选择对应的功能时就展示对应页面的QWidget;
    
2. w1_product_chanage选择产品型号窗口
    
    测试之前需要选择对应的测试产品型号.产品型号包括测试项,以及特殊参数.
    
    例如:H高位产品型号包含了镜头型号,选择产品型号后;测试之始自动配置镜头型号和云台等矫正参数,以便后续功能使用.

3. w2_test_widget测试主窗口
    
    整个界面分为左右;
    
    左边是一个QWidget,用于展示设备列表和测试单元;
    
    右边是一个QStackedWidget,用于展示具体测试项;当测试一项时,展示对应的测试项QWidget;与左边的测试单元一一匹配;
    
4. w2x_xxxxx_xxxxx测试项窗口

    具体的测试单元界面;把相近或有关的测试项整合到一个界面来展示\测试;大多后续增加或修改都会集中到此类界面中;
    
    例如:视频相关测试包括:镜头(变倍,变焦,DC-IRIS,IR-CUT),云台,补光灯;所以把它们放在一页测试;

5. w3_aging_tools老化工具

    老化测试工具,


## 应用层文件夹说明

- product\h1m: 产品信息文件夹,product与程序一个层级;
- product\h1m\image: 产品配套照片文件夹,展现各个产品型号不同之特点;
- product\h1m\customer.ini: 产品生产对应销售客户列表,如果产品客户有特殊配置,在此设定;
- product\h1m\xxxxxxxx.ini: 产品型号文件,产品描述,产品测试点设置;
 