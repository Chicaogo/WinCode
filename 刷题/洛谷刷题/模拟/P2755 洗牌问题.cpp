#include<bits/stdc++.h>
using namespace std;

int n,m;

void init()
{
	cin >> n;
	
	if(n == 0)
	{
		cout << 1;
		return;
	}
	
	int ans = 0;
	
	for(int i = 2;i != 1;ans++)
	{
		if(i > n) i = 2*(i - n) - 1;
		else i *= 2;
	}
	
	cout << ans+1;
}

void find()
{

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    find();

    return 0;
}
