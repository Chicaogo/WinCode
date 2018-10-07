#include <bits/stdc++.h>
using namespace std;

const int MAXN=100;
const int MAXW=1000;

int dp[MAXN][MAXW];
int w[MAXN],v[MAXN];
int n,W;

int res(int i,int j){
    int ans;
    if(dp[i][j]>=0) 
    {
        //cout<< dp[i][j] << ends;
        return dp[i][j];
    }
    if(i == n) ans = 0;
    else if(j < w[i]) res(i+1,j);
    else ans = max(res(i+1,j),res(i+1,j-w[i])+v[i]);
    dp[i][j] = ans;
    //cout<< dp[i][j] << ends;
    return dp[i][j];
}

int main(int argc, char const *argv[])
{
    memset(dp,-1,sizeof(dp));
    cin>> n >> W;

    for(int i=0;i<n;++i) cin >> w[i] >> v[i];

    cout << res(0,W) <<endl;
    
    getchar();getchar();getchar();
    return 0;
}
/*
4 5
2 3
1 2
3 4
2 2

7
*/