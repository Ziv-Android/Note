# Kotlin基础
## 什么是Kotlin
Kotlin是基于Jvm虚拟机的编译型计算机编程语言，编译后生成class字节码文件。相比较人类的语言系统，Java与Kotlin各自代表一种方言，经过编译器翻译成普通话后，虚拟机就可以无障碍相互沟通了。C语言以及其他编译型语言对于虚拟机来，解释型语言

val与var
val与var都是变量，但val定义的值不可改变
`const val` 才等于 `public final` 是编译期常量，编译期常量在编译时被替换，相当于C/C++中的宏


属性初始化
lateinit var和by lazy



数组操作：
val array = arrayOf()
求数组长度
Log.d("ziv", "array size = ${array.size}")
遍历Iterator
for (data in array) {

}
区间Range

中缀表达式：
只有一个参数，且使用infix修饰的函数。一般应用于两个相同类型对象之间。适合与两个对象比较。扩展原有对象的功能

面向对象

高阶函数，匿名函数，lambda，内联函数，闭包，尾递归和泛型 