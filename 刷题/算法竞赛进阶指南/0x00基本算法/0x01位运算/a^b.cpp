#include<bits/stdc++.h>
using namespace std;

int a,b,mod;

int main(void)
{
    cin >> a >> b >> mod;

    int res = 1 % mod;

    while(b)
    {
        if(b&1) res = 1ll * res * a % mod;
        
        a = 1ll * a * a % mod;
        b >>= 1;
    }

    cout << res;
    return 0;
}