## 路由管理
路由(Route)：在移动开发中通常指页面(Page)，Web单页中的Route，Android中的Activity，iOS中的ViewController。  
路由管理：管理页面之间如何跳转，又称导航管理。路由管理维护路由栈，打开页面对应路由入栈(push)操作，页面关闭对应路由出栈(pull)  

### PageRoute
抽象类 - 占有整个屏幕空间的路由页面，包含路由构建及切换时的过渡动画  

MaterialPageRoute：Material风格
1. Android：打开页面从底部滑动至屏幕顶部，关闭页面从屏幕顶部滑动至底部消失
2. iOS：打开页面从右侧滑动至屏幕左边，关闭页面从屏幕右侧滑动至左侧

构造方法
```
MaterialPageRoute({
    WidgetBuilder builder,
    RouteSettings settings,
    bool maintainState = true,
    bool fullscreenDialog = false,
})
```
1. builder：WidgetBuilder类型回调函数，构建路由页面具体内容返回新路由的实例（widget）
2. settings：包含路由的配置信息，如路由名称、是否是初始路由（首页）
3. maintainState：默认新路由入栈时，原页面任然存在内存中，设置false会在原路由没有使用时释放资源
4. fullscreenDialog：新路由页面是否是一个全屏对话框，iOS中如过设置为true，新页面将从屏幕底部滑出作为对话框显示

### 命名路由
通过给页面定义的“名字”操作路由，使路由管理直观、简洁  

注册路由表`Map<String, WidgetBuilder> routes`
```
MaterialApp(
    title: 'Demo',
    // 定义home路由（首页）
    initialRoute: "/",
    // 注册路由表
    routes: {
        "new_page": (context) => NewPage(),
        "/": (context) => HomePage(),
    }
)
```

### Navigator
Future push(BuildContext context, Route route)  
给定路由route入栈（打开新页面），返回Future接收新路由出栈时的返回值（startActivityForResult）  
`Navigator.of(context).push(Route route)`  

replace  

Future pushNamed(BuildContext context, String routeName, {Object arguments})
`Navigator.pushNamed(context, "new_page")`

pushReplacementNamed

bool pop(BuildContext context, [result])  
栈顶路由出栈，result为页面关闭需要返回给下一页面的数据  
`Navigator.of(context).pop([result])`

popUntil  

### 路由传值
1. 非命名路由
通过构造函数定义数据类型进行数据传递，对应的result返回值可通过Navigator.of(context).pop(result)
注：点击导航栏返回箭头返回时没有返回数据

2. 命名路由
参数传递方：`Navigator.of(context).pushNamed("new_page", arguments: {"key": "value"})`
参数接收方：`var args = ModelRoute.of(context).settings.arguments`

### 路由钩子
打开命名路由时，如果命名路由已经在路由表注册则调用`build`函数生成组件，如果没有注册则调用`MaterialApp.onGenerateRoute`属性用于打开命名路由之前，实现统一权限控制。
`onGenerateRoute`只对命名路由生效

navigatorObservers：监听所有路由跳转动作

inUnknownRoute：路由也不存在时回调

## 包管理
`pubspec.yaml`文件
字段 | 释义
--- | ---
name | 名称
description | 描述，简介
version | 版本号
dependencies | 依赖
dev_dependencies | 开发环境依赖
flutter | flutter相关配置选项

dependencies下的依赖包作为App源码的一部分参与编译，最终打包在App中
dev_dependencies 常用于配置开发阶段的测试工具包，用于提高开发测试效率

### Pub仓库
Pub仓库：https://pub.dev/

添加需要的包后执行`flutter packages get`

### 本地仓库
假定包名为`pkg1`
```
dependencies:
    pkg1:
        path: ../../code/pkg1
```
路径可以是相对的，也可以是绝对的

