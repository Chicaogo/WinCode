#include<bits/stdc++.h>
using namespace std;

int n;

void init()
{
    cin >> n;
}

void find()
{
    for(int i = 2;i <= n;++i)
    {
        if(n % i == 0)
        {
            cout << n / i;
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();

    find();

    getchar();getchar();getchar();
    return 0;
}
