#include<bits/stdc++.h>
using namespace std;

int num[23333333];
int n,ans = 0,p = 0;

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> num[i];
        p+=num[i];
    }
    p/=n;
    for(int i = 1;i <= n;++i)
        num[i]-=p;
    for(int i = 1;i <= n;++i)
    {
        if(num[i]!=0)
        {
            num[i+1] += num[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}
