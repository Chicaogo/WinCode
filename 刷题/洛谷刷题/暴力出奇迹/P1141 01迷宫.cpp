#include<bits/stdc++.h>
using namespace std;

int fa[1000005],haaa[1000005],n;//f[i]表示i节点的父节点,
                            //h[i]表示i节点及其子节点的连通块数
char s[2][1005];//滚动数组
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}//查
void unionn(int x,int y)//并
{
    int r1=get(x),r2=get(y);
    if(r1!=r2)haaa[r1]+=haaa[r2],fa[r2]=fa[r1];
}
int main()
{
    int t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i&1]);
        for(int j=0;j<n;j++)
        {
            fa[i*n+j]=i*n+j,haaa[i*n+j]=1;//构造映射
            if(i!=0&&s[(i-1)&1][j]!=s[i&1][j])unionn((i-1)*n+j,i*n+j);
            if(j!=0&&s[i&1][j-1]!=s[i&1][j])unionn(i*n+j,i*n+j-1);
        }
    }
    int i,j;
    while(t--)
    {
        scanf("%d%d",&i,&j);
        printf("%d\n",haaa[get((i-1)*n+j-1)]);
    }
    return 0;
}

/*
char maps[1010][1010];
int sun,n,m,ans[1000010];
int ppx[1010][1010];
inline void read(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            char ch;
            cin>>maps[i][j];
        }
    }
}
int tipi=0;
void dfs(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=n){
    
    
    
        /*tipi++;//cout<<"运行正常！第"<<tipi<<"运行！"<<endl;
        if(maps[x][y]!=maps[x+1][y] && ppx[x+1][y]==0){ppx[x+1][y]=1;dfs(x+1,y);}
        else if(maps[x][y]!=maps[x-1][y] && ppx[x-1][y]==0){ppx[x-1][y]=1;dfs(x-1,y);}
        else if(maps[x][y]!=maps[x][y+1] && ppx[x][y+1]==0){ppx[x][y+1]=1;dfs(x,y+1);}
        else if(maps[x][y]!=maps[x][y-1] && ppx[x][y-1]==0){ppx[x][y-1]=1;dfs(x,y-1);}
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
        if(ans[maps[a][b]]>0) {
            cout<<ans[maps[a][b]];
            continue;
        }
        ppx[a][b]=1;
        dfs(a,b);
        cout<<tipi<<endl;
        memset(ppx,0,sizeof(ppx));
        m--;
    }
    getchar();getchar();getchar();
    return 0;
}
*/