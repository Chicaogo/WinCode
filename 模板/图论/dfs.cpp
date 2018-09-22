#include<bits/stdc++.h>
using namespace std;
vector<int> G[100086];
inline read(){
    int x=0,t;char c;
    c=getchar();
    do{if(c == '-')t=-1;c=getchar();} while (c<'0'||c>'9');
    do{x=x*10+c-'0';c=getchar();}while(c>='0'&&c<='9');
    return 0;
}
inline void addedge(int u,int v){
    G[u].push_back(v);G[v].push_back(u);
}
int vis[100086];
int dfs(int u){
    cout << u << ends;
    vis[u]=1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v=G[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(int argc, char const *argv[])
{
    memset(vis,0,sizeof(vis));
    int n;
    cin>> n;
    for(int i = 0; i < n-1 ; i++){
        int u , v;
        cin >> u >> v;
        addedge(u,v);
    }
    dfs(1);
    getchar(); getchar(); getchar(); getchar();
    return 0;
}