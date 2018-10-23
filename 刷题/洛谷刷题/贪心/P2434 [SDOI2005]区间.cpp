#include<bits/stdc++.h>
using namespace std;

const int maxn  = 2333333;

struct node
{
    int l,r;
    bool operator < (const node &qwq)
    {
        return l < qwq.l;
    }
}a[maxn];
int n,num=0,ans=0;

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);

    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;

    sort(a+1,a+n+1);
    num=a[1].r;
    ans=a[1].l;

    for(int i=2;i<=n;i++)
    {
        if(num<a[i].l)
        {
            cout<<ans<<" "<<num<<endl;
            num=max(num,a[i].r);
            ans=a[i].l;
        }
        else num=max(num,a[i].r);
        
        if(i==n) cout<<ans<<" "<<num<<endl;
    }
    return 0;
}
