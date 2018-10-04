//https://www.luogu.org/problemnew/show/P1051
#include<bits/stdc++.h>
using namespace std;

struct cao
{
    string name;
    int sum,text,classs,lun;
    bool G,X;
    int number;

    bool operator < (const cao &a)
    {
        if(sum > a.sum) return sum > a.sum;
        if(sum == a.sum) return number < a.number;
        return false;
    }
}num[110];

int main(int argc, char const *argv[])
{
    int n,ans=0;

    cin>>n;

    for(int i=1;i<=n;++i)
    {
        char ch_1,ch_2;;
        num[i].number=i;
        cin>>num[i].name>>num[i].text>>num[i].classs>>ch_1>>ch_2>>num[i].lun;
        if(ch_1 == 'N') num[i].G=0;
        else num[i].G=1;
        if(ch_2 == 'N') num[i].X=0;
        else num[i].X=1;
    }
    for(int i=1;i<=n;++i)
    {
        if(num[i].text>80 && num[i].lun >= 1) num[i].sum+=8000;
        if(num[i].text>85 && num[i].classs>80) num[i].sum+=4000;
        if(num[i].text>90) num[i].sum+=2000;
        if(num[i].text>85 && num[i].X == 1) num[i].sum+=1000;
        if(num[i].classs>80 && num[i].G == 1) num[i].sum+=850;

        ans+=num[i].sum;
    }

    sort(num+1,num+n+1);

    cout << num[1].name;
    printf("\n%d\n%d\n",num[1].sum,ans);

    getchar();getchar();getchar();
    return 0;
}
