#include<bits/stdc++.h>
using namespace std;
int maps[1010][1010],ans,n,m;
int ppx[1010][1010];
inline void read(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            char ch;
            cin>>ch;
            if(ch=='1') maps[i][j]=1;
            else maps[i][j]=0;
        }
    }
}
int tipi=0;
void dfs(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=n){
        tipi++;//cout<<"运行正常！第"<<tipi<<"运行！"<<endl;
        if(maps[x][y]!=maps[x+1][y] && ppx[x+1][y]==0){ppx[x+1][y]=1;dfs(x+1,y);}
        if(maps[x][y]!=maps[x-1][y] && ppx[x-1][y]==0){ppx[x-1][y]=1;dfs(x-1,y);}
        if(maps[x][y]!=maps[x][y+1] && ppx[x][y+1]==0){ppx[x][y+1]=1;dfs(x,y+1);}
        if(maps[x][y]!=maps[x][y-1] && ppx[x][y-1]==0){ppx[x][y-1]=1;dfs(x,y-1);}
    }
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    read();
    while(m){
        tipi=0;
        int a,b;
        cin>>a>>b;
        ppx[a][b]=1;
        dfs(a,b);
        cout<<tipi<<endl;
        memset(ppx,0,sizeof(ppx));
        m--;
    }
    getchar();getchar();getchar();
    return 0;
}
