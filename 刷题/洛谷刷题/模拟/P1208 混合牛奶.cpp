#include<bits/stdc++.h>
using namespace std;
struct n{
    int a;
    int b;
    bool operator < (const n &fuck)
    {
        return a < fuck.a;
    }
}t[5002];
int main(void)
{
    int n,m,i,sum=0;
    cin >> n >> m;
    for(i=0;i<m;i++)
    cin >> t[i].a >> t[i].b;
    sort(t,t+m);i=0;
    while(1){
        if(n>t[i].b){
            sum+=t[i].a*t[i].b;
            n-=t[i].b;
        }
        else {
            sum+=n*t[i].a;
            break;
        }
        i++;
    }
    cout << sum;
    return 0;
}