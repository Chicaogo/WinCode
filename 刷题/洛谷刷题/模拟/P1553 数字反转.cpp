#include<bits/stdc++.h>
using namespace std;
int len1 = 0,len2 = 0;
string s;
char qwq = '0';
int ans ;

int main(int argc, char const *argv[])
{
    cin >> s;

    for(int i=0;i<s.size();++i)
    {
        if(s[i] >= '0' && s[i] <= '9') len1++;
        else
        {
            qwq = s[i];
            break;
        }
    }

    len2 = len1;
    len1--;

    while(s[len1] == '0' && len1 > 0) len1--;
    for(int i = len1;i >= 0;--i) cout << s[i];

    if(qwq == '0') return 0;
    if(qwq == '%') 
    {
        cout << qwq;
        return 0;
    }

    int len = s.size()-1;
    while(s[len2+1] == '0' && len2<len-1) len2++;
    while(s[len] == '0' && m > x+1) m--;
    for(int i=len;i > len2;i--) cout << s[i];

    return 0;
}
