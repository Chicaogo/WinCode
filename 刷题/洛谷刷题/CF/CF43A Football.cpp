//https://www.luogu.org/problemnew/show/CF43A
#include<bits/stdc++.h>
using namespace std;

map<string,int> s;
int n,ans;

int main(void)
{
    cin >> n;
    while(n--){
        string ss;
        cin >> ss;
        s[ss]++;

        if(s[ss] > ans)
            ans = s[ss];
    }

    cout << ans;    

    return 0;
}