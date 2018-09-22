#include<bits/stdc++.h>
using namespace std;
/*
题意：
蒜国有 n 座基站，现在蒜头君想给基站之间布设光纤，使得任意两座基站都是连通的，光纤传输具有传递性，即如果基站 A 和基站 B 之间有光纤，基站 B 和基站 C 之间有光纤，则基站 A 和基站 C 也是连通的，
可以通过中间基站 B 来完成传输。 
不同的基站之间布设光纤的费用是不同的，现在蒜头君知道了任意两座基站之间布设光纤的费用，求问如何布设，可以使得任意两座基站都是连通的，且总费用最小。 
输入格式：
第一行输入一个整数 n(2≤n≤100)，表示蒜头基站总数。 
接下来输入 n×n 的矩阵。第 i 行第 j 列的整数表示第 i 座基站和第 j 座基站之间布设光纤的费用 wij（0≤wij ≤10,000）。 
输出格式：
输出一个整数，表示布设光纤的最小总费用，且使任意两座基站都是连通的。
样例输入：
4
0 1 5 1
1 0 6 3
5 6 0 2
1 3 2 0
样例输出：
4
*/
const int MAX_N=101,MAX_M=10010;
int G[110][110];
const int INF=0x3f3f3f3f;
int fa[MAX_N],n,m;

struct kin
{
    int u,v,w;
}rxz[MAX_M];
bool cmp(kin x,kin y){
    return x.w<y.w;
}
int fin(int x){
    if(fa[x]==x) return fa[x];
    return fa[x]=fin(fa[x]);
}
int main(){
    scanf("%d",&n);
    memset(G,INF,sizeof(G));
    for(int i=0;i<n;i++){
        for(int j = 0; j < n; j++)
        {
            int w;
            scanf("%d",&w);
            if(w!=0) G[i][j]=w;
        }
    }
    int eid=0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(G[i][j]<INF){
                rxz[eid].u=i;
                rxz[eid].v=j;
                rxz[eid].w=G[i][j];
                eid++;
            }
        }    
    }
    
    sort(rxz,rxz+eid,cmp);/*
    for(int i = 0; i < eid; i++)
    {
        cout<<rxz[i].u<<ends<<rxz[i].v<<ends<<rxz[i].w<<endl;
    }*/
    
    for(int i = 1; i <= MAX_N; ++i)
    {
        fa[i]=i;
    }
    int rest = n,ans=0;
    for(int i = 0; i < eid && rest>1; ++i)
    {
        int x = fin(rxz[i].u),y=fin(rxz[i].v);
        if (x!=y) {
            fa[x]=y;
            //cout<<rxz[i].w<<ends;
            ans = ans + rxz[i].w;
            rest--;
            //cout<<ans<<endl;
        }
    }
    
    printf("%d",ans);

    getchar();getchar();getchar();getchar();getchar();
    return 0;
}