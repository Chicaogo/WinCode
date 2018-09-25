#include<bits/stdc++.h>
using namespace std;
int fa[10086];
int fin(int n){
    if(fa[n] == n) return n;
    else return fa[n] = fin(fa[n]);
}
bool same(int x,int y){
    x = fin(x);y = fin(y);
    if(x == y) return 1;
    else return 0;
}
int main(int argc, char const *argv[])
{
    int n,m,c,b,a;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&c,&a,&b);
        if(c == 1) fa[fin(a)] = fin(b);
        else{
            if(same(a,b)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
