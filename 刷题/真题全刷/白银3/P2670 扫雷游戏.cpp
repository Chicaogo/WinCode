#include<bits/stdc++.h>
using namespace std;

const int MAX = 110;
int n,m;
int g[MAX][MAX];

inline void init()
{
    cin >> n >> m;

    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
        {
            char qwq;
            cin >> qwq;

            if(qwq == '*')
                g[i][j] = 1;
        }
}

inline int find()
{
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            if(g[i][j] == 1)
                cout << '*';
            else
                cout << g[i-1][j] + g[i-1][j-1] + g[i-1][j+1] + g[i][j-1] + g[i][j+1] + g[i+1][j-1] + g[i+1][j] + g[i+1][j+1];
        }
        
        cout << endl;
    }
}

int main(void)
{
    init();

    find();

    return 0;
}