#include<cstdio>
#include<iostream>
using namespace std;
struct dot
{
    int x,y;
} a[51];
struct mtrx
{
    int l,r,u,d;
    bool flag;
} p[5];
int n,m,ans=0x7f7f7f7f;
bool in(mtrx a, int x, int y)
{
    if (x>=a.l&&x<=a.r&&y>=a.d&&y<=a.u) return 1;
    return 0;
}
bool judge(mtrx a, mtrx b)
{
    if (in(a,b.l,b.u)) return 1;
    if (in(a,b.l,b.d)) return 1;
    if (in(a,b.r,b.u)) return 1;
    if (in(a,b.r,b.d)) return 1;
    return 0;
}
void dfs(int num)
{
    int value=0;
    for (int i=1; i<=m; i++)
    {
      if (p[i].flag)
      {
        for (int j=i+1; j<=m; j++)
          if (judge(p[i],p[j])) return;
      }
      value+=(p[i].r-p[i].l)*(p[i].u-p[i].d);
    }
    if (value>=ans) return;
    if (num>n){
        ans=value;
        return;
    }
    for (int i=1; i<=m; i++)
    {
        mtrx tmp=p[i]; //tmp的初值 
        if (p[i].flag==0)
        {
            p[i].flag=1;
            p[i].l=p[i].r=a[num].x;
            p[i].u=p[i].d=a[num].y;
            dfs(num+1); p[i]=tmp;    //回溯 （一定要回溯彻底，用tmp变量） 
            break;
        }
        else 
        {
            p[i].r=max(p[i].r,a[num].x); p[i].l=min(p[i].l,a[num].x);
            p[i].u=max(p[i].u,a[num].y); p[i].d=min(p[i].d,a[num].y);
            dfs(num+1);
            p[i]=tmp;   //回溯 （一定要回溯彻底，用tmp变量） 
        }    
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].y);
    dfs(1);
    printf("%d",ans);
    return 0;
}