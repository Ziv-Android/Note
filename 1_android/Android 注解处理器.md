## Java注解
注解就相当于对源代码打的标签，外部工具通过访问这些标签，然后根据不同的标签做出了相应的处理。访问和处理Annotation的工具统称为APT(Annotation Processing Tool)

### 基本语法
基本注解 | 意义 | 注意
--- | --- | ---
@Override | 重写 | 
@Deprecates | 过时 | 
@SuppressWarnings | 忽略警告 | 
@SafeVarargs | 忽略方法参数警告（堆污染） | Java7新增
@FunctionalInterface | 标记是一个接口函数 | Java8新增

### 元注解
@Retention：用于指定被此元注解标注的注解的保留时长
RetentionPolicy.SOURCE | 注解信息只保留在源代码中，编译器编译源码时会将其直接丢弃。
RetentionPolicy.CLASS | 注解信息保留在class文件中，但是虚拟机VM不会持有其信息。
RetentionPolicy.RUNTIME | 注解信息保留在class文件中，而且VM也会持有此注解信息，所以可以通过反射的方式获得注解信息。

@Target：用于指定被此元注解标注的注解可以标注的程序元素
ElementType.TYPE | 标明该注解可用于**类、接口（包括注解类型）或enum声明**
ElementType.FIELD | 标明该注解可用于**字段（域）声明，包括enum实例**
ElementType.METHOD | 标明该注解可用于**方法声明**
ElementType.PARAMETER | 标明该注解可用于**参数声明**
ElementType.CONSTRUCTOR | 标明该注解可用于**构造函数声明**
ElementType.LOCAL_VARIABLE | 标明该注解可用于**局部变量声明**
ElementType.ANNOTATION_TYPE | 标明该注解可用于**注解声明**，注解的注解
ElementType.PACKAGE | 标明该注解可用于**包声明**
ElementType.TYPE_PARAMETER | 标明该注解可用于**参数类型声明**，1.8加入
ElementType.TYPE_USE | 标明该注解可用于**类型使用声明**，1.8加入

@Documented：将被标注的注解生成到javadoc中。

@Inherited：其让被修饰的注解拥有被继承的能力。

@Repeatable ：使被修饰的注解可以重复的注解某一个程序元素。

### 自定义注解
注解是以关键字@interface来定义的，按照有无成员变量可以分为：
标记Annotation：无成员变量，只利用自身是否存在来提供信息。
元数据Annotation：有一个或者多个成员变量，可以接收外界信息。

### APT
Annotation接口是所有注解的父接口（需要通过反编译查看），在java.lang.reflect 反射包下存在一个叫AnnotatedElement接口，其表示程序中可以接受注解的程序元素，例如 类，方法，字段，构造函数，包等等。而Java为使用反射的主要类实现了此接口，如反射包内的Constructor类、Field类、Method类、Package类和Class类。

AnnotatedElement接口的中的API方法:
`<T extends Annotation> T getAnnotation(Class<T> annotationClass);`  | 返回该元素上存在的指定类型的注解，如果不存在则返回 null。
`default <T extends Annotation> T getDeclaredAnnotation(Class<T> annotationClass){}` | 返回该元素上存在的直接修饰该元素的指定类型的注解，如果不存在则返回null.
`Annotation[] getAnnotations();` | 返回该元素上存在的所有注解。
`Annotation[] getDeclaredAnnotations();` | 返回该元素上存在的直接修饰该元素的所有注解。
`default <T extends Annotation> T[] getAnnotationsByType(Class<T> annotationClass){}` | 该方法功能与前面getAnnotation方法类似，但是由于Java8 加入了重复注解功能，因此需要此方法获取修饰该程序元素的指定类型的多个Annotation

### 自定义APT
#### 基本思路
1. 读取注解信息，通过`Class<?> cl = Class.forName(className)`获取Class类
2. 构造生成的类结构，通过`cl.getAnnotation()`反射获取注解信息，并实现预期逻辑
3. 通过JavaPoet或KotlinPoet生成对应的Java/Kotlin文件

#### 注意事项
1. 注解标注的类的继承关系
2. 注解内部类的情况，`$`符号的处理
3. 由于是使用Javac，所以非Java语言存在类型映射问题，如Kotlin与Java
4. 尽量少生成，能通用尽量通用，能使用泛型也是优先使用泛型

### 常用场景
Spring框架：解耦神器。
JUnit :测试框架
ButterKnife :在Android中使用的视图注解框架，Android的小伙伴们都知道。
Dagger2 :依赖注入框架，在Android中用的也比较多。
Retrofit ：Http网络访问框架，Android网络请求标配。
Room ：Google 发布的用于Android开发的本地数据库解决方案库。
ARouter

## 元编程
### compile编译期
APT（注解处理工具）
Bytecode（字节码）RePlugin（360推出）
Generic（泛型）
### runtime运行期
Generic（泛型）
Reflect（反射）
Proxy（动态代理）Retrofit

## 参考资料
[Annotation](https://blog.csdn.net/ShuSheng0007/article/details/80622035)
[Javapoet](https://github.com/square/javapoet)
https://blog.csdn.net/ShuSheng0007/article/details/90734159
https://toutiao.io/posts/3v1wx2/preview
https://juejin.cn/post/6844903564742000648