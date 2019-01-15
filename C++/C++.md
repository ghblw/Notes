###从C到C++

####f()和f(void)的区别

C++:无区别，都是没有参数

C:有区别，参数不定，无参数

**在结构体中定义并实现函数**(类和结构体的区别)

异常类：try catch 

bug和异常的区别

```c++
#include <iomanip>
using namespace std;
cout << setprocisior(2) << fixed << 结果
```

编码规范

###类和对象

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

####class和struct的默认访问权限

struct:公有的

class:私有的

####const的区别

C语言中有没有真正的常量？

enum{}枚举类型是真正的常量

const:read only只读变量

- C++:真正的常量
- C:只读的变量

	例：指针修改	

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

####宏和const的区别

const有作用域和类型检查

####引用

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

```c++
#include<iostream>
using namespace std;

int &f() {
    int a = 100;
    return a;
}
int main() {
    int &c = f();
    cout << c << endl;
}
```



####传参、默认值

传参，从左向右

默认值，从右向左

例如：add (int a, int b = 0, int c)错误

参数可能有默认值，没有默认值的需要传参，否则报参数不匹配

函数参数如果带默认值，在声明时有默认值，实现时不能有默认值？



####函数参数的占位

只有类型，没有形参（为了兼容C）



####（重点）函数重载

C语言中不允许函数重载

如何判断函数是否被重载

#####大前提

- 同一作用域
- 函数名相同
- 参数列表不同
  - 参数类型

  - 参数个数

  - 参数顺序（类型不同）

    

重载只和函数参数列表有关，与返回值无关

函数重载的本质，不同的函数，地址不一样

#####常犯错误

函数重载＋默认参数（二义性）

`error: call of overloaded ‘add()’ is ambiguous`

函数重载＋函数指针，首先参数类型和参数个数要相同(因为用了函数指针)，其次**返回值类型也要相同**，C++是强类型语言，函数指针是一个指针类型的变量

```c++
#include<iostream>
#include<cstdio>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace yxw {
    int add(int x, int y = 3) {
        return x + y;
    }
    int add() {
        return 100;
    }
    string add(string &s1, string &s2) {
        return s1 + s2;
    }
}

using namespace yxw;
int (*p1)(int, int);
int (*p2)();
int main() {
    string s1 = "yxw", s2 = "haizei";
    p1 = add;
    p2 = add;
    int c = (*p1)(1, 2);
    int d = (*p2)();
    cout << c << " " << d << endl;
    cout << add() << endl;
    cout << add(0) << endl;
    cout << add(s1, s2) << endl;
    printf("%p %p\n", p1, p2);
}
/*
输出：
3 100
100
3
yxwhaizei
0x400e16 0x400e2a
*/
```



#####函数重载编译器调用准则（2条）

- 所有函数名都能作为被选对象

- 编译器尝试寻找匹配的函数，精确匹配参数（可能出现二义性）

  `f(int x = 1, int x = 2)`

  `f()`

  真正用到的时候可以换函数名qwq

思考：实现一个数组类



####new和delete???

动态分配内存空间

calloc

- 申请空间
- 赋值

new

- 对单个变量初始化
- 按照数据类型分配空间

malloc

- 根据子节大小分配空间

初始化和赋值的区别



通过对象访问和修改类的属性

变量不初始化：

#####堆区栈区静态全局

堆栈：随机

静态、全局：０

#### （重点）构造函数

#####特点

- 没有返回值
- 函数名与类名相同
- 定义对象时自动调用
- 可以有形参，可以没有形参，可以带有默认参数
- 可以重载

**解决对象不初始化产生随机值的问题**

可以重载

#####易错

无参构造函数只能　Test t;

Test t();被认为是函数声明

