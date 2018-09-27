#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
char ss[maxn][maxn],zz[]="yizhong";
int vis[maxn][maxn];
int fuck[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
struct wahaha
{
    int a,b;
}c[maxn];


void dfs_one(int n);
void dfs_tow(int x,int y,int k,int cnt,wahaha c[]);

void dfs_one(int n){
    for(int i=0;i< n;++i){
        for(int j=0;j< n;++j){
            if(ss[i][j]=='y'){
                for(int k = 0; k < 8; k++)
                {
                    int x=i+fuck[k][0];
                    int y=j+fuck[k][1];
                    if(ss[x][y]=='i') {
                        dfs_tow(i,j,k,0,c);
                    }
                }
            }
        }
    }
}

void dfs_tow(int x,int y,int k,int cnt,wahaha c[]){
    if(cnt==7) {
        for(int i=0;i<7;++i){
            vis[c[i].a][c[i].b]=1;
        }
    }
    else{
        int dx=x+fuck[k][0];
        int dy=y+fuck[k][1];
        if(cnt==6||ss[dx][dy]==zz[cnt+1]){
            c[cnt].a=x;c[cnt].b=y;
            dfs_tow(dx,dy,k,cnt+1,c);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",&ss[i]);
    }
    memset(vis,0,sizeof(vis));
    dfs_one(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(vis[i][j]) printf("%c",ss[i][j]);
            else printf("*");
        }
        printf("\n");
    }
    getchar();getchar();getchar();
    return 0;
}
