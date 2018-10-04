//https://www.luogu.org/problemnew/show/P1093
#include <bits/stdc++.h>
using namespace std;

struct qwq
{
    int wyu,wshu,wying;
    int sum;
    int number;

    bool operator < (const qwq &w)
    {
        if(sum > w.sum) return true;
        if(sum == w.sum) 
            {
                if(wyu > w.wyu) return true;
                if(wyu == w.wyu) return number < w.number;
            }
        return false;
    }

}num[310];

int n;

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    
    for(int i=1;i<=n;++i)
    {
        num[i].number=i;
        scanf("%d%d%d",&num[i].wyu,&num[i].wshu,&num[i].wying);
        num[i].sum=num[i].wyu+num[i].wshu+num[i].wying;
    }

    sort(num+1,num+n+1);

    if(n<=5)
    {
        for(int i=1;i<=n;++i) printf("%d %d\n",num[i].number,num[i].sum);
    }
    else
    {
        for(int i=1;i<=5;++i) printf("%d %d\n",num[i].number,num[i].sum);
    }

    getchar();getchar();getchar();
    return 0;
}
