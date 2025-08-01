# 2.1.1 算术类型

## 类型选择

1. 明确知道数值不为负数时，选择无符号类型
2. 整数运算用 int，超过范围用 long long
3. 算术表达式不要用 char 或 bool
4. 浮点数用double

## 练习

### 练习2.1

类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

答：C++ 规定 `short` 和 `int` 至少16位，`long` 至少32位，`long long` 至少64位；带符号类型能够表示正数、负数和 0 ，而无符号类型只能够表示 0 和正整数；float是单精度浮点数，double是双精度浮点数，执行浮点运算时用 `double` ，因为 `float` 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。

### 练习2.2

计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

答：使用 `double` 或 `float` 。

# 2.1.2 类型转换

## 带符号类型和无符号类型

**不要混用带符号类型和无符号类型**

## 练习

### 练习2.3

读程序写结果

答：32，溢出，32，-32，0，0

### 练习2.4

编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

# 2.1.3 字面值常量

## 字面值常量

字面值常量的值一眼就可以看出，每个字面值常量都对应一种数据类型，字面值常量的形式和值决定了它的数据类型

如果两个字符串位置紧邻且仅由**空格、缩进和换行符**分割，则它们实际上是一个整体。因此当字符串字面值比较长不适合放到一行里时，可以分开书写

## 宽字符

宽字符是宽度始终为 16 位的多语言字符代码。 字符常量的类型是 **`char`**；对于宽字符，该类型是 **`wchar_t`**。 由于宽字符始终具有固定大小，因此使用宽字符集可以简化使用国际字符集进行的编程。

宽字符串文本 `L"hello"` 将成为类型为 **`wchar_t`** 的六个整数的数组。

## 练习

### 练习2.5

指出下述字面值的数据类型并说明每一组内几种字面值的区别：

- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值。

(b): 十进制整型，十进制无符号整型，十进制长整型，十进制无符号长整型，八进制整型，十六进制整型。

(c): double, float, long double

(d): 十进制整型，十进制无符号整型，double, double

### 练习2.6

下面两组定义是否有区别，如果有，请叙述之：

```C++
int month = 9, day = 7;
int month = 09, day = 07;
```

答：有区别，第一行是十进制整型，第二行是八进制整型，且第二行的month无效，因为八进制没有9

### 练习2.7

下述字面值表示何种含义？它们各自的数据类型是什么？

- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?(换行)，string 类型

(b): long double

(c): 无效，因为后缀 f 只能用于浮点字面量，而 1024 是整型。

(d): long double

# 2.2.1 变量定义

## 什么是对象？

对象是指 一块能存储数据并具有某种类型的内存空间

## 列表初始化

C++11加入了列表初始化，允许使用花括号进行初始化

```c++
int a{0};
int a = {0};
```

## 默认初始化

定义变量时没有指定初值，则会默认初始化，会有一个默认值。

定义于函数体内部的内置类型变量将**不被初始化**，一个未被初始化的内置类型变量的值是未定义的，如果试图访问则会引发错误。

## 初始化变量

建议初始化每一个内置类型的变量。

## 练习

### 练习2.9

解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。

- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int i = 3.14;

(a): 应该先定义再使用。

```
int input_value = 0;
std::cin >> input_value;
```

(b): 用列表初始化内置类型的变量时，如果存在丢失信息的风险，则编译器将报错。

```
double i = { 3.14 };
```

(c): 在这里 wage 是未定义的，应该在此之前将其定义。

```
double wage;
double salary = wage = 9999.99;
```

(d): 不报错，但是小数部分会被截断。

```
double i = 3.14;
```

### 练习2.10

下列变量的初值分别是什么？

```c++
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

`global_int` 是全局变量，所以初值为 0 。 `local_int` 是局部变量并且没有初始化，它的初值是未定义的。 `global_str` 和 `local_str` 是 string 类的对象，该对象定义了默认的初始化方式，即初始化为空字符串。

**这里本以为local_str是未定义，但是忘记了string不是内置类型变量，而是string类的对象**

# 2.2.2 声明与定义

## 声明和定义

声明是为了告诉程序这个名字，而定义则负责创建与名字关联的实体，定义会申请存储空间，也可能会为变量赋初始值，且只能定义一次。

**声明不分配内存空间，定义会为变量分配内存空间**

## extern

`extern`关键字在 C/C++ 中用于声明变量或函数具有**外部链接（external linkage）**，使其能在多个源文件间共享。其核心作用是通知编译器“该符号的定义在其他文件中”，由链接器在编译后统一解析地址。

使用extern可以声明一个变量而非定义它，直接使用内置类型会定义一个变量。

```c++
extern int i; // 只声明不定义i
int j; // 声明并定义j

