/*
题目背景
奶牛爱干草
题目描述
Bessie 计划调查N (2 <= N <= 2,000)个农场的干草情
况，它从1号农场出发。农场之间总共有M (1 <= M <= 1
0,000)条双向道路，所有道路的总长度不超过1,000,000
,000。有些农场之间存在着多条道路，所有的农场之间都
是连通的。
Bessie希望计算出该图中最小生成树中的最长边的长度。
输入输出格式
输入格式：
两个整数N和M。
接下来M行，每行三个用空格隔开的整数A_i， B_i和L_i
，表示A_i和 B_i之间有一条道路长度为L_i。
输出格式：
一个整数，表示最小生成树中的最长边的长度。
输入输出样例:
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2010;
const int MAX_M = 10010;

struct edge
{
    int v,next,w;
    bool operator < (const edge &a) const{
        return w < a.w;
    }
}e[MAX_M];

int fa[MAX_N];

int fin(int v){
    if (fa[v] == v) return v;
    else return fa[v]=fin(fa[v]);
}

int main(int argc, char const *argv[])
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%d%d%d",&e[i].v,&e[i].next,&e[i].w);
    sort(e+1,e+m+1);
    for(int i=1;i<=n;++i) fa[i]=i; 
    int rst = n,ans = 0;
    for(int i=1;i <= m && rst>1;i++){
        int x=fin(e[i].v),y=fin(e[i].next);
        if (x != y) {
            rst--;
            fa[x]=y;
            ans=e[i].w;
        }
    }
    printf("%d",ans);
    getchar();getchar();getchar();
    return 0;
}
