###PE  40 
题意：将所有正整数连接起来构造的一个十进制无理数如下所示：
0.123456789101112131415161718192021…
可以看出小数点后第12位数字是1。
如果dn表示上述无理数小数点后的第n位数字，求下式的值：
d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
```
/*************************************************************************
	> File Name: 40.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 13时11分15秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int dnum[10]={0,9};
int getnum(int d)
{
    if(d<10) return d;
    int res=0,digit;
    for(int i=1;i<=9;i++){
        if(res+dnum[i]*i>=d){
            digit=i;//所在数字的位数
            break;
        }
        res+=dnum[i]*i;
    }
    int m=d-res;//剩余需要跳过的位数
    int n=(int)pow(10,digit-1)+(m-1)/digit;//在哪个数字中
    int p=m%digit;
    int ans;
    int q=digit-p;//是所在数字的第几位
    while(q--)
    {
        n/=10;
        ans=n%10;
    }
    return ans;
}
int main()
{
    for(int i=2;i<=9;i++){
        dnum[i]=dnum[i-1]*10;
    }
    int ans=1;
    for(int i=1;i<=1000000;i*=10){
        ans*=getnum(i);
    }
    printf("%d\n",ans);
    return 0;
}
```
###PE 50
```
/*************************************************************************
	> File Name: 50.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 23时45分02秒
 ************************************************************************/

#include<stdio.h>
#define MAXN 1000000
int prime[MAXN+5]={0};
int is_prime[MAXN+5]={0};
int sum[MAXN+5]={0};
int main()
{
    for(int i=2;i<=MAXN;i++){
        if(!is_prime[i]){
            prime[++prime[0]]=i;
        }
        for(int j=1;j<=prime[0];j++){
            if(i*prime[j]>MAXN) break;
            is_prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    for(int i=1;i<=prime[0];i++){
        sum[i]=sum[i-1]+prime[i];
    }
    int maxn=0,ans=0;
    for(int i=1;i<=prime[0];i++){
        for(int j=i+maxn+1;j<=prime[0];j++){
            int tmp=sum[j]-sum[i];
            if(tmp>MAXN) break;
            if(j-i<maxn) break;
            if(tmp<MAXN&&(!is_prime[tmp])){
                    maxn=j-i;
                    ans=tmp;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
```
###PE 19 日期枚举
```
/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 15时16分50秒
 ************************************************************************/

#include<stdio.h>
int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int nextd(int y,int m,int d)
{
    d++;
    if((y%4==0&&y%100)||y%400==0){
        if(d>a[m]) d=1;
    }else{
        if(d>b[m]) d=1;
    }
    return d;
}
int main()
{
    int d=1,m=1,y=1900,w=1,cnt=0;
    while(!(y==2000&&m==12&&d==31))
    {
        d=nextd(y,m,d);
        if(d==1) m++;
        if(m==13){
            y++;
            m=1;
        }
        w=(w+1)%7;
        if(d==1&&w==0&&y>1900) cnt++;
    }
    printf("%d\n",cnt);
}
```