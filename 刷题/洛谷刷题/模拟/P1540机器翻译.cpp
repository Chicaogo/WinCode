#include<bits/stdc++.h>
using namespace std;
    int first[1010],lists[1010];
    int n,m,ans=0;
    int l=0,r=0,x;
int main(int argc, char const *argv[])
{
    cin>>m>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(first[x]==0){
            ans++;
            r++;
            lists[r]=x;
            first[x]=1;
            if(r>m){
                l++;
                first[lists[l]]=0;
            }
        }
    }
    cout<<ans;
    getchar(); getchar(); getchar();
    return 0;
}
