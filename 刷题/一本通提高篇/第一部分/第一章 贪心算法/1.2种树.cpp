//https://www.luogu.org/problemnew/show/P1250
#include<bits/stdc++.h>

struct line{
    int s,e,v;
    bool operator < (const line &a)
    {
        return e < a.e;
    }
}a[5005];
int n,m,ans=0;
bool used[30005]={0};//判断是否已经有点

int main(void)
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=m;i++) 
        scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].v);
    
    std::sort(a+1,a+1+m);//排序
    
    for(int i=1;i<=m;i++)
    {
        int k=0;//用来统计区间已有的树的个数
        for(int j=a[i].s;j<=a[i].e;j++) if(used[j]) k++;//统计已有点的个数
        if(k>=a[i].v) continue;//已满足，continue
        for(int j=a[i].e;j>=a[i].s;j--)//不满足，在结尾处加入
        {
            if(!used[j])
            {
                used[j]=1;
                k++;
                ans++;//答案+1
                if(k==a[i].v) break;//满足退出
            }
        }
    }
    
    printf("%d",ans);//输出答案
    return 0;
}