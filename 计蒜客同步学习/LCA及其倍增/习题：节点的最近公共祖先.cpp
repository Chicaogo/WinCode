/*
题意：树是一种很常见的数据结构。现在蒜头君面临一个
问题，在一个有 n 个节点的树上，节点编号分别是1…n。
蒜头想知道一些节点之间的最近公共祖先是那些节点。
输入格式 
第一行输入一个整数 n（2≤n≤10,000），表示树上有 n 
个节点。 
接下来的 n−1 行，每行输入俩个整数 a，b（1≤a,b≤n）
代表节点 a，b 之间有一条 a 到 b 边，a 是 b 的父亲。 
接下来输入一个整数 q，代表蒜头君的 q 次提问。
（1≤q≤1,000） 
接下来的 q 行，每行输入俩个整数 c，d（1≤c,d≤n）
代表询问 c，d 俩个节点的最近公共祖先。 
输出格式 
对于每次询问，输出公共祖先的节点编号，占一行。 
样例输入 
5 
1 2 
2 3 
1 4 
2 5 
2 
3 4 
3 5 
样例输出 
1 
2
*/
#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;
const int MAX_N=100000;
const int MAX_M=1000000;
int isleave[100050];
struct edge{
    int v,next;
}E[MAX_M];
int p[MAX_N],eid;
void init(){
    memset(p,-1,sizeof(p));
    memset(isleave,0,sizeof(isleave));
    eid=0;
}
void insert(int u,int v){
    E[eid].v=v;
    E[eid].next=p[u];
    p[u]=eid++;
}
int d[MAX_N],fa[MAX_N][20];
void dfs(int u){
    for(int i=p[u];i!=-1;i=E[i].next){
        if(d[E[i].v]==-1){
            d[E[i].v]=d[u]+1;
            fa[E[i].v][0]=u;
            dfs(E[i].v);
        }
    }

}

int lca(int x,int y){
    int i,j;
    if(d[x]<d[y]){
        swap(x,y);
    }
    for(i=0;(1<<i)<=d[x];i++);
    i--;
    for(j=i;j>=0;j--){
        if(d[x]-(1<<j)>=d[y]){
            x=fa[x][j];
        }
    }
    if(x==y){
        return x;
    }
    for( j=i;j>=0;j--)
    {
        if(fa[x][j]!=fa[y][j]){
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    return fa[x][0];
}
int main() {
    int n;
    init();
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        insert(u,v);
        insert(v,u);
        isleave[v]=1;
    }
    memset(d,-1,sizeof(d));
    int root;
    for(int i=1;i<=n;i++)
        {
        if(isleave[i]==0){
            root=i;
            break;
        }
    }
    d[root]=1;
    dfs(root);
    for(int level=1;(1<<level)<=n;level++){
        for(int i=1;i<=n;i++){
            fa[i][level]=fa[fa[i][level-1]][level-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}
