#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int xiaoA[201],xiaoB[201];
    int q,a,b;
    cin>>q>>a>>b;
    for(int i=1;i<=a;++i) cin>>xiaoA[i];
    for(int i=1;i<=b;++i) cin>>xiaoB[i];
    int ansA = 0,ansB = 0,n = 0,m = 0;
    for(int i=1;i<=q;++i)
    {
        n++;m++;
        if(n > a) n=1;
        if(m > b) m=1;
        //枚举每一种情况 且只用枚举得分情况
        //由题面上的表我们可以得出
        if(xiaoA[n]==0 && xiaoB[m]==1 ) ansB++;
        if(xiaoA[n]==0 && xiaoB[m]==2 ) ansA++;
        if(xiaoA[n]==0 && xiaoB[m]==3 ) ansA++;
        if(xiaoA[n]==0 && xiaoB[m]==4 ) ansB++;
        if(xiaoA[n]==1 && xiaoB[m]==0 ) ansA++;
        if(xiaoA[n]==1 && xiaoB[m]==2 ) ansB++;
        if(xiaoA[n]==1 && xiaoB[m]==3 ) ansA++;
        if(xiaoA[n]==1 && xiaoB[m]==4 ) ansB++;
        if(xiaoA[n]==2 && xiaoB[m]==0 ) ansB++;
        if(xiaoA[n]==2 && xiaoB[m]==1 ) ansA++;
        if(xiaoA[n]==2 && xiaoB[m]==3 ) ansB++;
        if(xiaoA[n]==2 && xiaoB[m]==4 ) ansA++;
        if(xiaoA[n]==3 && xiaoB[m]==0 ) ansB++;
        if(xiaoA[n]==3 && xiaoB[m]==1 ) ansB++;
        if(xiaoA[n]==3 && xiaoB[m]==2 ) ansA++;
        if(xiaoA[n]==3 && xiaoB[m]==4 ) ansA++;
        if(xiaoA[n]==4 && xiaoB[m]==0 ) ansA++;
        if(xiaoA[n]==4 && xiaoB[m]==1 ) ansA++;
        if(xiaoA[n]==4 && xiaoB[m]==2 ) ansB++;
        if(xiaoA[n]==4 && xiaoB[m]==3 ) ansB++;

        printf("%d %d\n",ansA,ansB);    
    }
    printf("%d %d",ansA,ansB);
    getchar();getchar();getchar();getchar();
    return 0;
}
