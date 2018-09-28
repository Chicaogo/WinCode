#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int fa[maxn],n,m;

struct edge
{
    int v,u,w;
    bool operator < (const edge &a)const{
        return w < a.w;
    }
}fuck[maxn];


inline int fin(int x){
    if(fa[x]==x) return fa[x];
    else return fa[x]=fin(fa[x]);
}
inline bool same(int x,int y){
    x=fin(x);y=fin(y);
    if(x==y)return true;
    else return false;
}
inline void get(int x,int y){
    x=fin(x);y=fin(y);
    fa[x]=y;
}

int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int  i = 0; i < m; i++)
    {
        cin>>fuck[i].u>>fuck[i].v>>fuck[i].w;
    }
    for(int i = 0; i < n;++i) fa[i]=i;
    sort(fuck,fuck+m);
    int ans=0,cnt=n;
    for(int i=0;i<m&&cnt>1;++i){
        int x=fuck[i].u,y=fuck[i].v;
        if(!same(x,y)){
            get(x,y);
            cnt--;
            ans=fuck[i].w;
        }
    }
    if(cnt==1) cout<<ans;
    else cout<<-1;
    getchar();getchar();
    return 0;
}
