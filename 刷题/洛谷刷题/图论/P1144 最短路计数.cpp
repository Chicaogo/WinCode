#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
    char ch=getchar(); 
    int x=0,t=1;
    while((ch>'9'||ch<'0'))
    if(ch=='-'){if(ch == '-') t=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*t;
}
int mod=100010;
int n,m,x,y,tot=0;
const int N=1000010,M=4000010;
int head[N],to[M],nxt[M],d[N],ans[N];
bool p[N];
priority_queue< pair< int,int > > q;
void add(int x,int y)
{
    to[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        x=read();y=read();
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        d[i]=1e9;p[i]=0;
    }
    d[1]=0;ans[1]=1;
    q.push(make_pair(0,1));
    while(q.size())
    {
        x=q.top().second;
        q.pop();
        if(p[x])    continue;
        p[x]=1;
        for(int i=head[x];i;i=nxt[i])
        {
            y=to[i];
            if(d[y]>d[x]+1)
            {
                d[y]=d[x]+1;
                ans[y]=ans[x];
                q.push(make_pair(-d[y],y));
            }
            else if(d[y]==d[x]+1)
            {
                ans[y]+=ans[x];
                ans[y]%=mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}