### Git仓库
同样假定包名为`pkg1`，使用path参数指定相对位置
```
dependencies:
    pkg1:
        git:
            url: git://github.com/xxx/xx/pkg1.git
            path: ../../code/pkg1
```

## 资源管理
Flutter APP安装包中会包含代码和 assets（资源）两部分。Assets是会打包到程序安装包中的，可在运行时访问。常见类型的assets包括静态数据（例如JSON文件）、配置文件、图标和图片（JPEG，WebP，GIF，动画WebP / GIF，PNG，BMP和WBMP）等

指定assets
```
flutter:
    assets:
        - assets/ic_launcher.png
        - assets/background.png
```
构建期间，Flutter将asset放置在asset bundle存档中，程序可在运行时读取，但不能修改

变体资源：用于扩展本地化支持等

加载assets文本，使用rootBundle对象加载或DefaultAssetBundle
```
import 'dart:async' show Future;
import 'package:flutter/services.dart' show rootBundle;

Future<String> loadAsset() async {
  return await rootBundle.loadString('assets/config.json');
}
```

加载assets图片，使用AssetImage类
```
Widget build(BuildContext context) {
  return new DecoratedBox(
    decoration: new BoxDecoration(
      image: new DecorationImage(
        image: new AssetImage('graphics/background.png'),
      ),
    ),
  );
}
```

声明像素比例资源
.../image.png
.../2.0x/image.png
.../3.0x/image.png

控制缩放参数需使用ImageStream或ImageCache来加载图片资源， 加载依赖包中的资源必须先为AssetImage提供package参数
```
// 返回为ImageProvider
new AssetImage('icons/heart.png', package: 'package_icons')
// 返回时一个weight
new Image.asset('icons/heart.png', package: 'package_icons')
```

打包依赖包中的资源，需要在`pubspec.yaml`文件中声明，假设包为`test_backgrounds`资源在`../lib/backgrounds/`目录下，则：
```
flutter:
    assets:
        - packages/test_backgrounds/backgrounds/xxx.png
```

## 调试
### Widget
调试Widget树（转存储Widgets树状态）: 只要应用程序已经构建了至少一次（即在调用build()之后的任何时间），解决简单的布局问题，一般从frame回调或事件处理器中调用它是最佳解决方案。
```
debugDumpApp()
```
输出构建函数对应的所有widget，即在widget树的跟中调用toStringDeepwidget
```
I/flutter ( 6559): WidgetsFlutterBinding - CHECKED MODE
I/flutter ( 6559): RenderObjectToWidgetAdapter<RenderBox>([GlobalObjectKey RenderView(497039273)]; renderObject: RenderView)
I/flutter ( 6559): └MaterialApp(state: _MaterialAppState(1009803148))
I/flutter ( 6559):  └ScrollConfiguration()
I/flutter ( 6559):   └AnimatedTheme(duration: 200ms; state: _AnimatedThemeState(543295893; ticker inactive; ThemeDataTween(ThemeData(Brightness.light Color(0xff2196f3) etc...) → null)))
I/flutter ( 6559):    └Theme(ThemeData(Brightness.light Color(0xff2196f3) etc...))
I/flutter ( 6559):     └WidgetsApp([GlobalObjectKey _MaterialAppState(1009803148)]; state: _WidgetsAppState(552902158))
I/flutter ( 6559):      └CheckedModeBanner()
I/flutter ( 6559):       └Banner()
I/flutter ( 6559):        └CustomPaint(renderObject: RenderCustomPaint)
I/flutter ( 6559):         └DefaultTextStyle(inherit: true; color: Color(0xd0ff0000); family: "monospace"; size: 48.0; weight: 900; decoration: double Color(0xffffff00) TextDecoration.underline)
I/flutter ( 6559):          └MediaQuery(MediaQueryData(size: Size(411.4, 683.4), devicePixelRatio: 2.625, textScaleFactor: 1.0, padding: EdgeInsets(0.0, 24.0, 0.0, 0.0)))
I/flutter ( 6559):           └LocaleQuery(null)
I/flutter ( 6559):            └Title(color: Color(0xff2196f3))
```
```
import 'package:flutter'
```
自定义widget可通过覆盖`debugFillProperties()`来添加信息，将DiagnosticsProperty (opens new window)对象作为方法参数，并调用父类方法。

