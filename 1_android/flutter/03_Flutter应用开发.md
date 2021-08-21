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

pushReplacementNamed

bool pop(BuildContext context, [result])  
栈顶路由出栈，result为页面关闭需要返回给下一页面的数据  
`Navigator.of(context).pop([result])`

popUntil  

### 路由传值



## 包管理

## 资源管理

## 调试

## 异常捕获