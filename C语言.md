##C语言

###一、

数组：记录式

函数、深度神经网络：计算式

####练习1：

输出数字n的位数

`scanf`

返回值：

0合法

EOF -1

`sprintf`

sprintf(str,"%d",n)

末尾自动添加\0 

`fprintf`

FILE *p=fopen("/dev/null","w")

fprintf(p,"%d",n)

```C
#include <stdio.h>

int main() {
    int n;
    char str[100];
    FILE *fout = fopen("/dev/null", "w");
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", fprintf(fout, "%d", n));
    }
    return 0;
}
```



#### 练习2：

格式化字符串

```c
#include <stdio.h>

int main() {
    char str[100];
    scanf("%[^\n]s", str);//正则表达式
    int n = printf("%s", str);
    printf(" has %d chars\n", n);
    return 0;
}
```



###二、数学运算

实现sqrt

1.二分

2.牛顿迭代法

### 三、程序流程控制方法

条件表达式：条件运算符，返回值为0或1

普通表达式：加减乘除、赋值，返回值为任意值

switch：入口

####拓展

执行指令：取指令、指令解析、取数据、运算、写回结果

流水线

分支预测		likely	unlikely

### 四、函数

函数、数组

定义、声明

####递归

1、语义		n的阶乘

2、边界		1		

3、过程		fac(n-1)*n

4、返回		

#### 函数指针 

函数有地址

程序执行流程是特殊的数据，二进制形式加载到内存中，有地址

#### 变参函数

`scanf` `printf`

`va__list arg;`

`va_start(arg,变参列表前一个参数的名字)`

存疑：不是函数

`va_arg(arg,相应参数类型)`

#### 声明和定义

function.c

```c
/*************************************************************************
	> File Name: function.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年09月20日 星期四 19时48分03秒
 ************************************************************************/

#include<stdio.h>

//预处理、编译、链接
//不能生成可执行文件，可以生成对象文件 gcc -c function.c->function.o
//链接几个对象文件
//如果有多个对象文件定义了函数，不能通过编译
int is_prime(int x);//声明,如果不定义报错未声明
int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("!\n");
    }
}
```



is_prime.c

```c++
/*************************************************************************
	> File Name: is_prime.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年09月20日 星期四 19时52分31秒
 ************************************************************************/

#include<stdio.h>
int is_prime(int x) {
    printf("is_prime\n");
    return 1;
}
```

```shell
gcc -c function.c
gcc -c is_prime.c
gcc -o function.o is_prime.o
```

### 五、数组与预处理命令

数组可以看成展开的函数

####数组与地址

用整形数组存储字符串

```

```

小端系统

IP地址，转换为4个字节整形

####宏定义

调试宏： `g++ -E a.cpp` 显示编译源码

加入DEBUG宏: `g++ -DDEBUG a.cpp`

###六、复杂结构与指针

####结构体

匿名结构体

对齐方式：找到最大数据类型，作为基本内存分配单元，不够分新建一个单元

```c
#include <stdio.h>

struct test {
    short a;
    char b;
    int c;
    double d;
};
int main() {
    //printf("sizeof(person) : %d\n", sizeof(struct person));
    struct test a;
    printf("%p %p %p %p\n", &a.a, &a.b, &a.c, &a.d);
}
```

输出：0x7ffcefece8f0 0x7ffcefece8f2 0x7ffcefece8f4 0x7ffcefece8f8

int类型只能放在偏移量为int整数倍的位置

#### 共用体

数组：所有元素长度相同

练习：IP转整数	

```C
/*************************************************************************
	> File Name: union.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2018年10月04日 星期四 09时59分11秒
 	************************************************************************/

#include<stdio.h>
//IP->int
union IP {
    struct {
        unsigned char arr[4];
    } ip;//匿名结构体变量(只用一次)
    unsigned int num;
};

int main () {
    int a,b,c,d;
    IP ip;
    while(scanf("%d.%d.%d.%d",&a,&b,&c,&d) != EOF) {
        ip.ip.arr[0] = a;//相当于给num的第一个字节赋值
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
```

浮点型表示方式

#### 指针

指针变量

变量地址：存储空间第一个字节的地址

指针类型不影响存储空间，影响解析运算符下操作如`p++`

所有类型指针都占8字节（64位）

传入参数

传出参数：传入地址

####函数指针：

定义函数指针变量：`int (func*) (int a,int b)`

定义函数指针类型：`typedef`检查参数按照函数指针

####main()函数参数

argv[0]： 调用方式./a.out

argv[1]：第一个参数

`char **env`环境变量

#### 项目

测试框架

EXPECT：比较，判断函数返回值，测试点

TEST：测试用例，TEST参数：测试用例的名字

#### Makefile

clean：虚拟目标

.PHONY:clean