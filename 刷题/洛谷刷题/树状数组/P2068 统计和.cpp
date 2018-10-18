#include<bits/stdc++.h>
using namespace std;

int C[1000100],N = 0,q = 0;

int lowbit(int x)
{
    return x & (-x);
}

void add(int x,int k)
{
    while(x<=N)
    {
        C[x]+=k;
        x+=lowbit(x);
    }
}

inline long long sum(int x)
{
    long long ans = 0;
    for(;x;x-=lowbit(x))
    {
        ans += C[x];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    cin >> N >> q;

    while(q--)
    {
        char qwq;
        cin >> qwq;
        if(qwq == 'x')
        {
            int x,y;
            cin >> x >> y;
            add(x,y);
        }
        if(qwq == 'y')
        {
            int x,y;
            cin >> x >> y;
            cout << sum(y) - sum(x-1) << endl;
        }
    }

    return 0;
}
