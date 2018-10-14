#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=10e6+10;
ll a[maxn],ans[maxn<<2],tag[maxn<<2],n,m;

inline ll ls(ll x)
{
	return x<<1;
}//左儿子 

inline ll rs(ll x)
{
	return x<<1|1;
}//右儿子 

inline void push_up(ll p)
{
	ans[p]=ans[ls(p)]+ans[rs(p)];
}//更新父节点

void build(ll p,ll l,ll r)
{
	tag[p]=0;
	if(r==l){ans[p]=a[l];return;	}
	ll mid=(r+l)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
 } //递归建树 

 void change(ll p,ll l,ll r,ll k)
 {
 	tag[p]+=k;
 	ans[p]+=(r-l+1)*k;
 }//更新懒标记和节点信息 

 inline void push_down(ll p,ll l,ll r)
 {
 	ll mid=(r+l)>>1;
 	change(ls(p),l,mid,tag[p]);
 	change(rs(p),mid+1,r,tag[p]);
 	tag[p]=0;
 }//更新两个子区间的信息

 inline void updata(ll cl,ll cr,ll l,ll r,ll p,ll k)
 {
 	if(cl<=l&&cr>=r)
 	{
 		ans[p]+=(r-l+1)*k;
 		tag[p]+=k;
 		return ;
	 }
	 push_down(p,l,r);
	 ll mid=(r+l)>>1;
	 if(cl<=mid)updata(cl,cr,l,mid,ls(p),k);
	 if(cr>mid)updata(cl,cr,mid+1,r,rs(p),k);
	 push_up(p);
  } //区间更新

ll query(ll x,ll y,ll l,ll r,ll p)
  {
  	ll res=0;
  	if(x<=l&&y>=r)return ans[p];
  	ll mid=(r+l)>>1;
  	push_down(p,l,r);
  	if(x<=mid)res+=query(x,y,l,mid,p);
  	if(y>mid)res+=query(x,y,mid+1,r,p);
  	return res;
  }//区间查找 

ll read()
{
	char c=getchar();int x=1;ll ans=0;
	while(c<'0'||c>'9'){x=-1;c=getchar();	}
	while(c>='0'&&c<='9'){ans+=c-'0';c=getchar();	}
	return x*ans;
}

char tmp[110];
ll out(ll x)
{
	int cnt=1;
	while(x){
	tmp[cnt]=x%10;
	x/=10;
	cnt++;
	}
	for(cnt--;cnt>=1;cnt--)
	putchar(tmp[cnt]);
	putchar(' ');
 } 

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	build(1,1,n);
	int b
	ll c,d,e;
	while(m--)
	{
		scanf("%d",&b);
		if(b==1)
		{
			scanf("%lld%lld%lld",&c,&d,&e);
			updata(c,d,1,n,1,e);
		}
		else 
		{
			scanf("%lld%lld",&c,&d);
			out(query(x,y,1,n,1));
		}
	}
	return 0;
 } 