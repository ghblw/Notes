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