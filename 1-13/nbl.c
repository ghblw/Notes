/*************************************************************************
	> File Name: nbl.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月13日 星期日 14时16分06秒
 ************************************************************************/

#include<stdio.h>

int getNum(char *str, int *ret) {
    int i = 0, num = 0;
    while (str[i] <= '9' && str[i] >= '0') {
        num = num * 10 + str[i++] - '0';
    }
    *ret = num;
    return i;
}

int getTerm(char *str, int *ret) {
    int i = 0, temp;
    if (str[i] == 0) return 0;
    i += getNum(str + i, ret);
    if (str[i] == 0) return i;
    while (str[i]) {
        switch (str[i]) {
            case '*': {
                i += getTerm(str + i + 1, &temp) + 1;
                (*ret) *= temp;
            } break;
            case '/': {
                i += getNum(str + i + 1, &temp) + 1;
                (*ret) /= temp;
            } break;
            default: return i;
        }
    }
    return i;
}

int calc(char *str) {
    int i = 0, a, b;
    char op;
    if (str[i] == 0) return 0;
    i += getTerm(str + i, &a);
    if (str[i] == 0) return a;
    while (str[i]) {
        op = str[i];
        i += getTerm(str + i + 1, &b) + 1;
        switch (op) {
            case '+': a += b; break;
            case '-': a -= b; break;
        }
    }
    return a;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%d\n", calc(str));
}
