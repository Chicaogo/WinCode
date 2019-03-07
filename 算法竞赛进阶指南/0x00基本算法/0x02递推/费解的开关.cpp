#include<bits/stdc++.h>
using namespace std;

const int inf = 0x3fffffff;
char g[6][6];
int dx[6] = {0,-1,0,1,0},dy[6] = {0,0,1,0,-1};

void turn(int x,int y)
{
    for(int i = 0;i < 5;++i)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            g[nx][ny] ^= 1;
    }
}

int work()
{
    int ans = inf;

    for(int i = 0;i < 1 << 5;++i)
    {
        int res = 0;
        char cpy[6][6];
        memcpy(cpy,g,sizeof(g));
        
        for(int j = 0;j < 5;++j)
        {
            if(i >> j & 1)
            {
                res ++;
                turn(0,j);
            }
        }
        
        for(int y = 0;y < 4;++y)
        {
            for(int x = 0;x < 5;++x)
            {
                if(g[y][x] == '0')
                {
                    res ++ ;
                    turn(y + 1,x);
                }
            }
        }

        bool qwq = true;
        for(int x = 0;x < 5;++x)
            if(g[4][x] == '0')
            {
                qwq = false;
                break;
            }

        if(qwq) ans = min(ans,res);
        memcpy(g,cpy,sizeof(g));
    }
    
    if(ans > 6) ans = -1;
    return ans;
}

int main(void)
{
    int T;
    cin >> T;
    
    while(T--)
    {
        for(int i = 0;i < 5;++i)
            cin >> g[i];
        
        cout << work() << endl;
    }
    
    return 0;
}