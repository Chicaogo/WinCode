#include<bits/stdc++.h>
using namespace std;

int a,b,n,m;
long long dp[21][21];
bool wahaha[21][21];

inline void gun(int x,int y)
{
    if(0<=x && x<=n && 0<=y && y<=m) 
        wahaha[x][y] = 1;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m >> a >> b;

    gun(a,b);
    gun(a+1,b+2);gun(a-1,b+2);
    gun(a-1,b-2);gun(a+1,b-2);
    gun(a+2,b+1);gun(a-2,b+1);
    gun(a-2,b-1);gun(a+2,b-1);

    if(wahaha[0][0] == 0) dp[0][0]=1;

    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            if(wahaha[i][j]) continue;
            if(i>0) dp[i][j] += dp[i-1][j];
            if(j>0) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[n][m] <<endl;
    
    return 0;
}
