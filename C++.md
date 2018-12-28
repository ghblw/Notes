####从C到C++

**f()和f(void)的区别**

C++:无区别，都是没有参数

C:有区别，参数不定，无参数

**在结构体中定义并实现函数**(类和结构体的区别)

异常类：try catch 

bug和异常的区别

```
#include <iomanip>
using namespace std;
cout << setprocisior(2) << fixed << 结果
```

编码规范

####类和对象

类之间的组合和继承

```c++
#include<iostream>
#include<stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;
namespace my_lib {
    class People {
        private:
            int age;//属性
            string name;
        public:
        	People(string s) {
            name = s;
        	}
        	int getAge() {
            	return age;//成员方法
        	}
        	string getName() {
            	return name;
        	}
    };
}
using my_lib::People;
int main() {
    People p("yxw1");//调用构造函数
    People *p1 = new People("yxw2");
    cout << p.getName() << endl;
    cout << p1->getName() <<endl;
    delete p1;
    return 0;
}

```

**class和struct的默认访问权限**

struct:公有的

class:私有的



**const的区别**

C语言中有没有真正的常量？

enum{}枚举类型是真正的常量

const:read only只读变量

- C++:真正的常量
- C:只读的变量

举例：指针修改	

```c
/*************************************************************************
	> File Name: 1.const.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年12月28日 星期五 17时55分00秒
 ************************************************************************/

#include<stdio.h>

int main() {
    const int a = 5;
    int *p = (int *)&a;
    *p = 6;　
    printf("%d, %d\n", a, *p);
}
//gcc 输出6,6
//g++ 输出5,6
```

C++:符号表

对一个const类型的变量做引用时，会分配一个空间？？？

a	5

p	6

**宏和const的区别**

const有作用域和类型检查

**引用**

C中三目运算符不能当左值

C++：判断条件都是变量，三目运算符如果返回一个变量的引用,可当左值用

引用：变量新的别名

- 声明一个变量的引用必须初始化

  int a = 5;

  int &b = a;

**特殊**：引用作为参数时可以不用初始化，初始化发生在传参过程中

```c++
void swap1(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return ;
}

void swap2(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return ;
}
int main() {
    int a = 1, b = 5;
    swap1(&a, &b);
    cout << a << " " << b <<endl;
    swap2(a, b);
    cout << a << " " << b <<endl;
}

```



引用大多数时候可以代替指针

**特殊**：传出参数

局部变量不能当引用返回

**传参、默认值**

传参，从左向右

默认值，从右向左

例如：add (int a, int b = 0, int c)错误

参数可能有默认值，没有默认值的需要传参，否则报参数不匹配

函数参数如果带默认值，在声明时有默认值，实现时不能有默认值

**函数参数的占位**

只有类型，没有形参（为了兼容C）

**函数重载**

如何判断函数是否被重载

大前提：

- 同一作用域
- 函数名相同
- 参数列表不同
  - 参数类型
  - 参数个数
  - 参数顺序

函数重载的本质，不同的函数，地址不一样

常犯错误：

函数重载＋默认参数（二义性）

函数重载＋函数指针，首先参数类型和参数个数要相同，其次返回值类型也要相同，强类型

**编译器调用准则（2条）**

**函数重载**

思考：实现一个数组类