#include<bits/stdc++.h>
#define I using namespace std;
#define LOVE long long think[3000];
#define YZY int n;int main(void){think[0] = think[1] = 1;think[2] = 2;cin>>n;for(int i=3;i<=n;i++){int j=0;while(j<=i-1){think[i]+=think[j]*think[i-1-j];think[i]%=100000007;j++;}}cout<<think[n];return 0;}

I LOVE YZY