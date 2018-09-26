#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int num,ans;
    scanf("%d",&num);
    num=num+num*1000;
    ans=num/7/11/13;
    printf("%d",ans);
    getchar();getchar();
    return 0;
}
