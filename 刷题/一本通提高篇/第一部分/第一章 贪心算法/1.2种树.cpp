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
bool used[30005]={0};//�ж��Ƿ��Ѿ��е�

int main(void)
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=m;i++) 
        scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].v);
    
    std::sort(a+1,a+1+m);//����
    
    for(int i=1;i<=m;i++)
    {
        int k=0;//����ͳ���������е����ĸ���
        for(int j=a[i].s;j<=a[i].e;j++) if(used[j]) k++;//ͳ�����е�ĸ���
        if(k>=a[i].v) continue;//�����㣬continue
        for(int j=a[i].e;j>=a[i].s;j--)//�����㣬�ڽ�β������
        {
            if(!used[j])
            {
                used[j]=1;
                k++;
                ans++;//��+1
                if(k==a[i].v) break;//�����˳�
            }
        }
    }
    
    printf("%d",ans);//�����
    return 0;
}