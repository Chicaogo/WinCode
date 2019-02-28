#include<bits/stdc++.h>
using namespace std;

string ss;
stack<char> s;

inline void init()
{
    cin >> ss;
}

inline long long find()
{
    long long ans = 1;

    for(int i = 0;i < ss.size();++i)
    {
        if(ss[i] == '(')
            s.push('(');

        if(ss[i] == ')')
        {
            int len = s.size();
            ans *= len;
            s.pop();
        }
	}

    return ans;
}

int main(void)
{
    init();

    cout << find() ;

    return 0;
}