```c++
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Test {
    private:
    int a;
    public:
    Test() {
        a = 10;
        cout << "Test() " << a << endl;
    }
    Test(int value) {
        a = value;
        cout << "Test(int) "<< a << endl;
    }
    int getA() {
        return a;
    }
};

//Test t1;//全局区，不初始化默认值为０
int main() {
    Test t(1);//有参
    Test t2 = 100;//兼容int i = 1;调用有参构造函数
    Test t3;//调用无参构造函数，不能写成Test t3();会被认为是函数声明
}
/*输出：
Test(int) 1
Test(int) 100
Test() 10
*/

```



类中无构造函数时，编译器提供一个构造函数

类中有构造函数时，就不会提供

当一个类是空类（或无构造函数）时，编译器会默认提供一个无参的构造函 数，函数体是空



#####需要手动调用构造函数的情况

- new	: Test *p = new Test(1);

- 对象数组：

  `Test t[3] = {Test(), Test(2), Test(3)}`;



####拷贝构造函数???

如果不定义拷贝构造函数，系统自动生成，简单的值复制

#####辨析：何时调用拷贝构造函数

Test t2 = t1;//初始化，调用了拷贝构造，用一个已经初始化的对象初始化一个新的对象



Test t2;

t2 = t1;//赋值？重载了等号，试过后发现都有double free

#####深拷贝和浅拷贝???

浅拷贝：拷贝后物理状态相同，存的位置相同

深拷贝：逻辑状态相同，存的位置不同

拷贝构造函数：不涉及内存操作可以用系统自带的

手动实现拷贝构造函数必须深拷贝

否则free()可能出问题

`*** Error in `./a.out': double free or corruption (fasttop): 0x0000000001a36070 ***`



```c++
//手动实现拷贝构造函数，深拷贝
/*
class_name (const class_name&) {
	实现
}
*/
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Test {
    private:
    int a;
    int *p;
    public:
    Test() {
        p = new int(1);
    }
    Test(int value) {
        a = value;
        p = new int(1);
        cout << "Test(int)" << a << endl;
    }
    Test(const Test &obj) {
        a = obj.a;
        p = new int;
        *p = *obj.p;
    }
    int getA() {
        return a;
    }
    int *getP() {
        return p;
    }
    int get() {
        return *p;
    }
    void free() {
        delete p;
    }
};

int main() {
    Test *p = new Test(1);
    Test t3(1);
    Test t5 = t3;
    cout << "t3:"<< t3.getA() << " " << t3.getP() << endl;
    cout << "t5:"<< t5.getA() << " " << t5.getP() << endl;
    t3.free();
    t5.free();
}

```

####初始化列表

类中属性可以用const修饰，不能用构造函数或普通函数的赋值方法

**报错**:`error: uninitialized const member in ‘const int’ `

用初始化列表，紧跟在**构造函数**后

普通属性也可以用初始化列表

#####用法（根据初始化对象的不同分类）

######1.const变量和普通变量

```c++
//类内部实现
class Name {
    private:
    const int i;
    public:
    Name(int v):i(v) {
        
    }
} 
//类外部实现
class Name {
    private:
    const int i;
    public:
    Name(int v);
}
Name::Name(int v):i(v) {
    
}
```

######2.多个参数

```c++
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Test {
    private:
    const int i;
    int a;
    public:
    Test(int v1, int v2):i(v1), a(v2) {
        cout << "i = " << i << endl;
        cout << "a = " << a << endl;
    }
    int getI() {
        return i;
    }
};

int main() {
    Test t(10, 100);
    cout << "t.i = " << t.getI() << endl;
}

```

######3.对象是类??????

- 如果对象是空类，不用初始化，编译也可以通过,因为编译器默认提供一个无参的构造函数

```c++
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Value {

};//空类，默认提供无参构造函数
class Test {
    private:
    const int i;
    int a;
    Value v1;
    public:
    Test(int v1, int v2):i(v1), a(v2) {
        cout << "i = " << i << endl;
        cout << "a = " << a << endl;
    }
    int getI() {
        return i;
    }
};

int main() {
    Test t(10, 100);
    cout << "t.i = " << t.getI() << endl;
}

```

