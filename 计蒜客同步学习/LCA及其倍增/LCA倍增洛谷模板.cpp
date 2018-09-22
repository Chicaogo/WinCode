#include<iostream>
#include<cstdio>
/*
输入样例：
5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5
输出样例：
4
4
1
4
4

*/
using namespace std;
struct yyy{
    int t,nex;
}e[2*500001];
//  第i节点深度   x节点的2^i级祖先  预处理加速  邻接表   
int deepth[500001],fa[500001][22],lg[500001],head[500001];
int tot = 0; //记录
void add(int x,int y) //邻接表存树
{
    e[++tot].t=y; 
    e[tot].nex=head[x];
    //cout<<head[x]<<ends;
    head[x]=tot;
    //cout<<head[x]<<ends;
}
void dfs(int f,int fath)//f表示当前节点，fath表示它的父亲节点
{
    deepth[f]=deepth[fath]+1;
    fa[f][0]=fath;
    for(int i=1;(1<<i)<=deepth[f];i++)//这个转移可以说是算法的核心之一
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
      x=fa[x][lg[deepth[x]-deepth[y]]-1];//先跳到同一深度
    if(x==y)//如果x是y的祖先，那他们的LCA肯定就是x了
      return x;
    for(int k=lg[deepth[x]];k>=0;k--)//不断向上跳（lg就是之前说的常数优化）
      if(fa[x][k]!=fa[y][k])//因为我们要跳到它们LCA的下面一层，所以他们肯定要不相等，如果不相等我们就跳过去。
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
        add(x,y);cout<<endl; add(y,x);cout<<endl;cout<<endl;
    }
    dfs(s,0);

    for(int i=1;i<=n;i++)
      lg[i]=lg[i-1]+(1<<lg[i-1]==i);//预先算出log_2(i)+1的值，用的时候直接调用就可以了
    for(int i=1;i<=m;i++)
    {
        int x,y;  scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    getchar();getchar();getchar();
    return 0;
}