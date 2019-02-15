#include<bits/stdc++.h>
using namespace std;

long long N,M;

int main(void)
{
    cin >> N >> M;

    int ans = N / M;
    int n = N % M;

    for(int i = 1;i <= M-n;++i)
        cout << ans << " ";
    
    for(int i = 1;i <= n;++i)
        cout << ans + 1 << " ";
    
    return 0;
}