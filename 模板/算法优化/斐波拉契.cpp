#include<bits/stdc++.h>
int a=1,b=1;
int n;
int fibonac(int a,int b,int n)
{
    if(n > 1)
    {	
        return fibonac(a+b,a,n-1);
    }
    return a;
}
int main(){
    scanf("%d",&n);
    printf("%d",fibonac(a,a,n));
    return 0;
}
