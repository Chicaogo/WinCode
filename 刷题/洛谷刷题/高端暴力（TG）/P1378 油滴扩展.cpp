#include<bits/stdc++.h>
using namespace std;

const double pa = 3.141592;
const int maxn = 7;
int vis[maxn],mapp[maxn][3];
double r[maxn];
int n,x_1,y_1,x_2,y_2;
double anser,ss;

inline double rr(int x1,int y1,int x2,int y2)
{
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

inline double rrmax(int qwq)
{
    for(int i=1;i <= n;++i)
    {
        if(i != qwq && vis[i] == 1)
        {
            if(r[i] > rr(mapp[i][1],mapp[i][2],mapp[qwq][1],mapp[qwq][2]))
                return 0;
        }
    }

    double cnt;
    double ans = min(min(abs(mapp[qwq][1]-x_1),abs(mapp[qwq][1]-x_2)),min(abs(mapp[qwq][2]-y_1),abs(mapp[qwq][2]-y_2)));

    for(int i=1;i <= n;++i)
    {
        if(i != qwq && vis[i] == 1)
        {
            cnt = rr(mapp[i][1],mapp[i][2],mapp[qwq][1],mapp[qwq][2]) - r[i];
            ans = min(ans,cnt); 
        }
    }
    //cout << ans << endl;
    return ans;
}

void dfs(int qwq,double res)
{
    if(qwq == n)
    {
        anser = max(anser,res);
        return ;
    }

    for(int i = 1;i <= n;++i)
    {
        if(!vis[i])
        {
            r[i] = rrmax(i);
            vis[i] = 1;
            //cout << "   " << i << " " << r[i] << endl;
            dfs(qwq+1,res+pa*r[i]*r[i]);
            vis[i] = 0;
            r[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    ss = abs(x_1-x_2)*abs(y_1-y_2);

    for(int i = 1;i <= n;++i) cin >> mapp[i][1] >> mapp[i][2];

    dfs(0,0);

    cout << int(ss-anser+0.5);

    return 0;
}
