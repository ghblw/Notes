#第三章

###PE 12 整数因子个数
```c
#include <stdio.h>

#define MAX_N 100000

int dnum[MAX_N + 5] = {0};//约数个数
int mnum[MAX_N + 5] = {0};//最小素因子的幂次
int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * 2 <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
    return ;
}

int factor_nums(int n) {
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) / 2];
    }
    return dnum[n / 2] * dnum[n + 1];
}

int main() {
    init();
    int n = 1;
    while (factor_nums(n) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
```
### PE 21 整数因子和
```c
#include <stdio.h>

#define MAX_N 100000

int prime[MAX_N + 5] = {0};
int d_sum[MAX_N + 5] = {0};
int min_num[MAX_N + 5] = {0};

void init_prime() {
	for (int i = 2; i <= MAX_N; i++) {
		if (!prime[i]) {
			prime[++prime[0]] = i;
			d_sum[i] = i + 1;
			min_num[i] = i * i;
		}
		for (int j = 1; j <= prime[0]; j++) {
			if (prime[j] * i > MAX_N) break;
			prime[prime[j] * i] = 1;
			if (i % prime[j]) {
				d_sum[prime[j] * i] = d_sum[prime[j]] * d_sum[i];
				min_num[prime[j] * i] = min_num[prime[j]];
			} else {
				min_num[prime[j] * i] = min_num[i] * prime[j];
				d_sum[prime[j] * i] = d_sum[i] * (1 - min_num[i] * prime[j]) / (1 - min_num[i]);
				break;
			}
		}
	}
	for (int i = 2; i <= MAX_N; i++) {
		d_sum[i] -= i;
	}
	return ;
}

int main() {
	init_prime();
	int ans = 0;
	for (int i = 1; i <= MAX_N / 10; i++) {
		int a = i, b = d_sum[i];
		if (a == b || d_sum[b] != a) continue;
		ans += i;
	}
	printf("%d\n", ans);
}
```



###PE 18 数字三角形

####记忆化
```c
#include<stdio.h>
#define MAXN 30
int map[MAXN][MAXN];
int keep[MAXN][MAXN];
int solve(int i,int j)
{
    if(i==MAXN) return 0;
    if(keep[i][j]) return keep[i][j];
    int l=solve(i+1,j),r=solve(i+1,j+1);
    keep[i][j]=(l>r?l:r)+map[i][j];
    return keep[i][j];
}
int main()
{
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",&map[i][j]);
        }
    }
    printf("%d\n",solve(0,0));
    return 0;
}
```
####动态规划
（1）dp[i][j]:从（i，j）到底获得最大值
```c
#include<stdio.h>
#define MAXN 30
#define max(a,b) ((a)>(b)?(a):(b))
int dp[MAXN][MAXN]={0};
int main()
{
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i=MAXN;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
        }
    }
    printf("%d\n",dp[0][0]);
    return 0;
}
```
（2）dp[i][j]:从顶到（i,j） 获得最大值
```

```
###PE 24 全排列状态数
```C
#include <stdio.h>

#define MAX_N 10


int jnum[MAX_N] = {0};//跳过的个数
int dnum[MAX_N] = {0};//标记数字可用

void init() {
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
    return ; 
}

int judge_num(int n, int k) {
    int ind = (k / jnum[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
```
###PE 26 分数循环节
```
#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int dnum[MAX_N + 5];

int get_length(int d) {
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));
    printf("1 / %d = 0.", d);
    while (y != 0 && dnum[y] == 0) {
        printf("%d", y * 10 / d);
        dnum[y] = n;
        y = y * 10 % d;
        n += 1;
    }
    printf("(%d)\n", y ? n - dnum[y] : 0);
    return y ? n - dnum[y] : 0;
}

int main() {
    int max_length = 0, ans = 0;
    for (int d = 2; d < 1000; d++) {
        int temp_length = get_length(d);
        if (temp_length > max_length) {
            max_length = temp_length;
            ans = d;
        }
    }
    printf("%d -> %d\n", ans, max_length);
    return 0;
}
```
###PE 29 大整数乘法/大整数素因子表示法
####大整数乘法
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10000
#define MAX_M 210

int *result[MAX_N] = {0};//指针数组
int result_length = 0;

int find_result(int *num) {
    for (int i = 0; i < result_length; i++) {
        if (memcmp(result[i], num, sizeof(int) * MAX_M)) continue;
        return i + 1;
    }
    return 0;
}

int *calc_num(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), MAX_M);
    temp[0] = temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int main() {
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp = calc_num(a, b);
            if (find_result(temp) == 0) {
                result[result_length++] = temp;
            } else {
                free(temp);
            }
        }
    }
    printf("%d\n", result_length);
    return 0;
}
```
####大整数素因子表示法
```
#include <stdio.h>
#include <string.h>

struct Tuple {
    int p, a;
};

