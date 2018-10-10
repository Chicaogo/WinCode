//https://www.luogu.org/problemnew/show/P2895
#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
#define mp make_pair
#define INF 0x3f3f3f3f

const int maxn = 305;
int mapp[maxn][maxn] , dis[maxn][maxn] , vis[maxn][maxn];
//  ��ͼ           ��ÿ������������Сʱ��  ��¼������Ƿ�������
int pao[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; //�ĸ�����
queue<pa> q; //�洢�������

//�жϵ��Ƿ�Խ��
bool yes(int x,int y)
{
    if(x < 0 || y < 0) return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;

    //��ʼ������
    for(int i=0;i < maxn;++i)
        for(int j=0;j < maxn;++j)
        {
            mapp[i][j] = INF;
            dis[i][j] = INF;
        }

    //��ͼ����
    for(int i = 1;i <= m;++i)
    {
        int x,y,t;
        cin >> x >> y >> t;
        mapp[x][y] = min(mapp[x][y] , t);

        //�����м��� ��Χ���ĸ���ҲҪ����ȥ
        for(int j = 0;j < 4;++j)
        {
            int nx = x + pao[j][0],ny = y + pao[j][1];
            //�ж��Ƿ�Խ��
            if(yes(nx,ny))
            {
                mapp[nx][ny] = min(mapp[nx][ny] , t);
            }
        }
    }

    //��ʼ��spfa ԭ��
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
            //��������ĺ��� �����Դ�ֻ�����
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
    
    //����Ϊ ��-1�� �����
    if(ans == INF) 
    {
        cout << "-1";
        return 0;
    }
    cout << ans;

    return 0;
}