#include<bits/stdc++.h>
using namespace std;
double maxx,mo=0,d2,shengyu=0,d1,c,p;
int n;

struct edge
{
    double co;
    double dis;
}jiayouzhan[10000];

int search(int now)
{
    int can=99999;
    int f=jiayouzhan[now].dis;

    for(int i=now+1;i<=n&&jiayouzhan[i].dis-f<=maxx;i++)
    {
        if(jiayouzhan[i].co<jiayouzhan[now].co)
        {
            mo+=((jiayouzhan[i].dis-f-shengyu)/d2)*jiayouzhan[now].co;
            shengyu=0;
            return i;
        }
        if(can==99999||jiayouzhan[i].co<jiayouzhan[can].co)can=i;
    }

    if(d1-jiayouzhan[now].dis<=maxx)
        {
            mo+=((d1-jiayouzhan[now].dis-shengyu)/d2)*jiayouzhan[now].co;
            return 9999;
        }

    if(can==99999)
    {
        cout<<"No Solution";
        return -1;
    }

    else
    {
        mo+=c*jiayouzhan[now].co;
        shengyu+=(maxx-jiayouzhan[can].dis+f);
        return can;
    }
}

int cmp(edge a,edge b)
{
    return a.dis<b.dis;
}

int main()
{
    cin>>d1>>c>>d2>>p>>n;
    jiayouzhan[0].dis=0;
    jiayouzhan[0].co=p;

    for(int i=1;i<=n;i++)cin>>jiayouzhan[i].dis>>jiayouzhan[i].co;

    sort(jiayouzhan,jiayouzhan+n,cmp);

    maxx=c*d2;
    int k=0,t;

    do
    {
        t=search(k);
        k=t;
        if(t==-1)return 0;
    }while(t!=9999);

    printf("%.2f",mo);
    return 0;
}