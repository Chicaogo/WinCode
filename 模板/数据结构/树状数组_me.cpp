#include<bits/stdc++.h>
using namespace std;

int tree[500010],n,m;

inline int lowbit(int x)
{
    return x & (-x);
}

inline void add(int x,int k)
{
    while(x<=n)
    {
        tree[x]+=k;
        x+=lowbit(x);
    }
}

inline int sum(int x)
{
    int ans = 0;
    while(x!=0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for(int i = 1;i <= n;++i)
    {
        int x;
        cin >> x;
        add(i,x);
    }

    for(int i = 1;i <= m;++i)
    {
        int qwq = 23333;
        cin >> qwq;
        if(qwq == 1)
        {
            int x,k;
            cin >> x >> k;
            add(k,x);
        }
        if(qwq == 2)
        {
            int x,y;
            cin >> x >> y;
            cout << sum(y) - sum(x-1) << endl;
        }
    }

    return 0;
}
