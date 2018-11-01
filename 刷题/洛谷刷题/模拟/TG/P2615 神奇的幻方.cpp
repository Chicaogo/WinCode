#include<bits/stdc++.h>

int n,map[100][100];
int x,y,qwq = 1;

inline void init()
{
	std::cin >> n;
    while (qwq <= n * n) {
        if (qwq == 1) 
            map[x = 1][y = n / 2 + 1] = qwq++;
        else if (x == 1 && y != n) 
            map[x = n][++y] = qwq++;
        else if (x != 1 && y == n) 
            map[--x][y = 1] = qwq++;
        else if (x == 1 && y == n) 
            map[++x][y] = qwq++;
        else if (x != 1 && y != n)
            if (map[x - 1][y + 1] == 0)
                map[--x][++y] = qwq++;
            else
                map[++x][y] = qwq++;
    }
    for (int i = 1; i <= n; ++i)
	{
        for (int j = 1; j <= n; ++j)
            std::cout << map[i][j] << " ";
        std::cout << std::endl;
	}
}

int main(void)
{
	init();
	return 0;
} 