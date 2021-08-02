## 泛型
Java1.5引入泛型概念，即参数化类型。用于解决在不创建新的类型的情况下，来控制形参具体限制的类型。即**操作的数据类型被指定为一个参数**，可用于类，接口和方法中，分别称为泛型类，泛型接口，泛型方法。

## 为什么要使用泛型
1. 从语言设计方面来说，泛型的使用是为了兼容Java1.5之前版本
2. 从开发角度讲，泛型提高代码的重用性，由于泛型提供了类型检查，所以减少了大量的数据类型转换，同时保证了类型安全
3. 从虚拟机方面讲，泛型使用了类型擦除，减轻方法区内存压力

## 泛型缺陷
基本类型无法作为泛型实参：装箱拆箱的消耗，[**SparseArray**](#sparsearray)  
泛型类型不能用作方法重载，擦除后没有区别
泛型类型不能作为真实类型使用，如new，获取类型（.class），instanceof等，只能用于创建其他的泛型类型
静态方法不能引用类泛型参数，类泛型参数只有在实例化时才会确定，如果静态方法需要使用泛型时，则给静态方法直接声明泛型即可

类型强转的运行时开销
对反射的影响（需要附加签名信息，混淆后需要注意是否已被删除）：getGenericReturnType获取真实type，Kotlin中使用Metadata注解保存这些类型信息

Gson与Retrofit内

## 常见的泛型起名
K 键 => Key：映射的键类型
V 值 => Value：映射的值类型
E 元素 => Element：元素类型
T 泛型 => Type：通用类型

## 泛型的限定符
`? extends Type`：子类限定
`? super Type`：父类限定
`?`：无限定

PECE 原则: Producer Extends, Consumer Super
extends 处理可读不可写
super   处理可写不可读

## [SparseArray](https://developer.android.com/reference/android/util/SparseArray)
SparseArray系列中有SparseArray，SparseIntArray，SparseBooleanAarray，SparseLongArray等  
### 常用操作
SparseArray初始化建立两个数组，数据使用put()存放，remove()删除，get()获取。
### put
key冲突时或与key对应的value为DELECT时，直接覆盖添加新value数据  
添加失败检查是否需要执行SparseArray的gc()并在该索引重试插入  
满容且无法gc()时需要对数组进行扩容，然后再插入

注：由于SparseArray的索引值Index是有序的，所以可以采用二分法查找对应索引位置，因此在插入失败时，对已经得到的结果做取反返回，这样既能得知插入失败，而且还能得知插入失败的索引位置
### remove
删除分两步操作——为了保持索引结构，同时不会频繁压缩数组，保证索引查询不会错位
1. remove删除value数组中的值，转变为DELETE
2. key的删除是在执行SparseArray的gc()时进行处理

### get
二分查找获取Key的索引，通过索引拿到value值

### SparseArray中的gc()
遍历检查value为DELETE的元素，并将后续元素移动到该处，时间复杂度O(n)，空间复杂度O(1)

### SparseArray与HashMap相比的优缺点
优势：
1. 避免了基本数据类型的装箱操作
2. 不需要额外的结构体，单个元素的存储成本更低
3. 数据量小的情况下，随机访问的效率更高

缺点：
1. 插入操作需要复制数组，增删效率降低
2. 数据量巨大时，复制数组成本巨大，gc()成本也巨大
3. 数据量巨大时，查询效率也会明显下降
