#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
int compare(const T& a, const T& b) {
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

template <typename T>
T foo(T* a) {
    T tmp = *a;
    return tmp;
}

// 非类型参数(nontype parameter)
template <unsigned N, unsigned M>
int compare_nontype(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

// 可以使用inline或constexpr
template <typename T>
inline T foo_inline(T a) {
    return a;
}

// 直到实例化时才能发现问题
template <typename T>
T foo_string(T a) {
    return "hello"; // 如果传int返回string会怎么样？
    // error: invalid conversion from 'const char*' to 'int'
    // 已老实
}

int main() {
    // cout << compare(1, 2) << endl;
    cout << compare_nontype("hello", "hi") << endl;
    return 0;
}