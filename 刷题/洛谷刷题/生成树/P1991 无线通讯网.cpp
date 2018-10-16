#include<bits/stdc++.h>
using namespace std;

int fa[520];

struct edge
{
    int u,v;
    double w;
    bool operator < (const edge &a)
    {
        return w < a.w;
    }
}G[300010];

inline fin(int x)
{
    return fa[x] == x ? x : fa[x] = fin(fa[x]);
}

int main(int argc, char const *argv[])
{
    int x[520],y[520];
    int s,p,num;
    cin >> s >> p;
    num = p;
    for(int i = 1;i <= p;++i)
    {
        fa[i] = i;
        cin >> x[i] >> y[i];
    }

    int k = 0;

    for(int i = 1;i <= p;++i)
    {
        for(int j = 1;j <= p;++j)
        {
            G[k].u = i;
            G[k].v = j;
            G[k].w = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
            k++;
        }
    }

    sort(G,G+k);

    int i;
    for(i = 0;i < k;++i)
    {
        int nx = fin(G[i].u) ,  ny = fin(G[i].v);
        if(nx != ny)
        {
            fa[nx] = fin(fa[ny]);
            num--;
        }
        if(num <= s) break;
    }

    printf("%.2lf",G[i].w);

    return 0;
}
