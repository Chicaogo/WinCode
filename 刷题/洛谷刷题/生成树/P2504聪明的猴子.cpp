#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000+10;
const int maxm = 510;

int fa[maxn],n,m,x[maxn],y[maxn],jump[maxn];

struct edge{
    int x,y,w;
    bool operator < (const edge &a)
    {
        return w < a.w;
    }
}num[maxn];

inline int fin(int x)
{
    return fa[x] == x? x : fa[x] = fin(fa[x]);
}

int main(void)
{
    cin >> n ;
    for(int i = 1;i <= n;++i) cin >> jump[i];
    cin >> m ;
    int q = 0;
    for(int i = 1;i <= m;++i)
    {
        cin >> x[i] >> y[i];
        int nx = x[i] , ny = y[i];
        for(int j = 1;j < i;j++)
        {
            q++;
            int fx = nx - x[j] , fy = ny - y[j];
            int ww = fx*fx + fy*fy;
            num[q].x = i;
            num[q].y = j;
            num[q].w = ww;
        }
    }

    sort(num+1,num+q+1);
    int ans = 0;

    for(int i = 1;i <= q;++i)
    {
        int nx = fin(num[i].x) , ny = fin(num[i].y);
        if(nx != ny) 
        {
            fa[nx] = ny;
            ans = num[i].w;
        }
    }

    double anss = sqrt(ans);
    int ansed = 0;
    
    for(int i=1;i<=n;i++)
    {
        if(anss<=jump[i]) ansed++;
    }
    
    cout<<ansed;

    return 0;
}