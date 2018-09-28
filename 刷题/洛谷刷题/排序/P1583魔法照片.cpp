//https://www.luogu.org/problemnew/show/P1583

#include<bits/stdc++.h>
using namespace std;
int e[12],n,k;
struct qwq{
    int w;//权值 
    int number;//编号 
    int d;//类别 
    bool operator < (const qwq &b)const{
        if(w!=b.w)return w>b.w;
        return number<b.number;
    }
}p[20010];//储存每个人的信息 
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<10;i++)scanf("%d",&e[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].w);
        p[i].number=i+1;
    }//读入+编号 
    sort(p,p+n);//第一次排序 
    for(int i=0;i<n;i++){
        p[i].d=i%10;//分类 
        p[i].w+=e[p[i].d];//加上e[i] 
    }
    sort(p,p+n);//第二次排序 
    for(int i=0;i<k;i++)printf("%d ",p[i].number);
}