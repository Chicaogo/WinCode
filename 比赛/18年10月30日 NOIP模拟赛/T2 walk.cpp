#include<bits/stdc++.h>
using namespace std;

inline long long read()
{
    long long x = 0,t = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x*10 + ch -'0'; ch = getchar();}
    return x*t; 
}

int n,m,num[100010];

inline void init()
{
    n = read(); m = read();
    for(int i = 1;i <= n;++i)
    {
        num[i] = read();
    }
}

inline void greed()
{
	for(int i = 1;i <= m;++i)
	{
		int t = read();
		long long k = read();
        int end,cnt=0;
        int vis[100010];
        
		for(int i=1;i<=n;i++)vis[i]=0;
        
		for(int i=t;!vis[i];i=num[i])
        {
            vis[i]=1;
            end=num[i];
        }
        
		while(k&&t!=end)t=num[t],k--;
        
		if(k)
        {
            cnt=1;
            while(num[end]!=t) cnt++,end=num[end];
            k%=cnt;
        }
        while(k--)t=num[t];
        
		printf("%d\n",t);
	}
}

int main(int argc, char const *argv[])
{
    init();
    greed();
    return 0;
}
