#include<bits/stdc++.h>
using namespace std;

int n;

inline bool check(int T,int len,string s)
{
    for(int i = 0;i+T < len;++i)
    {
        if(s[i] != s[i+T])
            return false;
    }

    return true;
}

inline int find(string s)
{
    int ans;

    for(int T = 1;T < s.length();++T)
    {
        if(s.length()%T == 0 && check(T,s.length(),s))
        {
            ans = T;
            break;
        }
    }

    return ans;
}

int main(void)
{
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        cout << find(s) << endl;
		if(n) cout << endl;
    }

    return 0;
}