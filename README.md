# NJUST《新标准 C++程序设计》参考答案及题目精析

## 目录

- [出版信息](#出版信息)

- [前言](#前言)

- [贡献者名单](#贡献者名单)

- [第 1 章 —— 概述](#)

- [第 2 章 —— 基本类型与变量](#第-2-章)

- [第 3 章 —— 运算符与表达式](#第-3-章)

- [第 4 章 —— 基本语句](#第-4-章)

- [第 5 章 —— 函数和编译预处理](#第-5-章)

- [第 6 章 —— 数组与字符串](#第-6-章)

- [第 7 章 —— 结构、枚举、联合体](#第-7-章)

- [第 8 章 —— 指针和引用](#第-8-章)

- [第 9 章 —— 类和对象](#第-9-章)

- [第 10 章 —— 类的成员](#第-10-章)

- [第 11 章 —— 类的继承](#第-11-章)

- [第 12 章 —— 运算符重载](#第-12-章)

## 原书出版信息

- 书名：新标准 C++程序设计
- ISBN：978-7-5641-7847-5
- 版次：2018 年 8 月第 1 版（第 2 版目前页码不对应，题目基本对应）

## 前言

本仓库为南京理工大学《新标准 C++程序设计》参考答案.

本答案为民间制作，并非官方标准答案. 如有疏漏之处，欢迎各位大佬批评指正（通过 issue 或者 pull request）.

**⚠ 注意学术诚信，严禁在课堂作业中抄袭本仓库提供的源代码，否则后果自负！**

## 贡献者名单

- 南京理工大学 网络空间安全学院 22 级 Robert Huang（联系 QQ：2191806401）

## 第 2 章

【选择题速查】

DB(ABC)AC BBCCB

DD

---

### 2.1

【答案】**D**

A~C 项均为 C++关键字，`void` 也是关键字，但是 C++区分大小写，`Void` 不同于 `void`，不是关键字.t

---

### 2.2

【答案】**B**

C++中变量名不可以用数字开头（只能以字母或下划线开头）.

---

### 2.3

【答案】**ABC**

四个选项的数据大小依次为 2, 8, 8, 4 字节.

【注】事实上，C++标准中只规定了数据类型的相对大小，并没有规定数据类型的具体大小，比如我们常说 `int` 是 4 个字节大小，但其实在一些单片机上也可以是 2 个字节，所以这个并不绝对. 书中和我们考试时通常默认是常见机器中的数据类型大小（考试以 [课本 P16] 标称的大小为准）.

---

### 2.4

【答案】**A**

参见 [课本 P17 - 2.2.2] 的四种字符型.

---

### 2.5

【答案】**C**

【A 项】十进制整型常量 `38``.

【B 项】`0` 开头，为八进制整型常量，八进制数 `46` 等价于十进制下的 `38`.

【C 项】`0` 开头，为八进制整型常量，八进制的数码为 `0` ~ `7`，不含`8` ，因此是非法的表示.

【D 项】`0B` 开头，为二进制整型常量，二进制数 `100110` 等价于十进制下的 `38`.

---

### 2.6

【答案】**B**

【A 项】`0x` 开头表示十六进制.

【B 项】科学计数法的指数部分必须为整数，不能为小数.

【C 项】表示 `long` 型的字面量量 `5`

【D 项】表示 ASCII 码为八进制 `56` 对应的字符.

---

### 2.7

【答案】**B**

浮点数类型均为有符号类型，没有无符号类型浮点数.

---

### 2.8

【答案】**C**

十六进制字面量应以 `0x` 开头，C 项非法.

---

### 2.9

【答案】**C**

【A 项】双引号括起的类型是字符串字面量，不是字符字面量.

【B 项】为整型字面量.

【C 项】为字符型字面值，其实际值为 `-42`

（八进制 `326` 对应的二进制表示为 `11010110` ，按补码解析为 `-42` ）.

【D 项】非法字面量.

【注】对于 C 项，同学们主要记住 “`\ooo`” 的表示方式上限为 `\377`（即十进制的 `255` ），具体细节可以暂且不深究。

【拓展延伸】[String and character literals (C++), Microsoft Learn](https://learn.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp)

---

### 2.10

【答案】**B**

字符分割如下：
|编号|字符|
|--|--|
|1|`U`|
|2|`g`|
|3|`\'`|
|4|`f`|
|5|`\"`|
|6\*|`\02`|
|7|`8`|
|8\*\*|`'`|

\* 八进制数码范围为 `0` ~ `7` ，`8` 不是八进制数码，因此这个位置会被分割（详情可以参见 [String and character literals (C++), Microsoft Learn](https://learn.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp)）.

\*\* 字符串中 `'` 可以用转义符号，也可以不转义。如果要表示单个的单引号字符，那么必须要转义. 即 `'\''` 表示一个单引号字符.

---

### 2.11

【答案】**D**

参见 [课本 P23 - 2.4.2].

---

### 2.12

【答案】**D**

`u` 表示 `unsigned`，`l` 表示 `long`，`ll` 表示 `long long`

因此四个选项表示的类型依次为 `int`, `unsigned int`, `unsigned long`, `unsigned long long`.

---

### 2.13

【答案】

```
30
1e
36
```

`036` 为八进制字面量，现在依次按照其十进制、十六进制、八进制输出.

---

### 2.14

【答案】

```
Zhao:Hello!How are you?
Liu:I am fine,         Thank you
16      24
```

`\012` 是一个 `char` 型，它与 `int` 型运算时会被提升为`int`型，八进制 `12` 对应十进制的 `14`，因此加 `2` 以后结果为 `16`，`\x12` 同理.

---

### 2.15

【答案】

```
ch1=b ch2=c ch3=b
i=9 j=9 k=9
x=6.9 y=5.8 z=5.8
```

每句语句执行以后三个变量的值用注释依次罗列如下：

```cpp
char ch1 = 'a', ch2 = 'b', ch3 = 'c'; // a b c
ch1 = ch2; // b b c
ch2 = ch3; // b c c
ch3 = ch1; // b c b
```

```cpp
int i = 9, j = 8, k = 7; // 9 8 7
j = k; //9 7 7
k = i; //9 7 9
j = k; //9 9 9
```

```cpp
double x = 3.6, y = 5.8, z = 6.9;
x = y;
y = x;
x = z;
z = y;
```

## 第 3 章

【选择题速查】

CCDBD BCADA

CCBDB DCDD

### 3.1

【答案】**C**

模运算 `%` 要求两个操作数均为整型，

`a %= b` 相当于 `a = a % b`，要求 `a` 和 `b` 均为整型.

---

### 3.2

【答案】**C**

题干的表达式是一个逗号表达式，这类表达式整体的值即为最后一项（ `x+5/3` ）的值.

注意 `5/3` 是两个整型做除法，小数点后会被截去，因此 `5/3` 的值为 `1`.

`x+1` 即为 `4.0`（这里是一个 `double` 类型和一个 `int` 类型运算，结果为 `double` 类型）

【注】虽然说如果把表达式输出的话可能就是个整数 4，但是这里主要是想考察以下大家知道最终表达式是 `double` 类型这个事，不必纠结答案，知道知识点就好.

---

### 3.3

【答案】**D**

【A 项】这是一条条件判断的表达式，不是赋值表达式.

【B 项】根据优先级，先执行 `i++`，得到一个右值，不能对右值执行前置 `++` 操作，因此错误.

【C 项】`a++` 为右值，不能赋值.

【D 项】`i` 被强制转换为 `int` 类型，并赋值给 `a`.

---

### 3.6

【答案】**B**

`x / y * z` 计算的式子为 $\frac{xz}{y}$，与题干不符.

---

### 3.7

【答案】**C**

表达式的运算顺序以及`a`的值示意如下：
|表达式|`a`|
|--|--|
|`a-=a+=a*a`|5|
|`a-=a+=25`|5|
|`a-=30`|30|
|`0`|0|

---

### 3.8

`auto`会自动推导右侧表达式的类型.
因此，`a`为`unsigned int`型，`b`为`int`型（无后缀的整型字面量默认为`int`）.

所以`a*b`为`unsigned int`类型 [课本 P43 - 3.3.1].

---

### 3.9

【答案】**D**

`a` 为 `unsigned int` 类型，`b` 为 `long` 类型，而成相乘为 `unsigned long` 类型 [课本 P43 - 3.3.1（3）]，`decltype` 即为 `unsigned long` 这一类型，因此代码等价于`unsigned long c;`

【注】《C++ Primer （第 5 版）（英文版）》第 161 页中指出，`unsigned int` 和 `long` 运算的结果取决于 `unsigned int` 和 `long` 在具体系统中的大小，该说法比课本描述更加准确.

---

### 3.10

【答案】**A**

对于表达式 `A ? B : C` ，当 `B` 和 `C` 的类型不相同时，将按照 C++相关标准进行类型转换.

【注】本题超纲，不必纠结答案. 看看就好.

【拓展延伸】[Conditional Operator, Microsoft Learn](https://learn.microsoft.com/zh-cn/cpp/cpp/conditional-operator-q)

---

### 3.11

【答案】**C**

表达式的类型和运算情况示意如下：

| 表达式                    | 结构                         |
| ------------------------- | ---------------------------- |
| `16 / 4 * float(4) + 2.0` | `int / int * float + double` |
| `4 * float(4) + 2.0`      | `int * float + double`       |
| `16 + 2.0`                | `float + double`             |
| `18`                      | `double`                     |

---

### 3.12

【答案】**C**

`n + 2` 为 5，原式相当于 `m %= 5`，即 `m = m % 5`，答案为 `3`.

---

### 3.13

【答案】**C**

首先执行 `m = a > b`，值为 `0`，此时根据逻辑运算符的短路逻辑，由于 `&&` 中左边的值已经为假，整个表达式直接计算为假，右边的表达式不再运算。

【拓展延伸】[顺序点, Wikipedia](https://zh.wikipedia.org/wiki/%E9%A1%BA%E5%BA%8F%E7%82%B9)

---

### 3.14

【答案】**D**

D 项中首先计算表达式 `-x`，得到的结果是一个右值，不能对右值执行自减（ `--` ）运算，因此错误.

【注】对于三个 `+` 或者三个 `-` 挨在一起的情况，到底如何解析，C++中有详细但复杂的规定，有兴趣的同学可以研究下拓展延伸中的内容.

【拓展延伸】[What does the operation c=a+++b mean?, stackoverflow](https://stackoverflow.com/questions/7485088/)

---

### 3.15

【答案】**B**

【A 项】结果为 `m`.

【B 项】因为`m`和`n`相同，那么 1 都与 1 异或，0 都与 0 异或，所得二进制位均为 0，因此表达式的值为 0.

【C 项】两个非零值都被转换为`True`，结果为`True`.

【D 项】结果为 `m`.

---

### 3.16

【答案】**D**

【A 项】`or` 不是合法的 C++逻辑运算符.

【B 项】`|` 是位运算符，`||` 才是逻辑运算符.

【C 项】`&&` 表示“且”.

【D 项】`||` 表示“或”.

【注】本题题干不知所云. 现实场景中应该会用到类似于 `18 <= age <= 60` 这样的逻辑，那么 `C` 项能够满足要求，`D` 项是迎合题意之举，不必纠结答案.

---

### 3.17

【答案】**C**

表达式的运算情况示意如下，注意两个整型运算时应向下取整：

`z = 9 / 2 + 2 * 6.6f / 1.1f + 1 / 2`

`z = 4 + 2 * 6.6f / 1.1f + 1 / 2`

`z = 4 + 13.2f / 1.1f + 1 / 2`

`z = 4 + 13.2f / 1.1f + 1 / 2`

`z = 4 + 12.0f + 1 / 2`

`z = 16.0f + 1 / 2`

`z = 16.0f + 0`

`z = 16.0f`

因此输出为 16.

【注】答案给出的运算过程仅为观看方便，实际机内运算顺序未必如此.

---

### 3.18

【答案】**D**

根据表达式的运算顺序，`a > b > c` 中首先计算 `a > b`，结果为 `true`.
进而计算 `true > c` （ `true` 转换为整型的 1），得到结果为 `false`，赋值给 `d` 为 0.

---

### 3.19

【答案】**D**

【D 项】`unsigned int` 和 `int` 长度相同. 有符号数和无符号数运算结果为无符号数，故结果为 `unsigned int`.

---

### 3.20

【答案】

```
7
5
12
```

执行各表达式后 a, b, c 的值如下：
| 表达式 | a | b | c |
| ------ | --- | --- | --- |
| `int a = 10, b = 9, c = 8;` |10 | 9 |8|
| `c = a -= (b - 6);` | 7 | 9 |7|
| `c = a % 8 + (b = 5)`|7|5|12|

---

### 3.21

【答案】

```
6
5
1
```

表达式 `x=y=5`：首先计算 `y=5` ，则变量 y 的值为 5，表示值为 5，继续计算`x=5`，则变量 x 的值为 5.

对于表达式 `z = ++x || ++y`，首先计算 `++x`, 则 x 的值变为 6，此时 `x` 的值非零，因此 `++x` 的值为真，根据条件表达式的**短路逻辑**，不再计算 `++y`，因此 y 值不变. `z` 的值为真，即 `z = 1`.

【拓展延伸】[C++短路求值（逻辑与、逻辑或）实例, phpStudy](https://m.xp.cn/b.php/80071.html)

---

### 3.22

【答案】

```
output
```

---

### 3.23

【答案】

我们可以通过对 2 取余或者位运算来判断偶数.

```cpp
//答案1
(x > 2) && (x % 2 == 0)

//答案2（位运算 &1 其实就是提取了 x 的二进制数中的最后一位，最后一位为0则为偶数）
(x > 2) && (x & 1 == 0)
```

---

### 3.24

【答案】

```cpp
//答案1 （需包含cstdlib头文件）
abs(x) > 8

//答案2
(x>8)||(x-8)
```
---

### 3.25

【答案】

【A】`0`

两个int型变量的除法结果截取小数点后数字，结果为int类型.

【B】`0.333333`

int型变量与浮点数的除法结果为浮点数.

【C】`1`

【D】`7`

---

### 3.26

【答案】

```
output
```

---

### 3.27

【答案】

```
output
```

---

### 3.28（1）

[**示例程序**](chapter_3/ex3_28_1_v1.cpp)

---

### 3.28（2）

[**示例程序**](chapter_3/ex3_28_2_v1.cpp)

---
### 3.28（3）

[**_示例程序 1_**](chapter_3/ex3_28_3_v1.cpp) |
[**_示例程序 2_**](chapter_3/ex3_28_3_v2.cpp)

将输入的浮点数通过 int 强制类型转换提取整数部分，用浮点数减去整数部分即为小数部分.

---

## 第 4 章

【选择题速查】

ACDCD CDACC

---

### 4.1

【答案】**A**

结构化编程的三种基本结构为顺序、选择、循环结构.

顺序执行是程序的一般结构，选择结构通过 `if...else...` 等实现，循环结构通过`for` `while` 等实现.

---

### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---
### 4.2

【答案】**C**

【A 项】.

【B 项】.

【C 项】.

【D 项】.

【注】

【拓展延伸】[Title, Source](https://www.exaple.com/)

---

### 4.11（1）

### 4.11（2）

## 第 5 章

### 5.12

答案是 23，课本无正确选项.

与函数调用不同，宏展开是简单的文本替换，因此不会多加括号.

宏展开以后的程序如下：

```cpp
int main(void)
{
    int x = 1, y = 2, t;
    t = x * y + x * y * 10; //宏展开不会多加括号
    cout << t;
    return 0;
}
```

将 x, y 值代入表达式，显然得到 t 的值为 23.

## 第 6 章

### 6.14(4)

[示例代码 1 (作者：LovinChan)](chapter_6\ex6_14_4_v1.cpp)

## 第 7 章

【选择题速查】

BBCDB BBBCC

DC

### 7.11

| 内存块编号 | 10       | 9   |
| ---------- | -------- | --- |
| 二进制数据 | 00000000 |     |

## 第 8 章

【选择题速查】

CCBDC CCDCB

CAADD CBCDC

DDABC CBBDD

DBCBD BBC

### 8.1

【答案】**C**

`p` 为指向变量 `k` 的指针，`*p` 即对指针 `p` 解引用，其值为变量 `k`（左值），即 8.

### 8.2

【答案】**C**

【A 项】 `f`是`float`类型的变量，声明指向 f 的指针 p 类型应该为 float*，而不是 int*

【B 项】 一般不允许直接使用地址值声明指针

【C 项】 该语句等价于

```cpp
int k;
int *p = &k;
```

语法正确.

【D 项】
该语句等价于

```cpp
int k;
int &p = &k;//Line A
```

A 行代码等号左边表示声明一个 int 变量的引用，等号右边应提供一个 int 型变量，而不是 int 型变量的地址.

### 8.4

【答案】**D**

`NULL`,`0`,`nullptr`均可作为空指针的值

【A 项】 `NULL`是通过宏定义的空指针值（其值为`0LL`）.

【B 项】 `0`可以作为空指针值.

【C 项】 `nullptr`是 C++11 标准规定的用于空指针的关键字（推荐使用）.

【D 项】 不存在`ptrnull`这一关键字.

### 8.19

本题考察嵌套类型的定义.关键的技巧是:从最内层的标识符出发，由内向外依次读取，即可判断出复杂类型的含义.

题干语句定义的是一个函数`f`，参数表为(int \*,int)，返回值为`int*`

定义了一个指针 fp1,指向参数表为(int \*,int)，返回值为`int*`类型的函数，这里指向了符合该类型的函数 f

定义了一个存放了 4 个指针的指针数组 fp2,这些指针指向参数表为(int \*,int)，返回值为`int*`类型的函数，这里 fp2 的第一个元素（fp2[0]）是指向 f 的指针，其余为空指针.

定义了一个函数 f（该函数与题干的函数 f 是重载关系），函数 f 的参数是一个指向函数的指针，被指向的函数返回值为 int\*，参数表为(int \*,int)，函数 f 的返回值是 int\*类型.函数 f 的函数体调用了所传参数指向的函数，并提供 nullptr,3 作为被调函数的参数，将被调函数返回的指针作为函数`f`的返回值返回.

定义了一个函数 f（该函数与题干的函数 f 是重载关系），该函数参数表为空，返回值是一个指向函数的指针，被指向的函数返回值为 int\*，参数表为(int \*,int).选项 f 的函数体返回题干函数 f 的指针，因此 D 项是将函数指针作为了函数的返回值，符合题意.

### 8.35

【答案】B

表达式`a-1+1`计算的结果为 3，这一结果被放置在一块与变量`a`不同的内存空间中.因此通过 ra+=2 修改 ra 值的时候，修改的是 ra 对应内存的值，而不会对 a 的值产生影响.

同学们可以将二者的地址打印出来加以体会：

`cout << &ra << " " << &a << endl;`

【拓展延伸】[R-value references, LEARN C++](https://www.learncpp.com/cpp-tutorial/rvalue-references/)

## 第 9 章

【选择题速查】

CCDCD BD

### 9.1

【答案】**C**

类中可以不包含任意成员.

【注】有同学可能会怀疑——如果没有任何数据成员，默认构造函数不是会被生成吗？其实，可以显式地取消该成员 `A() = delete;`

### 9.2

【答案】**C**

【A 项】 私有成员只能在本类中访问. 当然本选项的这种说法并不严谨，因为可以声明友元函数和友元类使得私有成员能在这些函数和类中访问.

【C 项】 公有成员可以被本类、派生类和类外代码访问.

### 9.3

【答案】**D**

【A 项】 类`A`的对象不能作为类`A`本身的成员. 这种情况的问题之处在于：为了创建类`A`的对象，需要调用`A`的构造函数，而为了创建该对象中的类`A`成员，又要通过`A`的构造函数递归调用`A`的构造函数，如此往复，将是无穷无尽的.

【D 项】不论可见性如何，两个数据成员位于同一个作用域（类作用域）中，该作用域不能重名.

### 9.4

【答案】**C**

【C 项】 类中可以定义重载函数（比如多种构造函数），它们可以重名.

【D 项】如果返回了本类的私有成员的指针或引用，则外部代码可能通过该返回的指针或引用对私有成员进行访问和修改，该操作破坏了对象的封装性.

### 9.5

【答案】**D**

同一类的各对象共用成员函数.

### 9.6

【答案】**B**

【B 项】 对象的引用是对象的别名，使用 `.` 来进行成员访问.

【D 项】私有成员只能在本类中访问. 当然本选项的这种说法并不严谨，因为可以声明友元函数和友元类使得私有成员能在这些函数和类中访问.

### 9.7

【答案】**D**

`this` 指针自动传入非静态成员函数。在其函数体中，如果出现本类的成员名称，则隐含着 `this` 指针访问，不用显式说明.

### 9.8

[示例代码](chapter_9\cat.cpp)

同学们可以自由设计其功能.

## 第 12 章

【选择题速查】BBC

### 12.1

【答案】**B**
参见 [课本 P346]

---

### 12.2

【答案】**B**

---

### 12.3

【答案】**C**

---

### 12.4

【答案】

```
24 27 216
```

### 12.5

[示例代码](chapter_12\ex12_5)
