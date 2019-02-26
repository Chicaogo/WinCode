#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int num[110],c[110];

int main(void)
{
    cin >> n >> k;

    for(int i = 1;i <= n;++i)
    {
        int number;
        cin >> number;

        if(!num[number])
        {
            c[++ans] = i;
            num[number] = 1;
        }
    }

	if(ans >= k)
	{
		cout << "YES" << endl;
		for(int i = 1;i <= k;++i)
        	cout << c[i]  << " ";
	}
    else cout << "NO";

    return 0;
}