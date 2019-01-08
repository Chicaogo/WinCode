#include<bits/stdc++.h>
using namespace std; 

long long l,r;
double minn = 0x7fffffff;

void init()
{
	cin >> l >> r;
	
	for(int i = l;i <= r;++i)
	{
		double ans = 1.0*i + 1.0/i;
		minn = min(minn,ans);
	}
}

void find()
{
	printf("%0.1lf",minn);
}

int main(void)
{
	init();
	
	find();
	
	return 0;
}
