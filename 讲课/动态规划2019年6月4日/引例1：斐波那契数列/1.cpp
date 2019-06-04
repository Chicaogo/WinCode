#include<bits/stdc++.h>
using namespace std;

int n;

long long dp(int i)
{
    if(i == 1 || i == 2) return 1;
    else return (dp(i-1) + dp(i-2));
}

int main(void)
{
    cin >> n;

    cout << dp(n) << endl;

    system("pause");
    return 0;
}