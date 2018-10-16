//https://www.luogu.org/problemnew/show/P1003
#include<bits/stdc++.h>
using namespace std;

int mapp[10010][5];
int n,x,y;

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        int a,b;
        cin >> mapp[i][1] >> mapp[i][2] >> a >> b;
        mapp[i][3] = mapp[i][1] + a;
        mapp[i][4] = mapp[i][2] + b;
    }

    cin >> x >> y;
    
    do
    {
        if(mapp[n][1] <= x && x <= mapp[n][3] && mapp[n][2] <= y && y <= mapp[n][4])
        {
            cout << n ;
            break;
        }
        if(n == 1)
        {
            cout << "-1";
            break;
        }
    } while (n--);
    
    return 0;
}

//100f