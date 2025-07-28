# 7.0 类

类的基本思想是**数据抽象**和**封装**，数据抽象是一种依赖于**接口**和**实现**的分离编程技术

类的接口包括用户所能执行的操作，类的实现则包括类的数据成员、负责接口实现的函数体，以及定义类所需的各种私有函数

封装实现了类的接口和实现的分离，封装后的类隐藏了实现细节，用户只能使用接口而无法访问实现部分

## 类内部的函数

类内部的函数是隐式的inline函数

## this

this总是指向“这个”对象，因此this是个常量指针，我们不允许改变this中保存的地址

## const成员函数

C++允许把**const关键字放在成员函数的参数列表之后**，紧跟在参数列表后面的const表示this是一个指向常量的指针，使用const的成员函数被称作常量成员函数

```cpp
std::string fn() const { return this->no; }
```

因为this是指向常量的指针，所以常量成员函数不能改变调用它的对象的内容

## 定义一个返回this对象的函数

```cpp
Sale_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this; // 返回调用该函数的对象
}
```

返回类型是引用，return解引用的this指针，获得执行该函数的对象，并将其返回

# 7.1.4 构造函数

每个类都定义了它的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫做**构造函数（constructor）**，构造函数的任务是初始化类的对象。**只要类的对象被创建，就会执行构造函数**

构造函数的名字与类名相同，且没有返回类型，构造函数也有一个参数列表和一个函数体

类可以包含多个构造函数，和其他的重载函数差不读，不同的构造函数之间必须在参数数量或参数类型上有所区别

不同于其他成员函数，构造函数不能被声明成const的

## 默认构造函数

如果我们的类没有显式定义构造函数，则编译器会隐式地定义一个默认构造函数，编译器创建的构造函数又被称为合成的默认构造函数

初始化遵循以下规则：

1. 如果存在类内的初始化，用它来初始化成员
2. 否则，默认初始化该成员

## 不能依赖默认构造函数

1. 编译器只有发现类不包含任何构造函数的情况下才会替我们生成默认构造函数
2. 默认构造函数可能执行错误的操作
3. 如果类中包含一个其他类类型的成员且这个成员的类型没有默认构造函数，则编译器无法初始化该成员

## =default

C++11引入的=default

```cpp
Sales_data() = default;
```

要求编译器生成构造函数

## 列表初始化

```cpp
Sales_data(const std::string &s, unsigned n, double p):
	bookNo(s), units_sold(n), revenue(p*n) { }
```

# 7.1.5 拷贝、赋值和析构

拷贝、赋值和析构，如果我们不主动定义，则编译器将替我们合成它们

## 某些类不能依赖合成的版本

尽管编译器能替我们合成，但对于某些类来说，合成的版本无法正常工作

# 7.2 访问控制与封装

## class、struct

struct和class的**唯一一点区别**是，它们的默认访问权限不一样。
使用struct，在定义一个访问说明符之前的成员是public的，相反，如果我们使用class，则成员是private的

# 7.2.1 友元

类可以允许其他类或函数访问它的非公有成员，方法是令其他类或函数成为它的友元

```cpp
class Sales_data {
	friend std::istream &read(std::istream&, Sales_data&);
}
```

这样read这个函数就可以访问Sales_data内的非公有成员了

**一般来说，最好在类定义开始或结束前的位置集中声明友元**

# 7.3 类的其他特性

## 可变数据成员

我们希望能修改类的某个数据成员，即使是在一个const成员函数内，可以通过在变量的声明中加入mutable关键字做到这一点

一个**可变数据成员**永远不会是const，即使它是const对象的成员，因此，一个const成员函数可以改变一个可变成员的值

```cpp
mutable size_t access_ctr;
```

## 类数据成员的初始值

C++11可以把默认值声明成一个类内初始值

```cpp
std::vector<Screen> screens{screen(24, 80, ' ')};
```

## 返回*this的成员函数

如果返回*this，则说明把this对象作为左值返回，此时返回值是调用set的对象的引用，返回的是对象本身而非副本

```cpp
myScreen.move(4, 0).set('#');
// 等价于
myScreen.move(4, 0);
myScreen.set('#');

// 如果move返回Screen而非Screen&
Screen tmp = myScreen.move(4, 0);
tmp.set('#'); // 则是对返回值进行拷贝，不会改变myScreen的contents
```

# 7.5.2 委托构造函数

