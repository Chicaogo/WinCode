//freopen("out.txt","w",stdout);
#include<bits/stdc++.h>
using namespace std; 
long long a=1,b=1;
long long n;
int i=0;
long long fibonac(long long a,long long b,long long n)
{
    if(n > 1)
    {	
        cout<<a<<",";
		return fibonac(a+b,a,n-1);
    }
    return a;
}
int main(){
	freopen("out.txt","w",stdout);
    n=90;
    fibonac(a,a,n);
    return 0;
}
