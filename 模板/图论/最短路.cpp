#include<bits/stdc++.h>
#define P pair<long long,int>
using namespace std;

const long long inf = 2147483647;
const int maxn = 100086;
const int maxm = 521314;

inline int read()
{
    int x=0,t=1;
    char ch = getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch == '-') t=-1;
        ch = getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x =x*10+ch-'0';
        ch = getchar();
    }
    return x*t;
}//���ٶ������

int n,m,s;  //n:��ĸ��� m:����ߵĸ��� s:���

/*************************floyd**************************/
/*
int a[maxn][maxn];

inline void floyd()
{
    for(int k=1;k<=n;++k)
    {
        //k ��ת��
        for(int i=1;i<=n;++i)
        {
            //i ���
            if(i==k || a[i][k]==inf) continue;
            //������ת���غ�ʱ ����ѭ��
            for(int j=1;j<=n;++j)
            {
                //j�յ�
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                //ѡ���i->j��ֱ�Ӿ��뻹����ת����
            }
        }
    }
}
*/
/************************dijkstra************************/

struct edge
{
    int u,v,w,next;
}G[maxm];

int head[maxm],vis[maxn],cnt=0;
long long dis[maxn];
priority_queue< P , vector< P > , greater< P > > q;
//���Ż�dijksra //q ÿ������С��

inline void addedge(int u,int v,int w)
{
    G[++cnt].u = u;
    G[cnt].v = v;
    G[cnt].w = w;
    G[cnt].next = head[u];
    head[u] = cnt;
}//��ʽǰ���Ǵ�ͼ ��ѧ��ͼ

inline void dijkstra()
{
    for(int i=1;i<=n;++i)
        dis[i]=2147483647;
    //dis �������µ�ÿ���������̾���
    dis[s] = 0;
    //��ʼ�� ����ֵ

    q.push(make_pair(0,s));
    //��ʼ�����

    while(!q.empty())
    {
        //����Ϊ��ʱ������������ͼ
        int x=q.top().second;
        q.pop();
        //ȡ��ͷԪ����С���ظ����� ����

        if(!vis[x])
        //����������¹��Ͳ��ٸ�����
        {
            vis[x]=1;
            for(int i = head[x];i;i = G[i].next)
            //��ʽǰ���Ǹ���ÿһ�����������С����
            {
                int v = G[i].v;
                dis[v] = min(dis[v],dis[x]+G[i].w);
                q.push(make_pair(dis[v],v));
            }
        }
    }

}

/***************************SPFA**************************/
/*
int tot=0,head[maxn];
long long dis[maxn];
bool vis[maxn];
struct Edge
{
      int next,to,w;
}h[maxm];

void add(int u,int v,int w)
{
    h[++tot].next=head[u];
    h[tot].to=v;
    h[tot].w=w;
    head[u]=tot;
}
//�����dijkstra�㷨������һ��

queue<int> q;
//�����Ż�

inline void spfa()
{
    memset(dis,inf,sizeof(dis));
    int u,v;
    q.push(s);
    dis[s] = 0;

    vis[s] = 1;

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        vis[u] = 1;
        for(int i=head[u];i;i=h[i].next)
        {
            v=h[i].to;
            if(dis[v]>dis[u]+h[i].w)
            {
                dis[v]=dis[u]+h[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
*/

int main(int argc, char const *argv[])
{/*
//��������������������������������������������������flyod������������������������������������������������//
    //floyd ������ö��
    n=read();m=read();s=read();

    memset(a,inf,sizeof(a));
    //��ʼ��a����Ϊ���ֵ

    int u,v,w;

    for(int i=1;i<=m;++i)
    {
        u=read();v=read();w=read();
        a[u][v]=min(a[u][v],w);
        //��u->v�ľ���
    }

    floyd();
    
    a[s][s]=0;
    for(int i=1;i<=n;++i)
    {
        printf("%d ",a[s][i]);
    }
    //�����
*/
//����������������������������������������������dijkstra����������������������������������������������//

    //dijkstra  ������̰��
    n=read(),m=read(),s=read();

    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        addedge(x,y,z);
    }

    dijkstra();

    for(int i=1;i<=n;i++)
    {
        printf("%lld ",dis[i]);
    }

//������������������������������������������������SPFA������������������������������������������������//
/*
    //SPFA  ������̰�İ�
    n=read(),m=read(),s=read();

    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        add(x,y,z);
    }

    spfa();

    for(int i=1;i<=n;i++)
    {
        printf("%lld ",dis[i]);
    }
*/
    getchar();getchar();getchar();
    return 0;
}
