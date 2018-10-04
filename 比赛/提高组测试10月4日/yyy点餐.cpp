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



int main(int argc, char const *argv[])
{
    n=read();
    int p=n-1,b=2;
    long long qwq=1;
    while(p>0)
    {
        if(p%2!=0) qwq=qwq*b;
        b=b*b;
        p>>=1;
    }
    cout<<qwq<<endl;
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
