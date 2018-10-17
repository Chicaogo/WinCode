#include<bits/stdc++.h>
using namespace std;
struct wewewe
{
    int qwq;
    string name;
}fuck[100005];


int n,m,x,y;
int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>fuck[i].qwq>>fuck[i].name;
    }

    int rxz=0;

    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(fuck[rxz].qwq==0&&x==0)rxz=(rxz+n-y)%n;
        else if(fuck[rxz].qwq==0&&x==1)rxz=(rxz+y)%n;
        else if(fuck[rxz].qwq==1&&x==0)rxz=(rxz+y)%n;
        else if(fuck[rxz].qwq==1&&x==1)rxz=(rxz+n-y)%n;
    }
    
    cout<<fuck[rxz].name<<endl;
    return 0;
}