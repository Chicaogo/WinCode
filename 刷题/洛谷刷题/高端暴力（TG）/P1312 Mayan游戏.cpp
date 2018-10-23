#include <bits/stdc++.h>
using namespace std;

#define il inline

int n;
int mapp[6][8],ans[6][8],last[6][6][8],tong[6][8];

il int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

//记录操作（搜索回溯还原）
il void copy (int x)
{
    for(int i = 1;i <= 5;++i)
        for(int j = 1;j <= 7;++j)
        {
            last[x][i][j] = mapp[i][j];
        }
}

//下沉操作
il void update()
{   
    for(int i = 1;i <= 5;++i)
        int flag = 0;
        for(int j = 1;j <= 7;++j)
        {
            if(mapp[i][j] == 0) flag++;
            else
            {
                if(!flag) continue;
                mapp[i][j - flag] = mapp[i][j];
                mapp[i][j] = 0;
            }
        }
}

//消除操作
il bool reover()
{
    bool flag = 1;
    for(int i = 1;i <= 5;++i)
        for(int j = 1;j <= 7;++j)
        {
            if(i-1 >= 1 && i+1 <= 5 && mapp[i][j] != 0 && mapp[i][j] == mapp[i-1][j] && mapp[i][j] == mapp[i+1][j])
            {
                tong[i][j] = 1;
                tong[i-1][j] = 1;
                tong[i+1][j] = 1;
                flag = 0;
            }
            if(j-1 >= 1 && j+1 <= 7 && mapp[i][j] != 0 && mapp[i][j] == mapp[i][j-1] && mapp[i][j] == mapp[i][j+1])
            {
                tong[i][j] = 1;
                tong[i][j-1] = 1;
                tong[i][j+1] = 1;
                flag = 0;
            }
        }
    
    if(flag) return 0;

    for(int i = 1;i <= 5;++i)
        for(int j = 1;j <= 7;++j)
        {
            if(tong[i][j]) 
            {
                mapp[i][j] = 0;
                tong[i][j] = 0;
            }
        }
    
    return 1;
}

//交换操作
il void move(int i,int j,int flag)
{
    swap(mapp[i][j],mapp[i][j+flag]);
    update();
    while(reover()) update();
}

//玩完了
il bool gameover()
{
    for(int i = 1;i <= 5;++i)
        if(mapp[i][1]) return 0;
    
    return 1;
}

//搜索
void dfs(int x)
{
    if(gameover())
    {
        for(int i = 1;i <= n;++i)
        {
            if(i != 1) cout << endl;
            cout << ans[i][1] <<" "<< ans[i][2] <<" "<< ans[i][3];
        }
        exit(0);
    }

    if(x == n+1) return 0;

    copy(x);

    for(int i = 1;i <= 5;++i)
        for(int j = 1;j <= 7;++j)
        {
            if(mapp[i][j])
            {
                if(i-1 >= 1 && mapp[i][j] != mapp[i-1][j])
                {
                    move(i,j,-1);
                    ans[x][1] = i+1;
                    ans[x][2] = j+1;
                    ans[x][3] = -1;
                    
                    dfs(x+1);

                    for(int i = 1;i <= 5;++i)
                        for(int j = 1;j <= 7;++j)
                            mapp[i][j] = last[x][i][j];
                    
                    ans[x][1] = 0;
                    ans[x][2] = 0;
                    ans[x][3] = 0;
                }

                if(i+1 >= 1 && mapp[i][j] != mapp[i+1][j])
                {
                    move(i,j,1);
                    ans[x][1] = i-1;
                    ans[x][2] = j-1;
                    ans[x][3] = 1;
                    
                    dfs(x+1);

                    for(int i = 1;i <= 5;++i)
                        for(int j = 1;j <= 7;++j)
                            mapp[i][j] = last[x][i][j];
                    
                    ans[x][1] = 0;
                    ans[x][2] = 0;
                    ans[x][3] = 0;
                }
            }
        }
}

int main(int argc, char const *argv[])
{
    n = read();

    for(int i = 1;i <= 5;++i)
        for(int j = 1;j <= 7;++j)
        {
            int x = read();
            if(x == 0) break; 
            mapp[i][j] = x;
        }

    dfs(1);

    printf("-1\n");

    return 0;
}
