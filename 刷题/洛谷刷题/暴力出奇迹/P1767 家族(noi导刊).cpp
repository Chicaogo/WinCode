#include<bits/stdc++.h>
using namespace std;

string ss[110];
int vis[110][666];
int pao[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n = 0 , ans = 0;

void dfs(int x,int y)
{
    for(int i = 0;i < 4;++i)
    {
        int nx = x + pao[i][0] , ny = y + pao[i][1];
        if(!vis[nx][ny] && ny>=0 && nx > 0 && nx <= n && ny < ss[nx].size() && ss [nx][ny]>='a' &&ss[nx][ny]<='z')
        {
            vis[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    getline(cin,ss[100]);
    for(int i = 1;i <= n;i++)
    {
        getline(cin,ss[i]);
    }

    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j < ss[i].size();++j)
        if(!vis[i][j] && ss[i][j]!=' ' && ss[i][j]>='a'&&ss[i][j]<='z')
        {
            vis[i][j] = true;
            ans++;
            dfs(i,j);
        }
    }
    
    cout << ans;


    return 0;
}
