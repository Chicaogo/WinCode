#include<bits/stdc++.h>
using namespace std;

struct edge{
    int x,y,w;
    bool operator <(const edge &qaq)
    {
        return w > qaq.w;
    }
}num[100010];

int n,m;
int fa[20010],wa[20010];

inline int fin(int x)
{
    return fa[x]==x ? x : fa[x] = fin(fa[x]);
} 

inline bool qwq(int x,int y)
{
    return fin(x) == fin(y) ? true : false;
}

inline void add(int x,int y)
{
    x = fin(fa[x]); y = fin(fa[y]);
    fa[x] = y;
}

inline void init()
{
    cin >> n >> m;

    for(int i = 1;i <= n;++i) fa[i] = i;

    for(int i = 1;i <= m;++i) 
        cin >> num[i].x >> num[i].y >> num[i].w;

    sort(num+1,num+m+1);

    for(int i = 1;i <= m;++i)
    {
        if(qwq(num[i].x,num[i].y))
        {
            cout << num[i].w << endl;
            break;
        }

        if(!wa[num[i].x]) wa[num[i].x] = num[i].y;
        else add(wa[num[i].x] , num[i].y);

        if(!wa[num[i].y]) wa[num[i].y] = num[i].x;
        else add(wa[num[i].y] , num[i].x);
    }
}

int main(int argc, char const *argv[])
{
    init();
    return 0;
}