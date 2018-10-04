//https://www.luogu.org/problemnew/show/T48568
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

int T,a;

int main(int argc, char const *argv[])
{
    T=read();
    for(int q=1;q<=T;++q)
    {
        a=read();
		long long sum,x;
		for(int j=1;j<=a;++j)
		{
			x=a%j;
			sum+=x;
		}
		printf("%d",sum);
    }
    getchar();getchar();getchar();
    return 0;
}
