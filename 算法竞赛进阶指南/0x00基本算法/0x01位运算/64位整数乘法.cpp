#include<bits/stdc++.h>
using namespace std;

long long a,b,mod;

int main(void)
{
    cin >> a >> b >> mod;
    long long ans;
    while(b)
    {
        if(b&1) ans = (ans + a) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    cout << ans << endl;
    
    return 0;
}