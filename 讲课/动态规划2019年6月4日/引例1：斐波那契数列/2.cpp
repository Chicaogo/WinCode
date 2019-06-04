#include<bits/stdc++.h>
using namespace std;

int n;
long long f[1001];

long long dp(int i)
{
    if(f[i]) return f[i];
    else if(i == 1 || i == 2) return 1;
    else return f[i] = (dp(i-1) + dp(i-2));
}

int main(void)
{
    cin >> n;

    cout << dp(n) << endl;

    system("pause");
    return 0;
}