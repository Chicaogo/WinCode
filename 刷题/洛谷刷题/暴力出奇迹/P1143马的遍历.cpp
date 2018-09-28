//https://www.luogu.org/problemnew/show/P1443
#include<bits/stdc++.h>
using namespace std;
struct fuck
{
    int x,y;
}emm[43333];

int main(int argc, char const *argv[])
{
    int n,m,CX,CY,GAY[410][410];
    int fx[]={2,-2,2,-2,-1,1,-1,1},fy[]={1,1,-1,-1,2,2,-2,-2};
    int head=0,tail=1;
    memset(GAY,-1,sizeof(GAY));
    cin>>n>>m>>CX>>CY;
    GAY[CX][CY]=0;
    emm[1].x=CX;emm[1].y=CY;
    while(head<tail){
        head++;
        int qwq=GAY[emm[head].x][emm[head].y]+1;
        for(int i=0;i<8;++i){
            int ix=emm[head].x+fx[i],iy=emm[head].y+fy[i];
            if(GAY[ix][iy]==-1&&ix>=1&&ix<=n&&iy>=1&&iy<=m){
                tail++;
                emm[tail].x=ix;
                emm[tail].y=iy;
                GAY[ix][iy]=qwq;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%-5d", GAY[i][j]);
        }
        cout<<endl;
    }
    getchar();getchar();getchar();getchar();
    return 0;
}
