#include<bits/stdc++.h>
using namespace std;

int a[1005],b[1005],m,s,c,i,ans;

bool cmp(int a,int b){
    return a > b;
}

int main(int argc, char const *argv[])
{
    cin >> m >> s >> c;

    for(i=1;i<=c;i++)
        scanf("%d",&a[i]);
    
    sort(a+1,a+c+1);
    for(i=1;i<=c-1;i++) 
        b[i]=a[i+1]-a[i]-1;
    
    sort(b+1,b+c,cmp);
    ans=a[c]-a[1]+1;
    for(i=1;i<m&&i<c;i++)
        ans-=b[i];
    
    cout << ans;
    return 0;
}