#include<bits/stdc++.h>

int fuck[25]={0,1};

int main(){
    int n,a,m,x,qwq;
    
    scanf("%d%d%d%d",&a,&n,&m,&x);

    for(int i=2;i<n;i++)fuck[i]=fuck[i-1]+fuck[i-2];

    qwq=(m-fuck[n-3]*a-a)/(fuck[n-2]-1);
    
    if(x==1)printf("%d",a);
    else printf("%d",(fuck[x-2]+1)*a+(fuck[x-1]-1)*qwq);
    
    return 0;
}