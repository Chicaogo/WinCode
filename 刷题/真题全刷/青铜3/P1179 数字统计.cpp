#include<bits/stdc++.h>
using namespace std;

int ans;
int l,r;

void init()
{
    cin >> l >> r;
}

void find()
{
    for(int i = l;i <= r;++i)
    {
        int n = i;

        while(n != 0)
        {
            if(n % 10 == 2) ans ++;
            n /= 10;
        }
    }

    cout << ans;
}

int main(int argc, char const *argv[])
{
    init();

    find();

    getchar();getchar();getchar();
    return 0;
}
