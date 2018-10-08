#include<bits/stdc++.h>
using namespace std;

int len;
int n,num[5210];
int maxn,minn;

inline void solow()
{
    for(int i=1;i<=n;i++)
    {
        maxn = max(maxn , max(len - num[i],num[i]));
        minn = max(minn , min(len - num[i],num[i]));
    }
}

int main(int argc, char const *argv[])
{
    cin >> len >> n;

    for(int i=1;i<=n;i++) cin >> num[i];

    solow();

    cout << minn+1 << " " << maxn+1;

    return 0;
}
