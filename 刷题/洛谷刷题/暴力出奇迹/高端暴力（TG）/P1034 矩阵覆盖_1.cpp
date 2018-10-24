#include<cstdio>
#include<algorithm>
using namespace std;
inline void read(int &x)
{
    char cu=getchar();x=0;
    while(cu<'0'||cu>'9')cu=getchar();
    while(cu>='0'&&cu<='9'){x=x*10+cu-'0';cu=getchar();}
}
void print(int x)
{
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
struct Poi
{
    int x,y;
}Q[51];
int n,k,ans=0x7fffffff;
int cmp1(Poi X,Poi Y)
{
    if(X.x==Y.x)return X.y<Y.y;
    return X.x<Y.x;
}
int cmp2(Poi X,Poi Y)
{
    if(X.y==Y.y)return X.x<Y.x;
    return X.y<Y.y;
}
int bj[4];
int count()
{
    int res=0,las=1;
    int lx,rx,ly,ry;
    for(int i=0;i<k;i++)
    {
        lx=rx=Q[las].x;
        ly=ry=Q[las].y;
        for(int j=las+1;j<=bj[i];j++)
        {
            lx=min(lx,Q[j].x);
            rx=max(rx,Q[j].x);
            ly=min(ly,Q[j].y);
            ry=max(ry,Q[j].y);
        }
        res+=(rx-lx)*(ry-ly);
        las=bj[i]+1;
    }
    return res;
} 
void dfs(int dq,int num)
{
    if(dq>n)
    {
        if(num==k)ans=min(ans,count());
        return;
    }
    if(num==k)return;
    for(int i=dq;i<=n;i++)
    {
        bj[num]=i;
        dfs(i+1,num+1);
    }
}
int main()
{
    read(n),read(k);
    if(k>=n)
    {
        putchar('0');
        return 0;
    }
    for(int i=1;i<=n;i++)read(Q[i].x),read(Q[i].y);
    sort(Q+1,Q+n+1,cmp1);
    dfs(1,0);
    sort(Q+1,Q+n+1,cmp2);
    dfs(1,0);
    print(ans);
    return 0;
}