#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int fa[maxn],n,m;

struct edge
{
    int v,u,w;
    bool operator < (const edge a)const{
        return w < a.w;
    }
}fuck[maxn];


inline int fin(int x){
    if(fa[x]==x) return x;
    else return fa[x]=fin(fa[x]);
}
inline bool same(int x,int y){
    x=fin(x);y=fin(y);
    return x==y;
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
        cin>>fuck[i].v>>fuck[i].u>>fuck[i].w;
    }
    for(int i = 0; i < n;++i) fa[i]=i;
    sort(fuck,fuck+n);
    int ans=0,cnt=n;
    for(int i=0;i<m&&cnt>1;++i){
        int x=fuck[i].u,y=fuck[i].v;
        if(!same(x,y)){
            get(x,y);
            ans=fuck[i].w;
        }
    }
    cout<<ans;
    getchar();getchar();
    return 0;
}
