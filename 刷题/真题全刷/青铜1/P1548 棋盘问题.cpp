#include<bits/stdc++.h>
using namespace std;

int n, m;
int zf = 0, cf = 0; 

void init()
{
    cin >> n >> m;
}

void find()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int l1 = i + 1; l1 <= n; l1++)
                for (int l2 = j + 1; l2 <= m; l2++)
                {
                    int ll1 = l1 - i;
                    int ll2 = l2 - j;
                    if (ll1 > 0 && ll2 > 0)
                    {
                        if (ll1 == ll2) zf++;
                        else cf++;
                    }
                }
    cout << zf << " " << cf << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    find();

    return 0;
}
