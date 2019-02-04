#include<bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int g[maxn][maxn];

int main(void)
{
    int N,R;
    cin >> N >> R;

    int n = R, m = R;

    for(int i = 0,x,y,w;i < N;++i)
    {
        cin >> x >> y >> w;
        x++,y++;
        n = max(n,x);
        m = max(m,y);
        g[x][y] += w;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= m; j++)
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i][j];

    int ans = 0;
    for(int i = R;i <= n;i++)
        for(int j = R;j <= m;j++)
            ans = max(ans,g[i][j]-g[i-R][j]-g[i][j-R]+g[i-R][j-R]);
    
    cout << ans ;

    return 0;
}