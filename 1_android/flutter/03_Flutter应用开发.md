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
.../image.png
.../2.0x/image.png
.../3.0x/image.png


## 调试

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