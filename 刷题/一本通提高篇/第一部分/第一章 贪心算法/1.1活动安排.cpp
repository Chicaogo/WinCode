//https://www.luogu.org/problemnew/show/U48369

#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0,t = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x*10 + ch - '0'; ch = getchar();}
    return x*t;
}

struct edge{
    int l,r;
    bool operator < (const edge &a) const{
        return r < a.r;
    }
}num[1005];

int n,ans;

inline void init()
{
    n = read();
    for(int i = 1;i <= n;++i) 
    {
        num[i].l = read();
        num[i].r = read();
    }
}

inline void greed()
{
    sort(num+1,num+n+1);
    int cnt = num[1].r;

    for(int i = 2;i <= n;++i)
    {
        if(num[i].l >= cnt)
        {
            ans++;
            cnt = num[i].r;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    greed();

    ++ans;
    cout << ans;
    
    getchar();getchar();getchar();
    return 0;
}