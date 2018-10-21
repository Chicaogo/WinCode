#include<bits/stdc++.h>
using namespace std;

int kk[10010],num[10010];
int k,m,n;

int main(int argc, char const *argv[])
{
    cin >> k >> m >> n;

    for(int i = 1;i <= n;++i)
    {
        int qwq;
        cin >> qwq;
        kk[qwq]++;
    }

    for(int i = 1;i <= m;++i)
    {
        int qwq;
        cin >> qwq;
        kk[qwq]--;
    }

    int ans = 0;

    for(int i = 1;i <= k;++i)
    {
        if(kk[i] > 0) ans+=kk[i];
    }
    
    cout << ans;

    return 0;
}
