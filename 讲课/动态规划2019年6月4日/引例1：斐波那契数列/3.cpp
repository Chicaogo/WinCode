#include<bits/stdc++.h>
using namespace std;

int n;
long long f[10010];

int main(void)
{
    cin >> n;

    f[1] = f[2] = 1;

    for(int i = 3;i <= n;++i)
        f[i] = f[i-1] + f[i-2];
    
    cout << f[n] << endl;

    system("pause");
    return 0;
}