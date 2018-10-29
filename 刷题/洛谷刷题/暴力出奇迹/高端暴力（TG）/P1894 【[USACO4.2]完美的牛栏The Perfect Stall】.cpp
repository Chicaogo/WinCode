#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const int maxm = 10010;
int n,m,tong[maxm],ans;
bool vis[maxn],love[maxn][maxm];

inline int read(){
    int k=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
    return k*f;
}

inline void init()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int l=read();
        while(l--){
            love[i][read()]=true;
        }
    }
}

bool dfs(int x)
{
    for(int i = 1;i <= m;++i)
    {
        if(!vis[i] && love[x][i])
        {
            vis[i] = true;
            if(tong[i]==0 || dfs(tong[i]))
            {
                tong[i] = x;
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    init();
    
    for(int i = 1;i <= n;++i)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }

    cout << ans;

    return 0;
}
