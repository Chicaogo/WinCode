//https://www.luogu.org/problemnew/show/P1583

#include<bits/stdc++.h>
using namespace std;
int e[12],n,k;
struct qwq{
    int w;//Ȩֵ 
    int number;//��� 
    int d;//��� 
    bool operator < (const qwq &b)const{
        if(w!=b.w)return w>b.w;
        return number<b.number;
    }
}p[20010];//����ÿ���˵���Ϣ 
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<10;i++)scanf("%d",&e[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].w);
        p[i].number=i+1;
    }//����+��� 
    sort(p,p+n);//��һ������ 
    for(int i=0;i<n;i++){
        p[i].d=i%10;//���� 
        p[i].w+=e[p[i].d];//����e[i] 
    }
    sort(p,p+n);//�ڶ������� 
    for(int i=0;i<k;i++)printf("%d ",p[i].number);
}