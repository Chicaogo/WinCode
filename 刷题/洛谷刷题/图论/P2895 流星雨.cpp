//https://www.luogu.org/problemnew/show/P2895
#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
#define mp make_pair
#define INF 0x3f3f3f3f

const int maxn = 305;
int mapp[maxn][maxn] , dis[maxn][maxn] , vis[maxn][maxn];
//  存图           在每个点所花费最小时间  记录这个点是否在里面
int pao[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; //四个方向
queue<pa> q; //存储点的坐标

//判断点是否越界
bool yes(int x,int y)
{
    if(x < 0 || y < 0) return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;

    //初始化数组
    for(int i=0;i < maxn;++i)
        for(int j=0;j < maxn;++j)
        {
            mapp[i][j] = INF;
            dis[i][j] = INF;
        }

    //读图操作
    for(int i = 1;i <= m;++i)
    {
        int x,y,t;
        cin >> x >> y >> t;
        mapp[x][y] = min(mapp[x][y] , t);

        //读入中间点后 周围的四个点也要读进去
        for(int j = 0;j < 4;++j)
        {
            int nx = x + pao[j][0],ny = y + pao[j][1];
            //判断是否越界
            if(yes(nx,ny))
            {
                mapp[nx][ny] = min(mapp[nx][ny] , t);
            }
        }
    }

    //初始化spfa 原点
    dis[0][0] = 0;
    q.push(mp(0,0));
    int ans = INF;

    while(!q.empty())
    {
        pa p = q.front(); q.pop();
        int x = p.first,y = p.second;
        vis[x][y] = 0;

        for(int i = 0;i < 4;++i)
        {
            int nx = x + pao[i][0] , ny = y + pao[i][1];
            //整个代码的核心 不可言传只可意会
            if(yes(nx,ny) && dis[nx][ny] > dis[x][y]+1 && mapp[nx][ny] > dis[x][y] + 1)
            {
                dis[nx][ny] = dis[x][y] + 1;
                if(mapp[nx][ny] == INF) ans = min(dis[nx][ny] , ans);
                if(!vis[nx][ny])
                {
                    q.push(mp(nx , ny));
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    
    //特判为 “-1” 的情况
    if(ans == INF) 
    {
        cout << "-1";
        return 0;
    }
    cout << ans;

    return 0;
}