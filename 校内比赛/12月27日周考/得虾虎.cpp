#include<bits/stdc++.h>
using namespace std; 

long long n,x,d,l,ans;

void init()
{
	cin >> n >> x >> d;
	l = -1 * (x + d);
}

void find()
{
	for(int i = 1;i <= n;i++)
	{
		long long zzm;
		cin >> zzm;
		if(zzm >= l) ans++;
	}
	
	cout << ans;
}

int main(void)
{
	init();
	
	find();
	
	return 0;
}