- 对象不是空类，

**要点**:先执行初始化列表，当执行到函数体时，已经存在对象，此时再给一些状态，类似于赋值

初始化列表相当于边生成对象边赋初始值

```c++
//错误代码１：编译不通过的原因是什么
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Value {
    private:
    int i;
    public:
    Value(int v) : i(v) {
        cout << "Value :: i = " << i << endl;
    }
};
class Test {
    private:
    const int i;
    int a;
    Value v1;
    public:
    Test(int v1, int v2):i(v1), a(v2) {
        cout << "i = " << i << endl;
        cout << "a = " << a << endl;
    }
    int getI() {
        return i;
    }
};

int main() {
    Test t(10, 100);
    cout << "t.i = " << t.getI() << endl;
}

```

```c++
//代码２：正解
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Value {
    private:
    int i;
    public:
    Value(int v) : i(v) {
        cout << "Value :: i = " << i << endl;
    }
};
class Test {
    private:
    const int i;
    int a;
    Value v1;
    public:
    Test(int v1, int v2):i(v1), a(v2), v1(1) {//改动的位置
        cout << "i = " << i << endl;
        cout << "a = " << a << endl;
    }
    int getI() {
        return i;
    }
};

int main() {
    Test t(10, 100);
    cout << "t.i = " << t.getI() << endl;
}

```



必须使用初始化列表：

- const成员属性
- 类属性
  - 空类，默认提供无参构造函数，不需要	
  - 类里有带参构造时

  当构造函数执行到函数体时，对象已经有了，初始化列表相当于边生成对象时边初始化

初始化列表的初始化顺序与成员属性的声明顺序相同

初始化顺序与实际初始化列表中的位置无关

初始化列表优先于函数体执行

```

```



#### 析构函数

对象销毁前自动调用

无参数，无返回值，**不可重载**



####对象的构造顺序和析构顺序???

堆上

- 程序执行流
- new，调构造函数
- delete，调析构函数

C++标准中全局对象构造顺序不定，尽量不用全局对象



对象构造顺序：

先父母

再朋友（private: value v1;value v2）

再自己

####类属性与方法

静态成员变量属于整个类

生命周期和程序相同

可以通过类名直接访问公有的静态成员变量，静态成员变量有访问级别

所有对象都共享



静态成员方法

不依赖对象

静态成员函数**不能**直接访问成员变量，没有this指针（静态对静态）

```c++
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//静态成员变量和静态成员方法
class Test {
    private:
        static int cnt;
        int m;
    public:
    static int getCnt() {
        return m;
    }
    Test() {
        m = 1;
        cnt += 1;
    }
    ~Test() {
        cnt -= 1;
    }
};
int Test::cnt = 0;
int main() {
    cout << Test::getCnt() << endl;
    Test t1;
    cout << Test::getCnt() << endl;
    Test *p = new Test();
    cout << Test::getCnt() << endl;
    delete p;
    cout << Test::getCnt() << endl;
    return 0;
}

```



**静态成员方法和普通成员方法的区别**



对象在程序中属性不共享，方法共享

每个成员方法有一个隐藏的this指针，是某个对象的地址

静态成员函数没有this指针

找不到普通成员变量（需要传参）



this	当前对象的某个指针

####const方法

const可以修饰一个对象

- 只读对象（属性只读）

- 在编译器只读对象成员属性不能被改变

- const对象只能调用const方法

  `Type 函数名()const {}`

类中退化成只读变量？

const方法中，不能修改成员变量，多线程



**总结**

const方法定义

类外

类内

const方法特性

const方法只能调用const方法

#### 结构体与类

####返回值优化（RVO)

手动调用构造函数产生临时对象（匿名对象）



优化在哪？

默认的第一个参数是 *this

把没拷贝之前的传过去

直接用临时对象传参



减少临时对象

尽量传引用