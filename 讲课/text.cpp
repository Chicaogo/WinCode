#include<bits/stdc++.h>
using namespace std;

int n,m;
int zzm[1000][1000];

void init()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin >> zzm[i][j];
        }
    }
}

void find()
{
    cout << endl;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cout << zzm[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    init();

    find();

    getchar();getchar();getchar();getchar();
    return 0;
}