extern double pi = 3.14 // 定义pi，此时会抵消掉extern的作用
```

**当在函数体内部初始化由extern标记的变量时会引发错误。**

**原因：**函数内部是**局部作用域**，变量默认具有**自动存储期**（函数结束时释放）。而`extern`声明的变量需具有**全局生命周期和外部链接属性**（整个程序运行期间有效，跨文件可见）。在函数内部初始化`extern`变量本质是**试图在局部作用域定义全局变量**，这既违反`extern`的声明语义（变为定义），又破坏全局变量的作用域与链接规则。C/C++通过强制**全局作用域定义+跨文件`extern`声明**的分离机制，确保全局变量的唯一性和可访问性。

## 练习

### 练习2.11

指出下面的语句是声明还是定义：

- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

答：(a): 定义。(b): 定义。(c): 声明。

# 2.2.3 标识符

## 标识符

1. 字母、数字、下划线组成
2. 必须以字母或下划线开头
3. 没有长度限制
4. 大小写敏感

**限制：**

1. 关键字和操作符替代名不可用
2. 不允许连续两个下划线
3. 不允许下划线紧连大写字母
4. 定义在函数体外的标识符不能以下划线开头

## 变量命名规范

1. 标识符要能体现实际含义
2. 变量一般用小写字母，如index
3. 自定义类名一般大写字母开头，如Sales_item
4. 多个单词之间应该有明显区分，如student_loan

## 练习

### 练习2.12

请指出下面的名字中哪些是非法的？

- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

`(a)`, `(c)`, `(d)` 非法。

# 2.2.4 名字的作用域

## 作用域

C++中大多数作用域都以花括号分隔

## 变量定义

建议在对象第一次被使用的地方附近定义它

如果函数有可能用到某全局变量，不建议再定义一个同名的局部变量

## 练习

### 练习2.13

下面程序中 j 的值是多少？

```
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

`j` 的值是 `100` ，局部变量 `i` 覆盖了全局变量 `i` 。

100

### 练习2.14

下面的程序合法吗？如果合法，它将输出什么？

```c++
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

【❌】不合法，因为两次定义了变量i，如果合法会输出10 45

其实是合法的，因为内外的i作用域不一样，且cout的是全局的i

# 2.3.1 引用

## 声明语句

一条声明语句由一个**基本数据类型**，和紧随其后的一个**声明符列表**组成，每个声明符命名了一个变量，并指定该变量为与基本数据类型有关的某种类型

简单的声明语句中，声明符就是变量名，此时变量的类型就是声明的基本数据类型，也可以有更复杂的声明符，基于基本数据类型得到更复杂的类型，并将其指定给变量

## 引用

当我们提到引用时，其实指的是左值引用

引用就是别名，引用类型 引用 另外一种类型，通过将声明符写成 &d 来定义引用类型，其中d是声明的变量名

```cpp
int ival = 1024;
int &refVal = ival; // refVal实际是ival的别名
int &refVal2; // 错误，必须被初始化
```

初始化变量时，默认是将初始值拷贝到新建的对象中，而定义引用时，是将其绑定，而不是拷贝，一旦引用和初始值对象绑定后，就无法令其重新绑定到另外一个对象，因此引用必须初始化

**注意：**引用只能绑定到对象上，不能与字面值或表达式计算结果进行绑定。

## 练习

### 练习2.15

下面的哪个定义是不合法的？为什么？

- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

答：b、d不合法，字面值，没有初始化。

### 练习2.16

考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？

```
int i = 0, &r1 = i; double d = 0, &r2 = d;
- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;
```

(a): 合法。给 d 赋值为 3.14159。
(b): 合法。会执行自动转换（int->double）。
(c): 合法。会发生小数截取。
(d): 合法。会发生小数截取。

### 练习2.17

执行下面的代码段将输出什么结果？

```
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

答：10 10

# 2.3.2 指针

## 指针与引用

1. 指针本身就是一个对象，允许直接对指针赋值和拷贝
2. 指针在生命周期内可以先后指向几个不同的对象
3. 指针无需在定义时赋初值
4. 和其他内置类型一样，在块作用域内定义的指针如果没有被初始化，也会有个不确定的值

## 指针的定义

```cpp
int *ip1, *ip2
```

ip1和ip2都是**指向int型对象的指针**

## 获取对象的地址

指针存放某个对象的地址，想要获取地址，则需要使用取地址符（&）

