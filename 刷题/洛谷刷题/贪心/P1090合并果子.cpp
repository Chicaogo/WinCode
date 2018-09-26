#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int,vector<int>,greater<int> > pq;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        int num;
        scanf("%d",&num);
        pq.push(num);
    }
    long long ans=0;
    while(1){
        int x,y;
        x=pq.top();pq.pop();
        y=pq.top();pq.pop();
        cout<<ans<<ends<<x<<ends<<y<<endl;
        ans=ans+x+y;
        if(pq.empty()) break;
        pq.push(x+y);
    }
    cout<<ans;
    getchar();getchar();getchar();
    return 0;
}
