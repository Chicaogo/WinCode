#include<bits/stdc++.h>
using namespace std;

int tong[5010],ans,n;

struct tree
{
    int l,w;
    bool operator < (const tree &qwq)
    {
        if(l == qwq.l) return w > qwq.w;
        return l > qwq.l;
    }
}num[5010];

inline void init()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> num[i].l >> num[i].w;

    sort(num+1,num+n+1);

    int cnt;
    for(int i = 1;i < n;++i)
    {
        cnt = num[i].w;
        if(tong[i]) continue;
        for(int j = i+1;j <= n;j++)
        {
            if(!tong[j] && cnt >= num[j].w)
            {
                tong[j] = 1;
                cnt = num[j].w;
            }
        }
    }

    for(int i = 1;i <= n;++i)
        if(!tong[i]) ans++;

    cout << ans;
}

int main(int argc, char const *argv[])
{
    init();
    return 0;
}
