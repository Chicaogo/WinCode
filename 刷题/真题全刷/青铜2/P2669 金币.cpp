#include<bits/stdc++.h>
using namespace std;

int k,n; 
long long ans;

void init()
{
	cin >> k;
}

void find()
{
	for(int i = 1;i <= k;++i)
	{
		for(int j = 1;j <= i;++j)
		{
			ans += i;
			n++;
			
			if(n >= k) break;
		}
		if(n >= k) break;
	}
	
	cout << ans;
}

int main(int argc, char const *argv[])
{
    init();

    find();
    
    return 0;
}
