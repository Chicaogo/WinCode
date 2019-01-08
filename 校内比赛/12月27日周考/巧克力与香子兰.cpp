#include<bits/stdc++.h>
using namespace std; 

string s;
int num[1000],maxn,minn;

void init()
{
	cin >> s;
}

void find()
{
	for(int i = 0;i < s.length();i++)
		num[(int)s[i]] ++;
	
	maxn = max(max(num['c'],num['a']),num['t']);
	minn = min(min(num['c'],num['a']),num['t']);
	
	cout << minn << " " << maxn - num['c'] << " " << maxn - num['a'] << " " << maxn - num['t'];
}

int main(void)
{
	init();
	
	find();
	
	return 0;
}
