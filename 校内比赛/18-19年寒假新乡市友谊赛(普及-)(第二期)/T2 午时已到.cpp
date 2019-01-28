#include<bits/stdc++.h>
using namespace std;

int k,n;

void init()
{
    cin >> k >> n;
}

void find()
{
	if(__gcd(k,n) == 1) cout << k*n;
    else cout << __gcd(k,n);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    find();

    return 0;
}
