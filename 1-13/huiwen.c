/*************************************************************************
	> File Name: huiwen.c
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月13日 星期日 15时16分45秒
 ************************************************************************/

#include<stdio.h>

//输出字符串中所有的回文子串
void expand(char *str, int i, int j, int n) {
    while (i >= 0 && j < n && str[i] == str[j]) {
        char c = str[j + 1];
        str[j + 1] = 0;
        printf("%s\n", str + i);
        str[j + 1] = c;
        i--, j++;
    }
    return ;
}

int main() {

}
