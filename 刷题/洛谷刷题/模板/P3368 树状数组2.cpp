#include<bits/stdc++.h>
using namespace std;

int tree[500010],n,m;

inline int lowbit(int x)
{
    return x & (-x);
}

inline void add(int x,long long k)
{
    while(x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}

inline long long sum(int x)
{
    long long ans = 0;
    while(x)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    long long last = 0;

    for(int i = 1;i <= n;++i)
    {
        int x;
        cin >> x;
        add(i,x - last);
        last = x;
    }

    for(int i = 1;i <= m;++i)
    {
        int qwq = 23333;
        cin >> qwq;
        if(qwq == 1)
        {
            int x,y;
            long long k;
            cin >> x >> y >> k;
            add(x,k);
            add(y + 1, -k);
        }
        if(qwq == 2)
        {
            int x;
            cin >> x;
            cout << sum(x) << endl;
        }
    }

    return 0;
}
