#include<bits/stdc++.h>
using namespace std;

int n;
string num[25];

bool cmp(string a,string b)
{
    return a+b > b+a;
}

int main(int argc, char const *argv[])
{
    cin >> n;

    for(int i=1;i<=n;++i) cin >> num[i];

    sort(num+1,num+n+1,cmp);

    for(int i=1;i<=n;++i) cout << num[i];

    getchar();getchar();getchar();
    return 0;
}
