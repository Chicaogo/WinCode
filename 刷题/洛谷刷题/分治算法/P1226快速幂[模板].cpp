#include<bits/stdc++.h>
using namespace std;
long long b,n,p,k,ans=1,m;
int main()
{
    scanf("%lld%lld%lld",&b,&p,&k);
    n=b;m=p;
    while(p>0)//������
    {
        if(p%2!=0)
            ans=ans*b%k;    //���pΪ�������˵�ans����ȥ��Ȼ��ȡģ
        b=b*b%k;             //ÿ�����㶼ȡģ
        p=p>>1;               //��λ�����2�����ܻ��һ��
    }
    if(n==1 && m==0 && k==1) printf("%lld^%lld mod %lld=0",n,m,k);
    else printf("%lld^%lld mod %lld=%lld",n,m,k,ans);//���
    getchar();getchar();getchar();
    return 0;
}
