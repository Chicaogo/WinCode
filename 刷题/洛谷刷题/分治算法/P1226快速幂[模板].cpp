#include<bits/stdc++.h>
using namespace std;
long long b,n,p,k,ans=1,m;
int main()
{
    scanf("%lld%lld%lld",&b,&p,&k);
    n=b;m=p;
    while(p>0)//快速幂
    {
        if(p%2!=0)
            ans=ans*b%k;    //如果p为单数，乘到ans里面去，然后取模
        b=b*b%k;             //每次运算都取模
        p=p>>1;               //用位运算除2，可能会快一点
    }
    if(n==1 && m==0 && k==1) printf("%lld^%lld mod %lld=0",n,m,k);
    else printf("%lld^%lld mod %lld=%lld",n,m,k,ans);//输出
    getchar();getchar();getchar();
    return 0;
}
