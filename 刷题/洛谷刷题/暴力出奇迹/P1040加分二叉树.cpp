#include<bits/stdc++.h>
using namespace std;
int a[31];
long long fa[31][31];
int root[31][31];
long long DP(int L,int R){
    int k;long long maxx;
    if(L > R) return 1;
    if(fa[L][R]==-1){
        for(k=L;k<=R;k++){
            maxx=DP(L,k-1)*DP(k+1,R)+a[k];
            if(maxx > fa[L][R]){
                fa[L][R] = maxx;
                root[L][R] = k;
            }
        }
    }
    return fa[L][R];
}
bool cnt=true;
void build(int L,int R){
    if(L > R) return; //±ß½ç
    if(cnt) cnt=false;
    else cout<<' ';
    cout << root[L][R];
    build(L,root[L][R]-1);
    build(root[L][R]+1,R);
}

int main(int argc, char const *argv[])
{
    int n,num;
    cin>>n;
    memset(fa,-1,sizeof(fa));
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        fa[i][i]=a[i];
        root[i][i]=i;
    }
    cout<<DP(1,n)<<endl;
    build(1,n);
    getchar();getchar();getchar();
    return 0;
}
