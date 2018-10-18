#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
int minn[MAXN*4],a[MAXN],cnt = 0,n,m,l,r;

void build(int now,int l,int r)
{
    if(l==r)
    {
        cnt++;
        minn[now]=a[cnt];
    }
    else
    {
        int mid=(l+r)/2;
        build(now*2,l,mid);
        build(now*2+1,mid+1,r);
        minn[now]=min(minn[now*2],minn[now*2+1]);
    }
}

void update(int now,int l,int r,int x,int y)
{
    if(r==l) minn[now] = y;
    else
    {
        int mid=(l+r)/2;
        if(x<=mid) update(now*2,l,mid,x,y);
        if(x>mid) update(now*2+1,mid+1,r,x,y);
        minn[now]=min(minn[now*2],minn[now*2+1]);
    }
}

int get_min(int now,int l,int r,int q_l,int q_r){
    int re=0x7fffffff;
    if(q_l<=l&&q_r>=r){
        re=minn[now];
    }else{
        int mid=(l+r)/2;
        if(q_l<=mid)re=min(re,get_min(now*2,l,mid,q_l,q_r));
        if(q_r>mid)re=min(re,get_min(now*2+1,mid+1,r,q_l,q_r));
    }
    return re;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    
    for(int i = 1;i <= n;++i) cin >> a[i];
    
    build(1,1,n);

    while(m--)
    {
        cin >> l >> r;
        cout << get_min(1,1,n,l,r) << " ";
    }

    return 0;
}
