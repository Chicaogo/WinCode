#include<bits/stdc++.h>
using namespace std;

int num[5010][5010];
int n,r,maxx,maxy,ans;

inline int read()
{
    int x = 0,t = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') t = -1;ch = getchar();}
    while(ch >= '0' && ch <='9'){x= x*10 + ch - '0'; ch = getchar();}
    return x*t;
}

inline void init()
{
    n = read(); r = read();
    for(int i = 1;i <= n;++i)
    {
        int x = read(),y = read(),w= read();
        num[x+1][y+1] = w;
        maxx = max(maxx,x); maxy = max(maxy,y);
    }

    for(int i = 1;i <= maxx;++i)
    {
        for(int j = 1;j <= maxy;++j)
        {
            num[i][j] += num[i-1][j] + num[i][j-1] - num[i-1][j-1];
        }
    }
}

inline void DP()
{
    for(int i = r;i <= maxx;++i)
    {
        for(int j = r;j <= maxy;++j)
        {
            ans = max(ans,num[i][j] - num[i-r][j] - num[i][j-r] + num[i-r][j-r]);
        }
    }

    printf("%d",ans);

}

int main(int argc, char const *argv[])
{
    init();
    DP();
    return 0;
}