C++11扩展了构造函数初始值的功能，可以定义**委托构造函数（delegating constructor）**

一个委托构造函数也有一个成员初始值的列表和一个函数体，和委托构造函数一样，类名后紧跟圆括号括起来的参数列表，参数列表必须与类中另外一个构造函数匹配

```cpp
class Sales_data {
public:
    //非委托构造函数使用对应的实参初始化成员
    Sales_data(std::string s, unsigned cnt, double price):
    	bookNo(s), units_sold(cnt), revenue(cnt*price) { }
    //其余构造函数全都委托给另一个构造函数
    Sales_data (): Sales_data("", 0, 0) { }
    Sales_data(std::string s): Sales_data(s, 0, 0) { }
    Sales_data(std::istream &is): Sales_data()
    						{ read(is, *this); }
    //其他成员与之前的版本一致
};
```

除了一个构造函数外，其余的构造函数都委托了它们的工作

# 7.5.4 隐式的类类型转换

## 转换构造函数

如果构造函数只接受一个实参，则它实际上定义了转换为此类类型的隐式转换机制，有时我们把这种构造函数称作**转换构造函数（converting constructor）**

```cpp
string null_book = "9-999";
item.combine(null_book);
```

构造了一个临时的Sales_data对象，units_sold和revenue等于0，bookNo等于null_book

这里我们用string实参调用了Sales_data的combine对象，该调用是合法的，编译器用给定的string自动创建了一个Sales_data对象

## 只允许一步类类型转换

不能一次隐式地使用两种转换规则，例如：
```cpp
item.combine("9-999"); // 错误，两次隐式转换
item.combine(string("9-999")); // 正确，显式转string，隐式转Sales_data
item.combine(Sales_data("9-999")); // 正确，隐式转string，显式转Sales_data
```

## 抑制隐式转换

可以通过将构造函数声明成 explicit 阻止其隐式转换

关键字explicit只对一个实参的构造函数有效，需要多个实参的构造函数无需指定

# 7.5.5 聚合类

聚合类（aggregate class）使得用户可以直接访问其成员，并且具有特殊的初始化语法形式，当一个类满足如下条件，我们说它是聚合的：

1. 所有成员都是public的
2. 没有定义任何构造函数
3. 没有类内初始值
4. 没有基类，也没有virtual函数

聚合类的例子：

```cpp
struct Data{
	int ival;
	string s;
};

Data val1 = {0, "Anna"};
```

# 7.5.6 字面值常量类

数据成员都是字面值类型的聚合类是字面值常量类，如果不是一个聚合类，符合以下条件也是一个字面值常量类：

1. 数据成员都必须是字面值类型
2. 类必须至少含有一个constexpr构造函数
3. 如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式。或成员属于某种类类型，则初始值必须使用自己的constexpr构造函数
4. 类必须使用析构函数的默认定义，该成员负责销毁类的对象

## constexpr构造函数

尽管构造函数不能是const的，但是字面值常量类的构造函数可以是constexpr的

# 7.6 类的静态成员

我们通过在成员的声明之前加上static，使其与类关联在一起，和其他成员一样，静态成员可以是public或private的

静态数据成员的类型可以是常量、引用、指针、类类型等

```cpp
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};
```

类的静态成员存在于任何对象之外，对象中不包含任何和静态数据成员有关的数据，因此，这个interestRate会被所有Account对象共享

## 使用类的静态成员

使用作用域运算符直接访问：
```cpp
double r;
r = Account::rate(); // 使用作用域运算符
```

使用类的对象、引用、指针来访问静态成员

```cpp
Account ac1;
Account *ac2 = &ac1;
// 调用静态成员函数rate的等价形式
r = ac1.rate(); // 通过Account的对象或引用
r = ac2->rate(); // 通过指向Account对象的指针
```

**和类的所有成员一样，当我们指向类外部的静态成员时，必须指明成员所属的类名。且static关键字只出现在类内部的声明语句中，在类的外部定义静态成员时，不能重复static关键字**

## 静态成员的类内初始化

因为静态数据成员不属于类的任何一个对象，所以它们并不是在创建类的对象时被定义的。这意味着它们不是由类的构造函数初始化的

通常情况下，类的静态成员不应该在类的内部初始化，然而我们可以为静态成员提供const整数类型的类内初始值，不过要求静态成员必须是字面值常量类的constexpr，初始值必须是常量表达式

