## Activity的OnActivityResult使用场景
页面跳转传值时使用，通过Boundle传值，处理逻辑分离，需要开发者自己保证类型安全，和处理逻辑一致问题，实现臃肿

## 使用回调会有什么问题
原Activity不是100%可信，由于内存或策略会被销毁，存在引用需要变换的问题

Activity内的Fragment会持有外部activity的引用，用过这里反射获取新的Activity后刷新在回调接口中


## RxPermission

## kotlin中新增Activity Results API方案

