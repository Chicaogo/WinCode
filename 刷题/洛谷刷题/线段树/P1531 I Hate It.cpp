#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int L;
    int R;
    int sum;
}Seg[800010];
int n,m,cnt,root;
char C;

void Build(int &now,int l,int r,int x,int k){
    if(now==0)
        now=++cnt;
    if(l==r){
        Seg[now].sum=k;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        Build(Seg[now].L,l,mid,x,k);
    else
        Build(Seg[now].R,mid+1,r,x,k);
    Seg[now].sum=max(Seg[Seg[now].L].sum,Seg[Seg[now].R].sum);

}

void Insert(int &now,int l,int r,int x,int k){
    if(now==0)
        now=++cnt;
    if(l==r){
        Seg[now].sum=max(Seg[now].sum,k);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        Insert(Seg[now].L,l,mid,x,k);
    else
        Insert(Seg[now].R,mid+1,r,x,k);
    Seg[now].sum=max(Seg[Seg[now].L].sum,Seg[Seg[now].R].sum);
}

int Query(int now,int l,int r,int x,int y){
    if(x<=l && r<=y)
        return Seg[now].sum;
    int mid=(l+r)>>1;
    int maxL=0,maxR=0;
    if(x<=mid)
        maxL=max(maxL,Query(Seg[now].L,l,mid,x,y));
    if(y>mid)
        maxR=max(maxR,Query(Seg[now].R,mid+1,r,x,y));
    return max(maxL,maxR);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        register int k;
        scanf("%d",&k);
        Build(root,1,n,i,k);
    }
    for(int i=1;i<=m;i++){
        cin>>C;
        if(C=='Q'){
            register int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",Query(root,1,n,x,y));
        }
        else{
            register int x,k;
            scanf("%d%d",&x,&k);
            Insert(root,1,n,x,k);
        }
    }
    return 0;
}