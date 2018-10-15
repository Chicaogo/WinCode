#include <bits/stdc++.h>
using namespace std;

int m,n,mapp[110][110];
int pao[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

void dfs(int x,int y)
{
    if(x < 0 || y < 0 || x > n || y > m) return;
    mapp[x][y] = 0;
    for(int i = 0;i < 4;++i)
    {
        int nx = x + pao[i][0],ny = pao[i][1];
        if(mapp[nx][ny]) dfs(nx,ny);
    }
}

int main(void)
{
    int ans = 0;
    cin >> m >> n;
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            scanf("%1d",&mapp[i][j]);
        }
    }
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            if(mapp[i][j])
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans;
    return 0;
}