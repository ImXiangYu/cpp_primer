# 5.3.2 switch语句

## break

建议每个case后都加上break，不管需不需要

## default

即使不准备在default标签下做任何工作，定义一个default标签也是有用的，其目的在于告诉程序的读者，我们已经考虑到了默认的情况，只是目前什么也没做

# 5.5.3 goto语句

## goto

不要在程序里使用goto，因为它让程序变得既难理解又难修改

# 5.6 try语句块和异常处理

## throw

异常检测部分用throw来表示它遇到了无法处理的问题，我们说 throw 引发(raise) 了异常

抛出异常将终止当前的函数，并把控制权转移给能够处理该异常的代码

## try

```cpp
try {
	program-statements
} catch (exception-declaration) {
	handler-statements
} catch (exception-declaration) {
	handler-statements
}
```

try语句块内声明的变量在块外部无法访问，特别是在catch子句中也无法访问

## terminate

在顺着异常一路寻找匹配catch子句的过程中，如果一直没能找到与之匹配的catch子句，而程序转到名为terminate的标准库函数，则说明没有与之对应的catch

terminate的行为与系统有关，执行了terminate会导致程序非正常退出，且如果一段程序没有try语句块且发生了异常，系统也会调用terminate函数并终止当前程序的执行

# 5.6.3 标准异常

## 异常类

1. exception 头文件定义了最通用的异常类 exception，它只报告异常的发生，不提供任何额外信息
2. stdexcept 头文件定义了几种通用的异常类
3. new 头文件定义了bad_alloc异常类型
4. type_info 头文件定义了bad_cast异常类型

