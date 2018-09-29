//https://www.luogu.org/problemnew/show/P2330
#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxm=100010;
int fa[maxn],n,m;
struct edge{
    int u,v,w;
    bool operator < (const edge &a)const{
        return w < a.w;
    }
}num[maxn];
int fin(int qwq){
    return fa[qwq]==qwq?qwq:fa[qwq]=fin(fa[qwq]);
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>num[i].u>>num[i].v>>num[i].w;
    for(int i=1;i<n;i++) fa[i]=i;
    sort(num,num+m);
    int ans=0,s;
    for(int i=0;i<m;i++){
        int x=fin(num[i].u),y=fin(num[i].v);
        if(x!=y){
            ans=num[i].w;
            fa[x]=y;
        }
    }
    cout<<n-1<<" "<<ans;
    getchar();getchar();getchar();getchar();
    return 0;
}
