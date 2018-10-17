#include<bits/stdc++.h>
using namespace std;

long long ans,n,s,c,y,qwq;

int main(int argc, char const *argv[])
{
    cin >> n >> s;

    for(int i = 1;i <= n;++i)
    {
        cin >> c >> y;
        if(i == 1) qwq = c;
        else qwq = min(qwq + s,c);
        ans += qwq*y;
    }

    cout << ans;
    return 0;
}
