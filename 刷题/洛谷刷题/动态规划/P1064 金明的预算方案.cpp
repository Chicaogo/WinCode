//https://www.luogu.org/problemnew/show/P1064
#include<bits/stdc++.h>
using namespace std;

const int maxn = 33000;
int dp[65][maxn];
int V[65][3],W[65][3];

int main(int argc, char const *argv[])
{
    int n,m,v,p,q;
    cin >> n >> m;
    for(int i=1;i<=m;++i)
    {
        cin >> v >> p >> q;

        if(!q)
        {
            V[i][0] = v;
            W[i][0] = p;
        }
        else
        {
            if(!V[q][1])
            {
                V[q][1] = v;
                W[q][1] = p;
            }
            else
            {
                V[q][2] = v;
                W[q][2] = p;
            }
        }
    }

    for(int i = 1;i <= m;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            if(j-V[i][0] >= 0)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-V[i][0]]+V[i][0]*W[i][0]);

                if(j-V[i][0]-V[i][1] >= 0)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-V[i][0]-V[i][1]]+V[i][0]*W[i][0]+V[i][1]*W[i][1]);
                }
                
                if(j-V[i][0]-V[i][2] >= 0)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-V[i][0]-V[i][2]]+V[i][0]*W[i][0]+V[i][2]*W[i][2]);
                }

                if(j-V[i][0]-V[i][1]-V[i][2] >= 0)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-V[i][0]-V[i][1]-V[i][2]]+V[i][0]*W[i][0]+V[i][1]*W[i][1]+V[i][2]*W[i][2]);
                }
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[m][n];

    return 0;
}
