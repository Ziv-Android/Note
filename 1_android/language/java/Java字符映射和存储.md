## 字符
Java => char（2字节），UTF-8（1~3个字节），由Unicode字符集，编码为UTF-16存储

Java的class文件将字符串编码为MUTF-8形式

python => u"" 存放UCS2(UTF-16)编码后字节 => 对应Java中的String => encode
python => "" => 对应Java中的byte[] a = "".getBytes("UTF-8") => decode

## 字符存储
码点：在Unicode代码空间中的一个值，取值0x0至0x10FFFF，将字符映射为数字表示，代表一个字符。由CodePoint相关方法操作
常见的字符集有Unicode，UTF-8等。Java中的char是以UTF-16存储

## UTF-8，UTF-6，UTF-32
UTF-8是一种变长的编码方式，字符长度占1个到4个字节不等

UTF-16结合定长和变长两种编码特点，字符占用2个或4个字节
UTF-16前有两位是代表**字节序**0xFE，0xFF

UTF-32是定长编码，每个码点/字符固定使用4个字节表示。优点：转换简单，查找效率高，缺点：占用空间较大

## 字节序
字节高位放内存高位或字节低位放内存低位则是小端字节序，否则就是大端字节序。当需使用C语言手动将读取到的内存转换为指定的数值类型时，需要知道具体内存的字节序
C/C++：大小都有可能（取决于CPU架构），Java：大端字节序，因此在native读取字节时，需要重点关注由于字节序的问题导致的数据处理错误

使用`ByteOrder.nativeOrder()`获取当前主机字节序

### 主机字节序
驱动相关，无需特别注意，由于CPU存在大端序，小端序的区分，因此引入BOM保证编码后解码的正确性

### 网络字节序
网络协议中默认使用的是大端字节序

### 文件字节序
保存文件的时候可以主动声明使用的字节序，即是否带有BOM（Byte Order Mark）

## 字符串长度
Java中字符串长度与字符数不一致：emoji.length() = 2
Java9对拉丁字符做了存储优化
python3.3之后1哥表情符长度为1，以前的版本与Java一样长度为2

## Java String可以有多长
字面量 -> 栈：受字节码限制，u2为两个字节16位，最大65535，存储在虚拟机方法区常量池，因此还抽运行时方法区限制（嵌入式设备限制）
```
CONSTANT_Utf8_info{
    u1 tag;
    u2 length;
    u1 byte[length];
}
```
但javac在Gen.java中checkStringConstant方法中检查Latin字节数只能小于65535因此报错`Error:java: constant string too long`，但中文经过utf-8编码后在writePool.java中检查没有该问题，kotlinc不存在该问题

文件 -> 堆：虚拟机指令newarray()下ArrayList.java理论最大限制Integer.MAX_VALUE - 8，且受制于虚拟机限制和堆内存


《Java虚拟机规范》，《Java语言规范》
