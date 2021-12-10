# PyQt入门——MVC计算器
## 设计思想
The Model，这部分是模型的核心功能模块，包含主要功能的代码。对于计算器来说，这一部分就是负责计算的模块。
The View，这一部分负责 GUI 界面。会包含所有的组件，与用户的交互等。对于计算器来说，就是在使用过程中我们看到的窗口界面。
The Controller，这一部分是用来连接上面的 Model 和 View 这两个部分。用户的事件会发送给 controller，然后控制 Model 进行工作。Model 的结果会给 controller，controller 在控制 view 的显示。对于计算器来说，这一部分就是会接受用户在界面的操作，让模型执行相应的计算，更新 GUI。


## 参考资料
https://mathpretty.com/13618.html