#include<bits/stdc++.h>
using namespace std;

const int maxn = 500000;
const int inf = 1e9;
int mapp[710][710];
int n,m,sum = 0,ans = 0;

struct edge{
    int x,y,h;
    bool operator < (const edge &a)
    {
        return h > a.h;
    }
}num[maxn];

void dfs(int x,int y)
{
    sum++;
    int hight = mapp[x][y];
    mapp[x][y] = inf;
    if(hight >= mapp[x+1][y]) dfs(x+1,y);
    if(hight >= mapp[x+1][y+1]) dfs(x+1,y+1);
    if(hight >= mapp[x+1][y-1]) dfs(x+1,y-1);
    if(hight >= mapp[x][y+1]) dfs(x,y+1);
    if(hight >= mapp[x][y-1]) dfs(x,y-1);
    if(hight >= mapp[x-1][y]) dfs(x-1,y);
    if(hight >= mapp[x-1][y+1]) dfs(x-1,y+1);
    if(hight >= mapp[x-1][y-1]) dfs(x-1,y-1);
}

int main(void)
{
    cin >> n >> m;
    for(int i=0;i<=m+1;i++)//防止越界
    {
        mapp[0][i]=inf;
        mapp[n+1][i]=inf;
    }
    for(int i=0;i<=n+1;i++)//防止越界
    {
        mapp[i][0]=inf;
        mapp[i][m+1]=inf;
    }

    int k = 0;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            k++;
            cin >> mapp[i][j];
            num[k].h = mapp[i][j];
            num[k].x = i;
            num[k].y = j;
        }
    }

    sort(num+1,num+n*m+1);
    k = 0;

    while(sum < n*m)
    {
        ans++;
        while(mapp[num[k].x][num[k].y] == inf) k++;
        dfs(num[k].x,num[k].y);
    }

    cout << ans;

    return 0;
}