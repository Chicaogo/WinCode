#include<bits/stdc++.h>
using namespace std;

int N,n[300010];

int main(void)
{
    cin >> N;
    for(int i=1;i <= N;i++)
    {
        cin >> n[i];
    }
    sort(n+1,n+N+1);
    int maxx = 0;
    for(int i=1;i <= N;i++)
    {
        maxx = max(maxx , n[i]+i);
    }
    int ans = 0;
    for(int i=1;i <= N;i++)
    {
        if(n[i]+N >= maxx)
        {
            ans++;
        }
        else break;
    }

    cout << ans;

    return 0;
}