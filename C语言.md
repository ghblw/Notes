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

