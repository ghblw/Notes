/*************************************************************************
	> File Name: 8.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月13日 星期日 18时28分22秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int atoi(char *str) {
    int i = 0, ret = 0, flag = 1;
    while (str[i] == ' ') ++i;
    if (str[i] == '-') flag = -1, i++;
    int pre_ret;
    while (str[i] && str[i] <= '9' && str[i] >= '0') {
        pre ret = ret;
        ret = ret * 10 + (str[i] - '0');
        if (ret / 10 != pre_ret) {
            return flag == -1 > INT_MIN : INT_MAX;
        }//溢出
        i++;
    }
    return ret * flag;
}

int main() {
    char str[100];
    while (scanf("%s", str) != EOF) {
        printf("%d\n", atoi(str));
    }
}
