#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int num[110],c[110],tong[110];

int main(void)
{
    cin >> n >> k;

    for(int i = 1;i <= n;++i)
    {
        int number;
        cin >> number;

        if(!num[number])
        {
            c[ans++] = i;
            num[number] = 1;
        }
    }

    cout << ans;

    for(int i = 1;i <= ans;++i)
        cout << c[i];

    return 0;
}