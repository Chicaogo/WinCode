#include<iostream>
#include<cstdio>
using namespace std;
struct yyy{
    int t,nex;
}e[2*500001];
//  第i节点深度   x节点的2^i级祖先  预处理加速  邻接表   
int deepth[500001],fa[500001][22],lg[500001],head[500001];
int tot;
void add(int x,int y) //邻接表存树
{
    e[++tot].t=y; 
    e[tot].nex=head[x];
    head[x]=tot;
    cout<<e[tot+1].t<<ends<<e[tot]
}
void dfs(int f,int fath)
{
    deepth[f]=deepth[fath]+1;
    fa[f][0]=fath;
    for(int i=1;(1<<i)<=deepth[f];i++)
      fa[f][i]=fa[fa[f][i-1]][i-1];
    for(int i=head[f];i;i=e[i].nex)
      if(e[i].t!=fath)
        dfs(e[i].t,f);
}
int lca(int x,int y)
{
    if(deepth[x]<deepth[y])
      swap(x,y);
    while(deepth[x]>deepth[y])
      x=fa[x][lg[deepth[x]-deepth[y]]-1];
    if(x==y)
      return x;
    for(int k=lg[deepth[x]];k>=0;k--)
      if(fa[x][k]!=fa[y][k])
        x=fa[x][k], y=fa[y][k];
    return fa[x][0];
}
int n,m,s;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;  scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs(s,0);

    for(int i=1;i<=n;i++)
      lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=m;i++)
    {
        int x,y;  scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    getchar();getchar();getchar();
    return 0;
}