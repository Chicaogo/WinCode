#include<bits/stdc++.h>
using namespace std;

int n;

inline int find(string s)
{
    int ans = 0,date = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'O') 
        {
            date++;
            ans += date;
        }
        else
        {
            date = 0;
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
        cout << find(s);
    }

    return 0;
}