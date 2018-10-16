//https://www.luogu.org/problemnew/show/P1311
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct qwq{
    int col , ww;
}num[1000000];

int main(int argc, char const *argv[])
{
    int n,k,p;
    cin >> n >> k >> p;
    for(int i = 0;i < n;++i)
    {
        cin >> num[i].col >> num[i].ww;
    }
    int minn = inf,ans = 0;
    for(int i = 0;i < n-1;++i)
    {
        minn = min(minn,num[i].ww);
        for(int j = i+1;j < n;++j)
        {
            minn = min(minn,num[j].ww);
            if(minn < p && num[i].col == num[j].col) ans++;
        }
        minn = inf;
    }

    cout << ans;

    return 0;
}

//40f