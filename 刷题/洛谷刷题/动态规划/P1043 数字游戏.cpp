#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,s[102],dp1[102][102][10],h,ans=1e9,c[102],dp2[102][102][10],Max;

inline void init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {scanf("%d",&s[i]);s[n+i]=s[i];}
    for (int i=1;i<=n*2;i++)
    c[i]=c[i-1]+s[i];
}

inline void dp_first()
{
    for (int i=1;i<=n*2;i++)
        for (int j=i;j<=n*2;j++)
            for (int k=1;k<=m;k++)
            if (k<2)
            {
                dp2[i][j][k]=((dp2[i][j-1][k]+s[j])%10+10)%10;
                dp1[i][j][k]=((dp1[i][j-1][k]+s[j])%10+10)%10;
            }
            else dp1[i][j][k]=1e9;
}

inline void dp_second()
{
    for (int i=2;i<=m;i++)
        for (int j=1;j<=n*2;j++)
            for (int k=i+j-1;k<=n*2;k++)
                for (int l=i+j-1;l<=k;l++)
                {
                    dp1[j][k][i]=min(dp1[j][k][i],dp1[j][l-1][i-1]*(((c[k]-c[l-1])%10+10)%10));
                    dp2[j][k][i]=max(dp2[j][k][i],dp2[j][l-1][i-1]*(((c[k]-c[l-1])%10+10)%10));
                }
}

inline void out_qwq()
{
    for (int i=1;i<=n;i++)
    {
        ans=min(ans,dp1[i][n+i-1][m]);
        Max=max(Max,dp2[i][n+i-1][m]);
    }
    printf("%d\n%d",ans,Max);
}

int main(void)
{
    init();
    dp_first();
    dp_second();
    out_qwq();
    return 0;
}