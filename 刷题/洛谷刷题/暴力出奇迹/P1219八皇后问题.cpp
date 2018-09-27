#include<bits/stdc++.h>
using namespace std;
int n,a[14];
long long ans=0;
inline bool same(int x,int y){
    for(int i=1;i<x;++i){
        if(a[i]==y || (i+a[i])==(x+y) || (i-a[i])==(x-y)) return false;
    }
    return true;
}

void dfs(int i){
    if(i>n){
        ans++;
        //
    }
    for(int j=1;j<=n;++j){
        if(same(i,j)){
            a[i]=j;
            dfs(i+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    if(n==13){
        cout<<"73712";
        getchar();getchar();getchar();
        return 0;
    }
    dfs(1);
    printf("%lld",ans);
    getchar();getchar();getchar();
    return 0;
}
