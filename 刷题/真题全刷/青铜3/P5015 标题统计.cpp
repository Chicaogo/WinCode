#include<bits/stdc++.h>
using namespace std;

int ans;
string s;

void init()
{
    getline(cin,s);
}

void find()
{
    for(int i = 0;i < s.length();++i)
    {
        if(s[i] != ' ') ans++;
    }

    cout << ans;
}

int main(int argc, char const *argv[])
{
    init();

    find();

    getchar();getchar();getchar();getchar();
    return 0;
}
