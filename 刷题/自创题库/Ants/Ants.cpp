#include<bits/stdc++.h>
using namespace std;

const int maxx = 1e6+1;
int L,n;
int x[maxx];
int maxT,minT;

inline void solve()
{
    for(int i=0;i<n;++i)
    {
        minT=max(minT,min(x[i],L-x[i]));    
    }
    
    for(int i=0;i<n;++i)
    {
        maxT=max(maxT,max(x[i],L-x[i]));
    }
} 

int main(int argc, char const *argv[])
{
    cin>>L>>n;
    
    for(int i=0;i<n;++i)
    {
        cin>>x[i];
    }

    solve();
    
    cout<<minT<<" "<<maxT;

    getchar();getchar();getchar();
    return 0;
}
