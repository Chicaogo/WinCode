#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    while(n)
    {
        int i;
        cin>>i;
        if(i==1)
        {
            int x;
            cin>>x;
            pq.push(x);
        }
        if(i==2)
        {
            cout<<pq.top()<<endl;
        }
        if(i==3)
        {
            pq.pop();
        }
        --n;
    }
    
    getchar();getchar();getchar();
    return 0;
}
