#第二章
###PE 05 辗转相除
题意：求1～20的最小公倍数
```
#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}
```
###PE 07 素数筛+线性筛
题意：求第10001个素数
WA点：
（1）注意如果素数筛打表，要最后遍历一遍，之前是i*i<=MAXN
（2）素数筛的j+=i老写错
####素数筛
```
#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    return ;
} 

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
```
拓展：
最小质因子->质因数分解
最大质因子
####最小质因子
```
#include <stdio.h>

#include <inttypes.h>

 

#define MAX_RANGE 10000 // 求出10000以内的素数

 

int32_t prime[MAX_RANGE + 5] = {0}; // 初始值为0，代表没有被标记成合数

 

int32_t main() {

    for (int32_t i = 2; i * i <= MAX_RANGE; i++) {

        if (!prime[i]) // i 没有被标记过，说明 i 是素数

            for (int32_t j = i; j <= MAX_RANGE; j += i) // 枚举 i 的倍数

                if (!prime[j]) // 如果 j 没有被标记过，说明 i 是其最小素因子

                    prime[j] = i; // 将 i 的倍数标记为1，说明其是合数

    }

    int32_t n;

    while (scanf("%d", &n) != EOF) {

        //输出 n 的最小素因子

        printf("%d\n", prime[n]);

    }

    return 0;

}	
```
####最大质因子
```
#include <stdio.h>

#include <inttypes.h>

 

#define MAX_RANGE 10000 // 求出10000以内的素数

 

int32_t prime[MAX_RANGE + 5] = {0}; // 初始值为0，代表没有被标记成合数

 

int32_t main() {

    for (int32_t i = 2; i * i <= MAX_RANGE; i++) {

        if (!prime[i]) // i 没有被标记过，说明 i 是素数

            for (int32_t j = i; j <= MAX_RANGE; j += i) // 枚举 i 的倍数

                prime[j] = i; // 始终用素数 i 更新为 j 的最大素因子

    }

    int32_t n;

    while (scanf("%d", &n) != EOF) {

        //输出 n 的最大素因子

        printf("%d\n", prime[n]);

    }

    return 0;

}
```
####线性筛
```
#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d ", prime[i]);
    }
    printf("\n");
    return 0;
}
```
###PE 08 滑动窗口法
题意：求连续13个数乘积最大值
```
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

char num[1005] = {0}, temp[1005] = {0};

int main() {
    while (scanf("%s", temp) != EOF) {
        strcat(num, temp);
    }
    int64_t p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') {
            zero += 1;
        } else {
            p *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -= 1;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
```
###PE 11 方向数组
题意：给出一个二维数组，共八个方向，求出一个方向上连续四个数最大乘积
思路：枚举每个数，简化为四个方向，开一个方向数组遍历
WA点：数组初始化
```
#include <stdio.h>

int dir_arr[4][2] = {
    1, 1, 1, -1, 
    0, 1, 1, 0
};

int main() {
    int num[30][30] = {0};
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", num[i] + j);
        }
    }
    int ans = 0;
    for (int x = 5; x < 25; x++) {
        for (int y = 5; y < 25; y++) {
            for (int k = 0; k < 4; k++) {
                int p = 1;
                for (int step = 0; step < 4; step++) {
                    int xx = x + step * dir_arr[k][0];
                    int yy = y + step * dir_arr[k][1];
                    p *= num[xx][yy];
                }
                if (p > ans) ans = p;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
```
###PE 14 记忆化
题意：给出数列规律，求最长链的长度
WA点：long long
```
#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000
#define KEEP_RANGE 2000000

int keep_ans[KEEP_RANGE + 5] = {0};

int get_length(int64_t x) {
    if (x == 1) return 1;
    if (x <= KEEP_RANGE && keep_ans[x]) return keep_ans[x];
    int temp_ans;
    if (x & 1) temp_ans = get_length(x * 3 + 1) + 1;
    else temp_ans = get_length(x >> 1) + 1;
    if (x <= KEEP_RANGE) keep_ans[x] = temp_ans;
    return temp_ans;
}

int main() {
    int ans = 0, ans_length = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp_length = get_length(i);
        if (temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;
        }
    }
    printf("%d(%d)\n", ans, ans_length);
    return 0;
}
```
###PE 17 找规律
###PE 13 大整数加法
题意：求出100个50位数字之和的前十位
```
#include <stdio.h>
#include <string.h>

char num[55];
int ans[55] = {1, 0};

int main() {
    for (int i = 0; i < 100; i++) {
        scanf("%s", num);
        int len = strlen(num);
        if (ans[0] < len) ans[0] = len;
        for (int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
```
加法框架可改为乘法
###PE 25 循环数组
题意：第一个位数大于1000的斐波那契数
思路：大数加法+循环数组
```
#include <stdio.h>

int fib[3][1005] = {{0, 0}, {1, 1}, {1, 1}};
int n = 2;

int main() {
    while (fib[n % 3][0] < 1000) {
        n += 1;
        int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        a[0] = b[0];
        for (int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i];
        }
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (a[0] == i);
        }
    }
    printf("%d\n", n);
    return 0;
}
```
###PE 31 加法原理
题意：给出面值为1p,2p,5p,10p,20p,50p,100p,200p的硬币，拼凑出200p的方法有多少种
WA点：边界条件
####二维
```
#include<stdio.h>
int dp[8][205]={0};
int w[8]={1,2,5,10,20,50,100,200};
int main()
{
    for(int i=0;i<8;i++){
        for(int j=0;j<=200;j++){
            if(j==0){
                dp[i][j]=1;
                continue;
            }
            if(i>=1)dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]+=dp[i][j-w[i]];
        }
    }
    printf("%d\n",dp[7][200]);
}
```
####一维
```
#include <stdio.h>
#define MAX_W 8
#define MAX_N 201

int w[MAX_W] = {1, 2, 5, 10, 20 , 50, 100, 200};
int dp[MAX_N] = {0};

int main() {
    dp[0] = 1;
    for (int i = 0; i < MAX_W; i++) {
        for (int j = w[i]; j < MAX_N; j++) {
            dp[j] += dp[j - w[i]];
        }
    }
    printf("%d\n", dp[MAX_N - 1]);
    return 0;
}
```
###PE 32 正整数位数公式 
题意：如果一个n位数包含了1至n的所有数字恰好一次，我们称它为全数字的；例如，五位数15234就是1至5全数字的。
7254是一个特殊的乘积，因为在等式39 × 186 = 7254中，被乘数、乘数和乘积恰好是1至9全数字的。
找出所有被乘数、乘数和乘积恰好是1至9全数字的乘法等式，并求出这些等式中乘积的和。
注意：有些乘积可能从多个乘法等式中得到，但在求和的时候只计算一次。
```
#include<stdio.h>
#include<math.h>
int digit(int x)
{
    return floor(log10(x))+1;
}
bool check1(int x,int *vis)
{
    while(x)
    {
        if(x%10==0) return 0;//坑点！
        if(vis[x%10]) return 0;
        vis[x%10]=1;
        x/=10;
    }
    return 1;
}
bool check(int a,int b,int c){
    int vis[10]={0};
    if(!check1(a,vis)) return 0;
    if(!check1(b,vis)) return 0;
    if(!check1(c,vis)) return 0;
    return 1;
}
int vis[100005]={0};
int main()
{
    int ans=0;
    for(int i=2;digit(i)+digit(i)+digit(i*i)<=9;i++){
        for(int j=i+1;digit(i)+digit(j)+digit(i*j)<=9;j++){
            if(digit(i)+digit(j)+digit(i*j)<9) continue;
            if(check(i,j,i*j)&&!vis[i*j]){
                vis[i*j]=1;
                ans+=i*j;
            } 
        }
    }
    printf("%d\n",ans);
    return 0;
}

```
###PE 33 除法判断转乘法
题意：求按照错误的约分方式结果正确的四个数的乘积最简形式分母的值
WA点：题中条件是非平凡解，10/20=1/2这种不算
```
#include<stdio.h>
bool check(int x,int y)
{	//分式相等转化为乘法
    int x1=x/10,x2=x%10,y1=y/10,y2=y%10;
    if(x%10==0&&y%10==0) return 0;
    if(x1==y1) return x*y2==y*x2; 
    if(x1==y2) return x*y1==y*x2;
    if(x2==y1) return x*y2==y*x1;
    if(x2==y2) return x*y1==y*x1;
    return 0;
}
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    int x=1,y=1;
    for(int i=10;i<100;i++){
        for(int j=i+1;j<100;j++){
            if(check(i,j)){
                x*=i;
                y*=j;
            }
        }
    }
    y/=gcd(y,x);//约分
    printf("%d\n",y);
    return 0;
}
```
###PE 35 整数循环右移
题意：197被称为圆周素数，因为将它逐位旋转所得到的数：197、971和719都是素数。小于100的圆周素数有十三个：2、3、5、7、11、13、17、31、37、71、73、79和97。小于一百万的圆周素数有多少个？
思路：有几位说明能旋转几次，求出位数后逐一判断即可
```
#include<stdio.h>
#include<math.h>
#define MAXN 1000000
int prime[MAXN+5];
bool check(int x)
{
    int digit=floor(log10(x))+1;//位数
    for(int i=0;i<digit;i++){
        x=x/10+(x%10)*(pow(10,digit-1));
        if(prime[x]) return 0;
    }
    return 1;
}
int main()
{
    int cnt=0;
    for(int i=2;i*i<=MAXN;i++){
        if(prime[i]) continue;
        for(int j=i*i;j<=MAXN;j+=i){
            prime[j]=1;
        }
    }
    for(int i=2;i<=MAXN;i++){
        if(check(i)) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
```
题意：3797有着奇特的性质。不仅它本身是一个素数，而且如果从左往右逐一截去数字，剩下的仍然都是素数：3797、797、97和7；同样地，如果从右往左逐一截去数字，剩下的也依然都是素数：3797、379、37和3。只有11个素数，无论从左往右还是从右往左逐一截去数字，剩下的仍然都是素数，求这些数的和。注意：2、3、5和7不被视为可截素数。
###PE 37 数字截位
WA点：要注意1既不是合数也不是素数，
```
#include<stdio.h>
#include<math.h>
#define MAXN 5000000
int is_prime[MAXN+5]={0,1};
int primes[MAXN]={0};
bool check(int x)
{
    int a=x;
    while(a)
    {
        if(is_prime[a]) return 0;
        a/=10;//右移
    }
    int b=x;
    while(b)
    {
        if(is_prime[b]) return 0;
        b=b%(int)(pow(10,floor(log10(b))));//左移
        
    }
    return 1;
}
int main()
{
    int cnt=0;
    for(int i=2;i*i<=MAXN;i++){
        if(is_prime[i]) continue;
        for(int j=i*i;j<=MAXN;j+=i){
           is_prime[j]=1;
        }
    }
    for(int i=1;i<=MAXN;i++){
        if(!primes[i]) primes[++primes[0]]=i;
    }
    long long sum=0;
    for(int i=1;i<=primes[0];i++){
        if(primes[i]<10) continue;
        if(check(primes[i])){
            printf("%d\n",primes[i]);
            sum+=primes[i];
            cnt++;
        }   
    }
    printf("%lld %d\n",sum,cnt);
    return 0;
}
```
###PE 38 抽屉原理
题意：将9分别与1、2、3、4、5相乘，得到1至9全数字的数918273645，即是9和(1,2,3,4,5)的连接乘积。
对于n > 1，所有某个整数和(1,2, … ,n)的连接乘积所构成的数中，最大的1至9全数字的数是多少？
思路：遍历到五位数，判断时用两个变量，一个用作乘数，一个统计使用的数字个数，为0或用过的会被返回false，因此最终j=9
```
 #include<stdio.h>
 #include<math.h>
 #define MAXN 100000
 int digit(int x)
 {
     return floor(log10(x))+1;
 }
 int check(int x)	
 {
     int i=1,res=0,j=0;
     int num[10]={0};
     while(j<9)
     {
         int tmp=i*x;
         res=res*((int)pow(10,digit(tmp)))+tmp;
         while(tmp)
         {
             if(tmp%10==0) return 0;
             if(num[tmp%10]) return 0;
             num[tmp%10]=1;
             j++;
             tmp/=10;
         }
         i++;
     }
     return res;
 }
 int main()
 {
     int ans=1;
     for(int i=1;i<MAXN;i++){
         int t=check(i);
         if(t>ans) ans=t;
     }
     printf("%d\n",ans);
     return 0;
 }
```
###PE 43 全排列函数
题意：1406357289是一个0至9全数字数，因为它由0到9这十个数字排列而成；但除此之外，它还有一个有趣的性质：子串的可整除性。
记d1是它的第一个数字，d2是第二个数字，依此类推，我们注意到：
d2d3d4=406能被2整除
d3d4d5=063能被3整除
d4d5d6=635能被5整除
d5d6d7=357能被7整除
d6d7d8=572能被11整除
d7d8d9=728能被13整除
d8d9d10=289能被17整除
找出所有满足同样性质的0至9全数字数，并求它们的和。
```
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int prime[8]={0,2,3,5,7,11,13,17};
bool check(int *a)
{
    for(int i=1;i<=7;i++){
        if((a[i]*100+a[i+1]*10+a[i+2])%prime[i]) return 0;
    }
    return 1;
}
int main()
{
    long long ans=0;
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    do{
        long long res=0;
        if(a[0]==0) continue;//不含前导0
        for(int i=0;i<10;i++){
            res=res*10+a[i];
        }
        ans+=check(a)*res;
    }while(next_permutation(a,a+10));
    printf("%lld\n",ans);
}
```
###PE 44 二分法
题意：五边形数由公式Pn=n(3n−1)/2生成。前十个五边形数是：
1, 5, 12, 22, 35, 51, 70, 92, 117, 145, …
可以看出P4 + P7 = 22 + 70 = 92 = P8。然而，它们的差70 − 22 = 48并不是五边形数。
在所有和差均为五边形数的五边形数对Pj和Pk中，找出使D = |Pk − Pj|最小的一对；此时D的值是多少？
思路：
二分：单调性问题，二分的是数据范围
while循环结束条件是本题重点
```
#include <stdio.h>
#include <inttypes.h>

int64_t pentagonal(int64_t n) { 
    return n * (3 * n - 1) / 2;
}

int64_t is_pentagonal(int64_t x) {
    int64_t head = 1, tail = 500000000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return 1;
        if (pentagonal(mid) > x) tail = mid - 1;
        else head = mid + 1;
    }
    return 0; 
}

int main() {
    int64_t i = 1, j = 1, ans = INT64_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j++;
        i = j - 1;
        do {
            if (is_pentagonal(pentagonal(i) + pentagonal(j))) {
                if (is_pentagonal(pentagonal(j) - pentagonal(i))) {
                    if (pentagonal(j) - pentagonal(i) < ans) {
                        ans = pentagonal(j) - pentagonal(i);
                        printf("%" PRId64 " -> %" PRId64 "\n", pentagonal(j), pentagonal(i));
                    }
                }
            }
            i--;
        } while (i >= 1 && pentagonal(j) - pentagonal(i) < ans);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
```
### PE 45 二分+找规律+函数指针优化
题意：三角形数、五边形数和六角形数分别由以下公式给出：
三角形数	Tn=n(n+1)/2	1, 3, 6, 10, 15, …
五边形数	Pn=n(3n−1)/2	1, 5, 12, 22, 35, …
六边形数	Hn=n(2n−1)	1, 6, 15, 28, 45, …
可以验证，T285 = P165 = H143 = 40755。
找出下一个同时是三角形数、五边形数和六角形数的数。
思路：六边形数都是三角形数，且增长速度最快，枚举六边形数
```
#include <stdio.h>
#include <inttypes.h>

typedef int64_t int1;

int1 Triangle(int1 n) {
    return n * (n + 1) / 2;
}

int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 Hexagonal(int1 n) {
    return n * (2 * n - 1);
}

int1 binary_search(int1 (*num)(int1), int1 n, int1 x) {
    int1 head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return mid;
        if (num(mid) > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

int main() {
    int1 n = 144;
    while (binary_search(Pentagonal, 2 * n, Hexagonal(n)) == -1) ++n;
    printf("%" PRId64 "\n", Hexagonal(n));
    return 0;
}
```