struct Tuple M[10000][4] = {0};
int M_num = 0;

int prime[105] = {0};

void get_M(int a, int b, struct Tuple *M) {
    int m_len = 0;
    while (a != 1) {
        int p_num = 0, pre = prime[a];
        while (a % pre == 0) {
            a /= pre;
            p_num++;
        }
        M[m_len].p = pre;
        M[m_len].a = p_num * b;
        m_len++;
        if (m_len > 4) printf("error");
    }
    return ;
}

int main() {
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= 100; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            struct Tuple temp_M[4] = {0};
            get_M(a, b, temp_M);
            int flag = 1;
            for (int i = 0; i < M_num && flag; i++) {
                flag = memcmp(M[i], temp_M, sizeof(temp_M));
            }
            if (flag) {
                memcpy(M[M_num++], temp_M, sizeof(temp_M));
            }
        }
    }
    printf("%d\n", M_num);
    return 0;
}
```
###PE 39 素勾股数构造
题意：若三边长{a,b,c}均为整数的直角三角形周长为p，当p = 120时，恰好存在三个不同的解：
{20,48,52}, {24,45,51}, {30,40,50}
在所有的p ≤ 1000中，p取何值时有解的数目最多？
```
#include <stdio.h>

#include <inttypes.h>

 

#define MAX_RANGE 1000

 

int32_t many[MAX_RANGE] = {0};

 

int32_t gcd(int32_t a, int32_t b) {

    if (!b) return a;

    return gcd(b, a % b);

}

 

int32_t AddMany(int32_t a, int32_t b, int32_t c) {

    int32_t sum = 0, p = a + b + c;

    for (int32_t k = p; k <= MAX_RANGE; k += p) {

        many[k] += 1;

        sum += 1;

    }

    return sum;

}

 

int32_t main() {

    int32_t a, b, c, p;

    for (int32_t i = 2; i * i <= MAX_RANGE; i++) {

        for (int32_t j = 1; j < i; j++) {

            if (gcd(i, j) != 1) continue;

            a = i * i - j * j;

            b = 2 * i * j;

            c = i * i + j * j;

            if (a + b + c > MAX_RANGE) continue;

            AddMany(a, b, c);

        }

    }

    int32_t max_num = 1;

    for (int32_t i = 2; i <= MAX_RANGE; i++) {

        if (many[max_num] < many[i]) max_num = i;

    }

    printf("%d\n", max_num);

    return 0;

}
```
### PE 42 判断三角形数
题意：判断有多少个三角形单词
```
#include <stdio.h>

#include <inttypes.h>

#include <math.h>

#include "042.h"

 

bool isTriangleNumber(int32_t n) {

    int32_t m = (int32_t)floor(sqrt(n * 2));

    return m * (m + 1) / 2 == n;

}

 

int32_t main() {

    int32_t i = 0, sum = 0, total = 0;

    while (wordList[i].length() != 0) {

        sum = 0;

        for (int32_t j = 0; j < wordList[i].length(); j++) {

            sum += wordList[i][j] - 'A' + 1;

        }

        if (isTriangleNumber(sum)) ++total;

        ++i;

    }

    printf("%d\n", total);

    return 0;

}

 
```
### PE 46
题意：找到最小的不能写成一个素数和一个平方的两倍之和的奇合数
```
#include <stdio.h>

#include <inttypes.h>

 

#define MAX_N 10000

 

int32_t a[MAX_N + 5] = {0};

int32_t prime[MAX_N] = {0};

 

int32_t main() {

    for (int32_t i = 2; i <= MAX_N; i++) {

        if (!prime[i]) { prime[++prime[0]] = i; a[i] = 1; }

        for (int32_t j = 1; j <= prime[0]; j++) {

            if (i * prime[j] > MAX_N) break;

            prime[i * prime[j]] = 1;

            if (i % prime[j] == 0) break;

        }

    }

    for (int32_t i = 1; i <= prime[0]; i++) {

        for (int32_t n = 1; true; n++) {

            if (prime[i] + 2 * n * n > MAX_N) break;

            a[prime[i] + 2 * n * n] = 1;

        }

    }

    for (int32_t i = 9; i <= MAX_N; i += 2){

        if (a[i]) continue;

        printf("%d\n", i);

        break;

    }

    return 0;

}
```
### PE 47
题意：首次出现连续四个数均有四个不同的质因数时，其中的第一个数是多少？
```
#include <stdio.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) { 
            prime[++prime[0]] = i; 
            dnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            dnum[prime[j] * i] = dnum[i] + (i % prime[j] != 0);
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= MAX_N - 3; i++) {
        if (dnum[i] ^ 4) continue;
        if (dnum[i + 1] ^ 4) continue; 
        if (dnum[i + 2] ^ 4) continue;
        if (dnum[i + 3] ^ 4) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
```

