#include<bits/stdc++.h>
using namespace std;

int n = 0;

struct edge{
    int t,s;
    bool operator < (const edge &qxq)
    {
        return s > qxq.s;
    }
}num[1010];

int main(int argc, char const *argv[])
{
    cin >> n;

    for(int i = 1;i <= n;i++)
    {
        cin >> num[i].t >> num[i].s;
    }

    sort(num+1,num+n+1);

    int ans = num[1].s;
    for(int i = 1;i <= n;i++)
    {
        if(ans <= num[i].s) ans -= num[i].t;
        else ans = num[i].s - num[i].t;
    }

    if(ans < 0) cout << "-1";

    else cout << ans;
    
    return 0;
}
