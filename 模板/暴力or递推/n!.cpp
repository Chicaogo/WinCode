#include<bits/stdc++.h>
using namespace std;
long long ans;
long long fuck(long long n){
    if(n==1) return 1;
    return n*fuck(n-1);
}
int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld",&n);
    printf("%lld",fuck(n)); 
    getchar();getchar();getchar();
    return 0;
}
