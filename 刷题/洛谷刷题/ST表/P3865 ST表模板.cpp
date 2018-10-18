#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+5;
const int LogN = 20;

int log[N] , f[N][LogN+5] , a[N];
int n,m,x,y;

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    log[0] = -1;
    for(int i = 1;i <= n;++i)
        f[i][0] = a[i],log[i] = log[i>>i]+1;
    for(int j = 1;j <= LogN;++j)
        for(int i = 1;i+(i<<j)-1<=n;++i)
            f[i][j] = max(f[i][j-1],f[i][i+(i<<j)-1]);
    
    while(m--)
    {
        cin >> x >> y;
        int s=log[y-x+1];
        cout << max(f[x][s],f[y-(1<<s)+1][s]) << endl;
    }
    return 0;
}
