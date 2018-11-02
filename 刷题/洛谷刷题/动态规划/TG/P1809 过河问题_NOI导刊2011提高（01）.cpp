#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0,t = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*t;
}

int num[100010],dp[100010];
int n;

inline void init()
{
	n = read();
	
	for(int i = 1;i <= n;++i)
		num[i] = read();
}

inline void DP()
{		
	std::sort(num+1,num+n+1);

	dp[1] = num[1];
	dp[2] = num[2];
	
	for(int i = 3;i <= n;++i)
		dp[i] = min(dp[i-1] + num[1] + num[i],dp[i-2] + num[1] + num[2]*2 +num[i]);
		
	std::cout << dp[n];

}

int main(void)
{
	init();
	DP();
	return 0;
}
