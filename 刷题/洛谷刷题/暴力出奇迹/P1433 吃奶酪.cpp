#include<bits/stdc++.h>
using namespace std;
int n,vis[1001];
double x[100],y[20];
double dis[1001][1001]; 
double ans=-(1<<31);

inline void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>x[i]>>y[i];
    x[0]=0;y[0]=0;
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
        dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void dfs(int step,int now,double length)
{
    if(length>ans)
      return; 
    if(step==n)      
    {
          ans=min(ans,length); 
          return;
    }
    for(int i=1;i<=n;i++) 
        if(!vis[i])
        {
            vis[i]=1;
            dfs(step+1,i,length+dis[now][i]);
            vis[i]=0;
        }
}

int main()
{
    init();
    dfs(0,0,0.0);
    printf("%.2f",ans);
    return 0;
}