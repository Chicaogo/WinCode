//https://www.luogu.org/problemnew/show/T48566
#include <bits/stdc++.h>
using namespace std;

inline int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

const long long mo=998244353;
int n;
long long a;
long long ans = 0;

long long mimi(long long a, long long b, int n)
{
	long long ans=1;
	a=a%n;
	while(b>0)
	{
		if(b%2==1)
			ans=(ans*a)%n;
		b/=2;
		a=(a*a)%n;
	};
    return ans;
}

int main(int argc, char const *argv[])
{
    n=read();
    int p=n-1,b=2;
    long long qwq;
    qwq=mimi(b,p,mo);

    for(int i=1;i<=n;++i)
    {
        a=read();
        a=a*qwq%mo;
        ans+=a;
        ans%=mo;
    }

    printf("%lld",ans);

    getchar();getchar();getchar();
    //printf("%d", );
    return 0;
}
