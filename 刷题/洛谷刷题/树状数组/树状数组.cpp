#include<bits/stdc++.h>
using namespace std;

int C[100010],N,q;

int lowbit(int x)
{
    return x & (-x);
}

inline void add(int x,int y)
{
    for(;x <= N;x+=lowbit(x))
    {
        C[x]+=y;
    }
}

inline long long sum(int x)
{
    long long ans;
    for(;x;x-=lowbit(x))
    {
        ans += C[x];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> N >> q;

    for(int i = 1;i <= N;++i)
    {
        int x;
        cin >> x;
        add(i,x);
    }

    while(q--)
    {
        int qwq;
        cin >> qwq;
        if(qwq == 1)
        {
            int x,y;
            cin >> x >> y;
            add(x,y);
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
