/*************************************************************************
	> File Name: fitst_pos.cpp
	> Author:yuxiaowei 
	> Mail:1147407739@qq.com 
	> Created Time: 2019年01月13日 星期日 18时09分27秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int n, val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        val = (val < 0 || val > n ? 0 : val);
        arr.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        while (arr[i] != 0 && arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
}
