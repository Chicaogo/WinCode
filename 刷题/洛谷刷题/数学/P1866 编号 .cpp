#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0,t = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*t;
}

const int mod = 1000000007;
int n,i,num[51];
long long ans=1;

inline void init()
{
	n = read();
	
	for(int i = 1;i <= n;++i) num[i] = read();
	
	std::sort(num+1,num+n+1);
	
	for(int i = 1;i <= n;++i)
	{
		ans*=(num[i]-i+1);
		ans%=mod;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); 

	init();
	
	cout << ans;

	return 0;
}