### RenderTree
调试渲染树（转存储RenderTree），解决较复杂的UI问题，一般从frame回调或事件处理器中调用它是最佳解决方案。
```
import 'package:flutter/rendering.dart';

debugDumpRenderTree()
```
对应根RenderObject的toStringDeep，调试布局问题时，关键看`size`和`constraints`字段，约束向下传递，尺寸向上传递
```
I/flutter ( 6559): RenderView
I/flutter ( 6559):  │ debug mode enabled - android
I/flutter ( 6559):  │ window size: Size(1080.0, 1794.0) (in physical pixels)
I/flutter ( 6559):  │ device pixel ratio: 2.625 (physical pixels per logical pixel)
I/flutter ( 6559):  │ configuration: Size(411.4, 683.4) at 2.625x (in logical pixels)
I/flutter ( 6559):  │
I/flutter ( 6559):  └─child: RenderCustomPaint
I/flutter ( 6559):    │ creator: CustomPaint ← Banner ← CheckedModeBanner ←
I/flutter ( 6559):    │   WidgetsApp-[GlobalObjectKey _MaterialAppState(1009803148)] ←
I/flutter ( 6559):    │   Theme ← AnimatedTheme ← ScrollConfiguration ← MaterialApp ←
I/flutter ( 6559):    │   [root]
I/flutter ( 6559):    │ parentData: <none>
I/flutter ( 6559):    │ constraints: BoxConstraints(w=411.4, h=683.4)
I/flutter ( 6559):    │ size: Size(411.4, 683.4)
```
自定义widget可通过覆盖`debugFillProperties()`来添加信息，将DiagnosticsProperty (opens new window)对象作为方法参数，并调用父类方法。

### LayerTree
调试Layer合成问题，
```
debugDumpLayerTree()
```
对应根Layer的toStringDeep输出
```
I/flutter : TransformLayer
I/flutter :  │ creator: [root]
I/flutter :  │ offset: Offset(0.0, 0.0)
I/flutter :  │ transform:
I/flutter :  │   [0] 3.5,0.0,0.0,0.0
I/flutter :  │   [1] 0.0,3.5,0.0,0.0
I/flutter :  │   [2] 0.0,0.0,1.0,0.0
I/flutter :  │   [3] 0.0,0.0,0.0,1.0
I/flutter :  │
I/flutter :  ├─child 1: OffsetLayer
I/flutter :  │ │ creator: RepaintBoundary ← _FocusScope ← Semantics ← Focus-[GlobalObjectKey MaterialPageRoute(560156430)] ← _ModalScope-[GlobalKey 328026813] ← _OverlayEntry-[GlobalKey 388965355] ← Stack ← Overlay-[GlobalKey 625702218] ← Navigator-[GlobalObjectKey _MaterialAppState(859106034)] ← Title ← ⋯
I/flutter :  │ │ offset: Offset(0.0, 0.0)
I/flutter :  │ │
I/flutter :  │ └─child 1: PictureLayer
I/flutter :  │
I/flutter :  └─child 2: PictureLayer
```
根部的变换时应用设备像素比的变换，上述例子中，每个逻辑像素代表3.5个设备像素

### 语义树
获取语义树（呈现给系统可访问性API的树）的转储，要使用此功能，必须首先启用辅助功能，例如启用系统辅助工具或SemanticsDebugger
```
debugDumpSemanticsTree()
```

### 调度
要找出相对于帧的开始/结束事件发生的位置，可以分别判断
debugPrintBeginFrameBanner -> 帧的开始
debugPrintEndFrameBanner ->  帧的结束

