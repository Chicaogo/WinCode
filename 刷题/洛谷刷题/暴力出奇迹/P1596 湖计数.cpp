#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
char mapp[110][110];

int fuckx[9]={0,-1,-1,-1,0,0,1,1,1};//x方向
int fucky[9]={0,-1,0,1,-1,1,-1,0,1};//y方向

void dfs(int x,int y)
{
    mapp[x][y]='.';
    for(int i = 0;i <= 8;++i)
    {
        int nx=x+fuckx[i];
        int ny=y+fucky[i];
        if (nx<1||nx>n||ny<1||ny>m||mapp[nx][ny]=='.')//判断是否出界
            continue;
        mapp[nx][ny]='.';
        dfs(nx,ny);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

     for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            cin >> mapp[i][j];
    }
    
    ans = 0;
    
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            if(mapp[i][j] == 'W') 
            {
                ans++;
                dfs(i,j);
            }
        }
    }

    cout << ans;
    
    return 0;
}
