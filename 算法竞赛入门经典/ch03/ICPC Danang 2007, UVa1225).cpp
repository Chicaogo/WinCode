#include<bits/stdc++.h>
using namespace std;

int n;

inline int find(int a)
{
    int num[10];
    memset(num,0,sizeof(num));

	for(int i = 1;i <= a;++i)
	{
		char s[100010];
		sprintf(s,"%d",i);
		
		for(int i = 0;i < strlen(s);++i)
	    {
	        int number = s[i] - '0';
	        num[number]++;
	    }

	}

    for(int i = 0;i < 10;++i)
        cout << num[i] << " ";
    
    cout << endl;
}

int main(void)
{
    cin >> n;

    while(n--)
    {
        int a;
        cin >> a;

        find(a);
    }

    return 0;
}