```
int ival = 42;
int *p = &ival;
```

p是指向变量ival的指针

**不能定义指向引用的指针**

## 指针的类型

指针的类型需要和指向的对象严格匹配：
```cpp
double dval;
double *pd = &dval; // 正确，初始值是double型对象的地址
double *pd2 = pd; // 正确，初始值是指向double对象的指针

int *pi = pd; // 错误，指针pi的类型与pd的类型不匹配
pi = &dval; // 错误，试图把double型对象的地址赋值给int型指针
```

## 指针值

指针的值（地址）应属于以下四种状态之一：

1. 指向一个对象
2. 指向紧邻对象所占空间的下一个位置（例如数组的尾后指针，虽然是有效地址值，但是解引用会触发未定义行为）
3. 空指针，没有指向任何对象
4. 无效指针，上述情况之外的其他值

## 利用指针访问对象

可以使用解引用符（*）来访问对象

```cpp
int ival = 42;
int *p = &ival;
cout << *p // 输出42
```

对指针解引用会得出所指的对象，如果给解引用的结果赋值，实际上是给所指的对象赋值

```cpp
*p = 0;
cout << *p; // 输出为0
cout << ival; // 输出为0
```

## & 与 *

& 与 * 这种既可以作为声明的一部分，也可以作为表达式的运算符，因此完全可以把它们当作不同的符号来看，例如：
```cpp
int i = 42;
int &r = i; // &紧随类型名，是声明的一部分，r是一个引用
int *p; // *紧随类型名，是声明的一部分，p是一个指针
p = &i; // &出现在表达式中，是一个取地址符
*p = i; // *出现在表达式中，是一个解引用符
int &r2 = *p; // &是声明的一部分，*是一个解引用符
```

## nullptr

C++11引入的方法，可以使用nullptr初始化指针，可以被转换成任意其他的指针类型。

```cpp
int *p1 = nullptr
int *p1 = 0; // 二者等价
```

任何非0指针的条件值都是true

**建议初始化所有指针**

## 赋值与指针

有时候想搞清楚一条赋值语句到底改变了指针的值还是改变了指针所指对象的值不太容易，但最好的办法是记住：**赋值永远改变的是等号左侧的对象**

```cpp
pi = &ival;   // pi的值被改变，现在pi指向了ival
*pi = 0; 	// ival的值被改变，指针pi并没有变
```

## void*指针

void*是一种特殊类型的指针，可以存放任意对象的地址

但是不能操作void*指针所指的对象，因为我们不知道这个对象到底是什么类型

## 练习

### 练习2.18

编写代码分别改变指针的值以及指针所指对象的值。

```cpp
int a = 0, b = 1;
int *p1 = &a, *p2 = p1;

// change the value of a pointer.
p1 = &b;
// change the value to which the pointer points
*p2 = b;
```

### 练习2.19

说明指针和引用的主要区别

1. 引用是另一个对象的别名，而指针本身就是一个对象。
2. 引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

### 练习2.20

请叙述下面这段代码的作用。

```cpp
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```

p1是指向int类型的指针，地址是i的地址

i = i * i

### 练习2.21

请解释下述定义。在这些定义中有非法的吗？如果有，为什么？

```cpp
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```

(a)非法，&i是i的地址，是int类型的，不能赋值给指向double类型的指针

(b)非法，*ip是指向int类型的指针，不能直接赋值，应该赋地址值

(c)合法，一切正常

### 练习2.22

假设 p 是一个 int 型指针，请说明下述代码的含义。

```cpp
if (p) // ...
if (*p) // ...
```

如果p指向了一个对象（不为0）

如果p指向的对象的值不为0

### 练习2.23

给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

答：不能，因为首先要确定这个指针是不是合法的，才能判断它所指向的对象是不是合法的。

### 练习2.24

在下面这段代码中为什么 p 合法而 lp 非法？

