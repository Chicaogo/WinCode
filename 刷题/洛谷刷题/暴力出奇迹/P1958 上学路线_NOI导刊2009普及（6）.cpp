#include<bits/stdc++.h>

inline int read()
{
	int x = 0,t = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*t;
}

void dfs(int x,int y);

int map[20][20];
int a,b,n,ans;

inline void init()
{
	a = read();
	b = read();
	
	for(int i = 1;i <= a;++i)
		map[i][b+1] = -1;
	for(int i = 1;i <= b;++i)
		map[a+1][i] = -1;
	
	n = read();
	
	for(int i = 1;i <= n;++i)
	{
		int x = read(),y = read();
		map[x][y] = -1;
	}
	
	dfs(1,1); 
}

void dfs(int x,int y)
{
	if(x==a && y==b)
	{
		ans++;
		return;
	}
	else
	{
		if(map[x][y] != -1)
		{
			dfs(x,y+1);
			dfs(x+1,y);
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false); 
	init();
	std::cout << ans;
	return 0;
}
