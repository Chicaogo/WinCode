//https://www.luogu.org/problemnew/show/P1551
#include<bits/stdc++.h>
using namespace std;

int fa[5010];

int fin(int n){
    return fa[n]==n?n:fa[n]=fin(fa[n]);
}

int main(int argc, char const *argv[])
{
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i){
        int j,k;
        cin>>j>>k;
        if(fin(j)!=fin(k)){
            fa[fin(j)]=fin(k);
        }
    }
    while(p){
        int a,b;
        cin>>a>>b;
        if(fin(a)==fin(b)) printf("Yes\n");
        else printf("No\n");
        p--;
    }
    getchar();getchar();getchar();
    return 0;
}
