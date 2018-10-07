//https://www.luogu.org/problemnew/show/P1049
#include<bits/stdc++.h>
using namespace std;

const int MAXV = 20001;
int n,V,dp[MAXV],v[31];

int main(int argc, char const *argv[])
{
    cin >> V >> n;
    
    for(int i = 0;i < n;++i) cin >> v[i];

    for(int i = 0;i < n;++i)
    {
        for(int j = V;j >= v[i];j--)
        {
            if(dp[j] < dp[j-v[i]]+v[i])
                dp[j] = dp[j-v[i]]+v[i];
        }
    }

    cout << V-dp[V];

    getchar();getchar();
    return 0;
}
