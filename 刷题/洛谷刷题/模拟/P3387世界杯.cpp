#include<bits/stdc++.h>
using namespace std;

priority_queue<int> k,d,m,f;
int K,D,M,F;

int main(void)
{
    cin >> K >> D >> M >> F;
    
    for(int i = 1; i <= K ;++i) {int x;cin >> x;k.push(x);}
    for(int i = 1; i <= D ;++i) {int x;cin >> x;d.push(x);}
    for(int i = 1; i <= M ;++i) {int x;cin >> x;m.push(x);}
    for(int i = 1; i <= F ;++i) {int x;cin >> x;f.push(x);}

    int q = 0;
    cin >> q;

    while(q--)
    {
        int a,b,c;
        double ans = 0;
        cin >> a >> b >> c;
        
        ans += k.top(); k.pop();
        for(int i = 1;i <= a;++i) {ans+=d.top();d.pop();}
        for(int i = 1;i <= b;++i) {ans+=m.top();m.pop();}
        for(int i = 1;i <= c;++i) {ans+=f.top();f.pop();}

        printf("%.2lf\n",ans/11);
    }

    return 0;
}