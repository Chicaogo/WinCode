#include<bits/stdc++.h>
using namespace std;
const int BIG = 666666;
int n,m,x,y,tot;
int rxzha[BIG],las[BIG],to[BIG],nxt[BIG];

inline void dfs(int now,int st){
    if(rxzha[now])
        return;
    rxzha[now]=st;
    for(int e=las[now];e;e=nxt[e])
        if(!rxzha[to[e]])
            dfs(to[e],st);
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&y,&x);
        nxt[++tot]=las[x];
        las[x]=tot;
        to[tot]=y;
    }
    for(int i=n;i;--i)
        dfs(i,i);
    for(int i=1;i<=n;++i)
        printf("%d ",rxzha[i]);
    return 0;
}