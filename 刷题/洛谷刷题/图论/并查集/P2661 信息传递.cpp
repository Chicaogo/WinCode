#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int fa[maxn],de[maxn],minn;

int fin(int x)
{
    if(fa[x] != x)
    {
        int qwq = fa[x];
        fa[x] = fin(fa[x]);
        de[x] += de[qwq];
    }
    return fa[x];
}

void code(int a,int b)
{
    int x = fin(a),y = fin(b);
    if(x != y) 
    {
        fa[x] = y;
        de[a] = de[b] + 1;
    }
    else minn = min(minn,de[a] + de[b] +1);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        int x;
        cin >> x;
        code(i,x);
    }
    cout << minn;
    return 0;
}
