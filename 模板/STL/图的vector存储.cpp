#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int to;
    int cost;
};
vector <Edge> G[10000];//G[i]代表从i出发的边，vector里存的是边
int m,n;
int temp1;
int main(void)
{
    scanf("%d%d",&n,&m);//结点数，边数,从1开始
    while(m--)
    {
        Edge e;
        scanf("%d%d%d",&temp1,&e.to,&e.cost);
        G[temp1].push_back(e);
    }
    for(int i=1;i<=n;i++)//遍历从每个节点出发的所有边
    {
        for(int j=0;j<G[i].size();j++)//G[i].size()为以i出发的边的条数
        {
            Edge e=G[i][j];
            printf("From %d to %d, the cost is %d\n",i,e.to,e.cost);
        }
    }
    getchar(); getchar(); getchar();
    return 0;
 
}
