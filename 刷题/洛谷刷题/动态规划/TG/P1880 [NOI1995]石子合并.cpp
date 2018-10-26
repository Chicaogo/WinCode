#include<bits/stdc++.h>
using namespace std;

const int maxn = 10100;
int dp1[maxn][maxn],dp2[maxn][maxn],a[maxn],sum[maxn];
int n;

inline void init()
{
    cin >> n;
    for(int i=1; i<=n*2; i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
        sum[i]=sum[i-1]+a[i];
    }
}

inline void DP()
{
    for(int l=1; l<=n; l++)
    {
        for(int i=1; i+l<=n; i++)
        {
            int j=i+l;
            dp1[i][j]= 1<<30;
            for(int k=i; k<=j; k++)
            {    
                dp1[i][j]=min(dp1[i][j],dp1[i][k-1]+dp1[k][j]+sum[j]-sum[i-1]);
                dp2[i][j]=max(dp2[i][j],dp2[i][k-1]+dp2[k][j]+sum[j]-sum[i-1]);
            }
        }
    }
    printf("%d\n%d",dp1[1][n],dp2[1][n]);
}

int main(int argc, char const *argv[])
{
    init();
    DP();
    return 0;
}
