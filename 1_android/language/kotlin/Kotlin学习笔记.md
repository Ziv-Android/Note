## 环境搭建
Kotlin，是一门可运行在Java虚拟机，Android，浏览器商的静态语言。  
官方文档：https://kotlinlang.org/doc/reference/

## 基础语法
数据类型：Bollean, int, float, double, long
类和对象：一个类通常可以有很多具体对象
类：一个具有某些特征的事物的概括，是一个抽象的概念，写法`class <类名> { <成员> }`
对象： 是一个居图的概念，描述某一种类的具体个体
类的继承
提取多个类的共性可以得到更抽象的父类
子类拥有父类的一切特征

空类型（?与!!）
智能类型转换（as as? is）

import中的as作用是给类起别名的作用
`improt com.ziv.test.XXX as Abc`

区间：
闭区间[0, 1024] -> val range:IntRange = 0..1024
开区间[0, 1024) -> val range_open:IntRange = 0 until 1024

数组：
`val array = Array<String> = arrayOf()`

var与val  
都具有类型推倒的效果  

运行时常量：val = final  
编译期常量：const + val = static final  

变量：var（variable） 

函数
返回值void -> Unit  
```
// 函数定义
fun[函数名]([参数列表]):[返回值类型]{[函数体]}
fun[函数名]([参数列表]) = [表达式]

// 匿名函数
fun([参数列表])
```

函数功能单一，函数名顾名思义，参数不要过多



## 程序结构

## 面向对象

## 高阶函数

## 领域特定语言——DSL

## 协程

## 与Java混合开发

## 应用与展望