```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

void*可以存放任意类型的地址，而lp是指向long类型的指针，不能存放int类型的地址

# 2.3.3 理解复合类型的声明

## 定义多个变量

一个定义语句可以定义出不同类型的变量

```cpp
int i = 1024, *p = &i, &r = i;
```

这里的i是一个int类型的数，p是一个int型指针，r是一个int型引用

类型修饰符是声明符的一部分，而不是基本数据类型

但是很容易写出可能误导的程序，例如：
```cpp
int* p; // 合法但容易产生误导
```

但是这里的基本数据类型依旧是int而不是int*，\*仅仅修饰了p而已，对于这个语句中的其他变量均不起作用，例如：

```cpp
int* p1, p2; // p1是int型指针，p2是int
```

所以，涉及指针和引用的声明，一般把修饰符和变量标识符写在一起：
```cpp
int *p1, *p2; // p1, p2都是int型指针
```

或者着重强调复合类型，把类型名和修饰符写在一起，但每条语句只定义一个变量

```cpp
int* p1;
int* p2;
```

**其实我个人更喜欢第一种写法（哈哈）**

## 指向指针的指针

**表示指向指针的指针，\*\*\*表示指向指针的指针的指针

## 指向指针的引用

引用本身不是对象，不能定义指向引用的指针，但是指针是对象，因此可以定义指针的引用

## 如何理解变量类型

**从右向左读r的定义，离变量名最近的符号对变量的类型有最直接的影响**

```cpp
int i = 42;
int *p;
int *&r = p;
```

这里从右向左，r最近的是&，说明r是个引用，是对什么的引用呢，是对int型指针的引用。

## 练习

### 练习2.25

说明下列变量的类型和值。

- (a) int* ip, i, &r = i;
- (b) int i, *ip = 0;
- (c) int* ip, ip2;

(a)ip是int型指针，i是int，r是对i的引用

(b)i是int，ip是空指针

(c)ip是int型指针，ip2是int

# 2.4.0 const限定符

## 初始化和const

const对象一旦创建后值就不能再改变，因此必须初始化

## const对象的生效范围

默认状态下，const对象只在文件内有效，因为编译时，编译器会把用到该变量的地方都替换成对应的值，仅此而已

因此，如果包含多个文件，必须每个用了const对象的文件都能访问到初始值才行，解决方法：

对于const变量，不管是声明还是定义都添加extern关键字，这样只需要定义一次就行了

原因：`extern`关键字在 C/C++ 中用于声明变量或函数具有**外部链接（external linkage）**，使其能在多个源文件间共享。其核心作用是通知编译器“该符号的定义在其他文件中”，由链接器在编译后统一解析地址。

**如果想在多个文件之间共享const对象，在变量定义之前加extern即可**

## 练习

### 练习2.26

下面哪些语句是合法的？如果不合法，请说明为什么？

```cpp
const int buf;      // 不合法, const 对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt; ++sz;        // 不合法, const 对象不能被改变
```

不合法，没有初始化。
合法
合法
不合法，sz不可变

# 2.4.1 const的引用

## const的引用

可以把引用绑定到const对象上，表示对常量的引用

## const引用可能引用非const的对象

const引用可能引用一个非const对象，此时不能通过const引用修改对应的值

```cpp
int i = 42;
const int &r1 = i; // r1绑定对象i，但是不允许通过r1修改i的值
```

# 2.4.2 指针和const

## 指向常量的指针

想要存放常量的地址，只能使用**指向常量的指针**，且该指针不能用于改变其所指对象的值

```cpp
const double pi = 3.14; // const
double *ptr = &pi; // 错误，ptr是普通指针
const double *cptr = &pi; // 正确
*cptr = 42; // 错误，不能给*cptr赋值
```

但允许**指向常量的指针**指向一个非常量对象

```cpp
double dval = 3.14;
cptr = &dval; // 正确，但不能通过cptr改变dval的值
```

**所谓的指向常量的指针或引用，是自以为是地觉得它们指向了常量，所以自觉地不去改变所指对象的值**

## const指针

指针允许本身是常量，可以定义const指针，一旦初始化完成，对应的地址就不再改变了，把*放在const关键字之前用以说明指针是个常量，即隐含着不变的是指针本身的值而非指向的值

```cpp
int errNumb = 0;
int *const curErr = &errNumb; // curErr将一直指向errNumb
const double pi = 3.14;
const double *const pip = &pi; // pip是一个指向常量对象的常量指针
```

## 练习

### 练习2.27

下面的哪些初始化是合法的？请说明原因。

```cpp
int i = -1, &r = 0;
int *const p2 = &i2;
const int i = -1, &r = 0;
const int *const p3 = &i2;
const int *p1 = &i2;
const int &const r2;
const int i2 = i, &r = i;
```

不合法，r没有引用一个对象；合法，p2是指向int类型的常量指针
合法，可以定义对常量int的引用；合法，p3是指向常量int类型的常量指针
合法，可以定义指向常量int的指针；不合法，引用类型必须初始化
合法，可以定义对常量int的引用

### 练习2.28

说明下面的这些定义是什么意思，挑出其中不合法的。

```cpp
int i, *const cp;       // 不合法, const 指针必须初始化
int *p1, *const p2;     // 不合法, const 指针必须初始化
const int ic, &r = ic;  // 不合法, const int 必须初始化
const int *const p3;    // 不合法, const 指针必须初始化
const int *p;           // 合法. 一个指针，指向 const int
```

# 2.4.3 顶层const

## 顶层const和底层const

用顶层const表示指针本身是个常量，用底层const表示指针所指的对象是个常量

更一般的，顶层const也可以表示任意的对象是常量

## 练习

### 练习2.30

p1顶层，p2底层，p3既是顶层又是底层，r2是底层

# 2.4.4 constexpr和常量表达式

## 常量表达式

是指**值不会改变**且**在编译过程中就能得到计算结果**的表达式

## constexpr

C++11允许把变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式

一般来说，如果认定变量是一个常量表达式，那就把它声明成constexpr

## 指针和constexpr

一个constexpr指针的初始值必须是nullptr或0，或者是存储于某个固定地址的对象

如果在constexpr声明中定义了一个指针，那么constexpr仅对指针有效，与指针所指的对象无关

```cpp
const int *p = nullptr; // p是一个指向整型常量的指针
constexpr int *q = nullptr; // q是一个指向整数的常量指针
```

## 练习

### 练习2.32

下面的代码是否合法？如果非法，请设法将其修改正确。

```
int null = 0, *p = null;
```

非法。把int变量直接赋给指针是错误的操作,即使int变量的值恰好等于0也不行.

```
int null = 0, *p = 0;
```

# 2.5.1 类型别名

## typedef

```cpp
typedef double wages; // wages是double的同义词
typedef wages base, *p; //base是double的同义词，p是double*的同义词
```

## using

```cpp
using SI = Sales_item;
```

# 2.5.2 auto类型说明符

## 复合类型、常量和auto

编译器推断出的auto有时候和初始值的类型不完全一样，编译器会适当改变结果使其更符合初始化规则

可以将引用类型设置为auto

```cpp
auto &h = 42; // 错误，不能为非常量引用绑定字面值
const auto &j = 42; // 正确，可以为常量引用绑定字面值
```

## 练习

### 练习2.33

利用本节定义的变量，判断下列语句的运行结果。

```
a=42; // a 是 int
b=42; // b 是一个 int,(ci的顶层const在拷贝时被忽略掉了)
c=42; // c 也是一个int
d=42; // d 是一个 int *,所以语句非法
e=42; // e 是一个 const int *, 所以语句非法
g=42; // g 是一个 const int 的引用，引用都是底层const，所以不能被赋值
```

### 练习2.35

j是int类型，k是const int的引用，p是指向const int的指针，j2是const int，k2是const int的引用

# 2.5.3 decltype

## 如何使用？

希望从表达式的类型推断出要定义的类型，但又不想用表达式的值初始化变量

```cpp
decltype(f()) sum = x; // sum的类型就是函数f的返回类型
```

sum的类型就是函数f的**返回类型**，这里编译器并不实际调用函数f，而是使用f的返回类型当作sum的类型

```cpp
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x的类型是const int
decltype(cj) y = x; // y的类型是一个const int&，y绑定到变量x
```

如果decltype使用的表达式是一个变量，则返回该变量的类型

## decltype和引用

如果decltype使用的是一个加了一层或多层括号的变量，则编译器会将其当作是表达式，变量是一种可以作为赋值语句左值的特殊表达式，所以这样decltype会得到引用类型

**decltype((variable))的结果永远是引用，只有decltype(variable)，variable本身就是一个引用时才是引用**

## 练习

### 练习2.36

关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

c 是 int 类型，值为 4。d 是 int & 类型，绑定到 a，a 的值为 4 。

### 练习2.37

赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。

```
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

c 是 int 类型，值为 3。d 是 int& 类型，绑定到 a，为3。

# 2.6.0 自定义数据结构

## struct

使用struct定义类，以分号结尾

# 2.6.3 编写自己的头文件

## 头文件

有时候头文件会被多次包含，有必要在书写头文件时做适当处理，使其遇到多次包含的情况也能安全和正常地工作

## 预处理器

预处理器是在编译之前执行的一段程序，可以部分改变我们写的程序，例如#include，就是预处理功能

头文件保护符也是常见的与处理功能，预处理变量符有两种状态：已定义和未定义。

#define 把一个名字设定为预处理变量
#ifdef 仅当变量已定义时为真
#ifndef 当且仅当变量未定义时为真
#endif 当#ifndef的结果为真时，执行后续操作直到#endif

**建议：头文件保护符其实很简单，只要习惯性加上就行了，没必要在乎程序是否需要**

