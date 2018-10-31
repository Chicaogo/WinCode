#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0,t = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x*10 + ch -'0'; ch = getchar();}
    return x*t; 
}

priority_queue<int> da;
priority_queue<int,vector<int>,greater<int> > xiao;

int num[1000010];
int n,k;
long long ansmin,ansmax;

inline void init()
{
    n = read(); k = read();
    for(int i = 1;i <= n;++i)
    {
        num[i] = read();
        da.push(num[i]);
    }
    sort(num+1,num+n+1);
}

inline void greed()
{
    for(int i = 1;i <= k;++i)
    {
        if(da.empty()) break;
        int qaq = da.top();
        ansmax += qaq;
        da.pop();
        da.push(qaq - 1);
    }
    int qwq = 1;
    for(int i = 1;i <= k;++i)
    {
		while(!num[qwq]) qwq++;
		ansmin += num[qwq];
		num[qwq]--; 
	}
}

int main(int argc, char const *argv[])
{
    init();
    greed();
    printf("%lld %lld",ansmax,ansmin);
    return 0;
}
