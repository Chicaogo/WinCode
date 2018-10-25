#include<bits/stdc++.h>
using namespace std;

int n,ans=0,flag=0,num;

int main(int argc, char const *argv[])
{
    cin >> n >> num;

    for(int i = 2;i <= n;++i)
    {
        int x ; cin >> x;
        if(x == num) continue;
        else if(x<num && flag != 1){ ans++; flag = 1;}
        else if(x>num && flag != 2){ ans++; flag = 2;}
        num = x;
    }
    
    cout << ans+1;

    getchar();getchar();getchar();
    return 0;
}
