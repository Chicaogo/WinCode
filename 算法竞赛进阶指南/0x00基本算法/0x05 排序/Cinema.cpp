#include<bits/stdc++.h>
using namespace std;

const int MAX = 200010;
int n,mm;
unordered_map<int, int> m;

struct node {
    int pos,lan,sub;
    bool operator <(const node &num) const
    {
        if(lan == num.lan) return sub > num.sub;
        else return lan > num.lan;
    }
}a[MAX];

inline void init()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        int x;
        cin >> x;
        m[x]++;
    }

    cin >> mm;
    for(int i = 1;i <= mm;++i)
    {
        int x;
        cin >> x;
        a[i].pos = i;
        a[i].lan = m[x];
    }

    for(int i = 1;i <= mm;++i)
    {
        int x;
        cin >> x;
        a[i].sub = m[x];
    }
}

inline void find()
{
    sort(a+1,a+mm+1);
    cout << a[1].pos;
}

int main(void)
{
    init();

    find();

    system("pause");
    return 0;
}