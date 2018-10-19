#include<bits/stdc++.h>
using namespace std;

int n,m,a,k = 0,ans = 0;

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for(int i = 1;i <= m;++i)
    {
        cin >> a;
        if(a+k < m)
        {
            k += a;
        }
        else
        {
            ans++;
            k = a;
        }
    }
    
    cout << ans;

    return 0;
}
