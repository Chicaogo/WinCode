#include<bits/stdc++.h>
using namespace std;
int maps[100][100],mapCLON[100][100]={0};
int n,x,y;

void dfs(int x,int y)
{
    if(x>n||x<1||y>n||y<1||maps[x][y]!=0)//�ж��Ƿ�Խ�� 
        return;
    maps[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);//�ĸ����� 
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>maps[i][j];
            if(maps[i][j]==1) mapCLON[i][j]=-1;//b������ԭ����λ�� 
        }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
    if(maps[i][1]!=1) dfs(i,1);
    if(maps[i][n]!=1) dfs(i,n);//�ѵ�i�еĵ�һ�к͵�n�� 
    }
    for(int i=1;i<=n;i++)
    {
    if(maps[1][i]!=1) dfs(1,i);
    if(maps[n][i]!=1) dfs(n,i);//�ѵ�i�еĵ�һ�к͵�n�� 
    } 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mapCLON[i][j]==-1) printf("1 ");
            else
            if(maps[i][j]==0) printf("2 ");
            else printf("0 ");
        }
        printf("\n");
    }
    getchar();getchar();
    return 0;
}