#include<bits/stdc++.h>
using namespace std;
const long long inf = 2147483647;
int n,m;
int a[110],b[110];
int s[11111111];
int main(void)
{
    cin >> n >> m;
    for(int i = 1;i <=n;i++)
    {
        cin >> a[i];
    }

    s[0] = 1;

    for(int i = 1;i <= m;i++)
    {
        int min = inf;
        for(int j = 1;j <=n;j++)
        {
            while(a[j]*s[b[j]]<=s[i-1]) b[j]++;
            if(a[j]*s[b[j]] < min) min = a[j]*s[b[j]];
        }
        s[i]=min;
    }

    cout << s[m] << endl;

    return 0;
}