#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int num[maxn];

inline void init()
{
    int n = 0;
    cin >> n;

    for(int i = 1;i <= n;++i)
        cin >> num[i];
    
    for(int i = n;i > 1;--i)
        num[i] -= num[i-1];
}

inline void frond()
{
    long long pos = 0,neg = 0;
    for(int i = 2;i <= n;++i)
    {
        if(a[i] > 0) pos += a[i];
        else neg -= a[i];
    }

    cout << min(pos,neg) + abs(pos - neg) << endl << abs(pos - neg) + 1;
}

int main(void)
{
    init();

    frond();

    return 0;
}