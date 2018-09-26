#include<bits/stdc++.h>
int vis[10086],a[10086];
void dfs(int now,int n){
    if(now == n+1){
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        a[now]=i;
        dfs(now+1,n);
        vis[i]=0;
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;
    dfs(1,n);
    //scanf("%d",&n);
    getchar();
    return 0;
}
