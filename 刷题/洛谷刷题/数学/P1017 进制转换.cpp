#include<bits/stdc++.h>
using namespace std;
char fuck[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'}; 
void swapp(int n,int m){//printf("n:%d m:%d",n,m);
    if(n==0)return;
    else{
        if(n>0||n%m==0)
        {
            swapp(n/m,m);
            printf("%c",fuck[n%m]);
        }
        else 
        {
            swapp(n/m+1,m);
            printf("%c",fuck[-m+n%m]);
        }
    }
}
int main(){
    int n,m;

    scanf("%d%d",&n,&m);
    
    printf("%d=",n);
    
    swapp(n,m);
    
    printf("(base%d)",m);
    return 0;
}