打印当前帧被调度的调用堆栈
```
debugPrintScheduleFrameStacks
```

### 可视化调试
通过设置`debugPaintSizeEnabled`为`true`以可视方式调试布局问题，推荐在`void main()`顶部设置，启用后：
1. 所有的Widget被包裹一个深青色边框，padding显示为浅蓝色
2. 子widget周围为深蓝色边框，
3. 对齐方式显示为黄色箭头
4. 空白以灰色显示

`debugPaintBaselinesEnabled`具有基线对象：
1. 文字基线以绿色显示
2. 表意基线以橙色显示

`debugPaintPointersEnabled`点击对象突出以深青色显示

调试合成图层
`debugPaintLayerBordersEnabled`：用橙色或轮廓线标出每一层的边界
`debugRepaintRainbowEnabled`：图层重绘时，该层会被一组旋转色覆盖

### 调试动画
设置动画timeDilation变量为大于1.0的数字，如50.0，且运行时不要参与修改

### 调试UI性能问题
debugPrintMarkNeedsLayoutStacks：调试重新布局问题
debugPrintMarkNeedsPaintStacks：调试重新绘制问题
可以使用services库中的debugPrintStack()方法按需打印堆栈痕迹

### 统计应用启动时间
收集有关Flutter应用程序启动所需时间的详细信息
```
flutter run --trace-startup --profile
```

输出`start_up_info.json`（单位微秒）
```
{
  "engineEnterTimestampMicros": 96025565262,
  "timeToFirstFrameMicros": 2171978,
  "timeToFrameworkInitMicros": 514585,
  "timeAfterFrameworkInitMicros": 1657393
}
```
engineEnterTimestampMicros -> 进入Flutter引擎时  
timeToFirstFrameMicros -> 展示应用第一帧时  
timeToFrameworkInitMicros -> 初始化Flutter框架时  
timeAfterFrameworkInitMicros -> 完成Flutter框架初始化时  

### 跟踪代码逻辑性能
类似Android平台systrace
```
import 'dart:developer';

Timeline.startSync("感兴趣的方法");
// some code
Timeline.finishSync();
```
然后打开应用程序中的Observatory timeline页面，在`Recorded Streams`中选择`Dart`复选框，并执行想测量的功能

### DevTools

Dart分析器`flutter analyze`静态代码检查工具

语句级单步调试分析器

debugger()声明

## 异常捕获

## 屏幕适配
使用 `MediaQuery.of(context).size.width` 获取屏幕宽度，从而切换布局
```flutter
//判断屏幕宽度
if (MediaQuery.of(context).size.width > 600) {
    isLargeScreen = true;
} else {
    isLargeScreen = false;
}
```

包裹`new OrientationBuilder()`监听横竖屏变化`Orientation. portrait`，如果不需要可以去掉。返回两个widget在Row中管理，如果是小屏幕，使用空的**Container()**占位，否则使用**Expanded()**扩展
```
body: new OrientationBuilder(builder: (context, orization) {
    return new Row(
        mainAxisSize: MainAxisSize.max,
        children: <widget>[
            new Expanded(child: new ListWidget()),
            isLargeScreen ? new Expanded(child: new DetailWidget(selectValue)) : new Container()
        ],
    );
}),
```
处理点击事件
```
if (isLargeScreen) {
    selectValue = value;
    setState(() {});
} else {
    Navigator.of(context).push(new MaterialPageRoute(builder: (context) {
        return new DetailWidget(value);
    }));
}
```
强制横竖屏的操作
```
// 强制竖屏
SystemChrome.setPreferredOrientations([
    DeviceOrientation.portraitUp,
    DeviceOrientation.portraitDown
]);
// 强制横屏
SystemChrome.setPreferredOrientations([
    DeviceOrientation.landscapeLeft,
    DeviceOrientation.landscapeRight
]);
```