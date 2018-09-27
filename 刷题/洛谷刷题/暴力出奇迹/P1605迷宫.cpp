#include<bits/stdc++.h>
using namespace std;
int SX,SY,FX,FY;
int MAP[6][6],vis[6][6];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int ans=0;
int n,m,t;

void dfs(int x,int y){
    if(x==FX && y==FY){
        ans++;
        return ;
    }
    else{
        for(int i = 0; i <= 3; i++)
        {
            if(vis[x+dx[i]][y+dy[i]]==0 && MAP[x+dx[i]][y+dy[i]]==1)
            {
                vis[x][y]=1;
                dfs(x+dx[i],y+dy[i]);
                vis[x][y]=0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            MAP[i][j]=1;
        }
    }
    scanf("%d%d%d%d",&SX,&SY,&FX,&FY);
    for(int i=1;i<=t;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        MAP[x][y]=0;
    }
    memset(vis,0,sizeof(vis));
    dfs(SX,SY);
    printf("%d",ans);
    getchar();getchar();getchar();
    return 0;
}
