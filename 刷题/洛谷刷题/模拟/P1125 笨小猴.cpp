//https://www.luogu.org/problemnew/show/P1125

#include<bits/stdc++.h>
using namespace std;

int maxn,minn,tong,len;
char word[110];
int ans[110];
//ÅÐ¶ÏËØÊý
bool su(int n)
{
    if(n==0 || n==1) return 0;
    for(int h=2;h<=sqrt(n);++h)
        if(n%h == 0) return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    scanf("%s",&word);
    len=strlen(word);
    
    for(int i=0;i<len;++i)
    {
        ans[word[i]]++;
    }
    
    maxn=ans[word[0]];
    minn=ans[word[0]];
    
    for(int i=1;i<len;++i)
    {
        if(ans[word[i]]>maxn) maxn=ans[word[i]];
        if(ans[word[i]]<minn) minn=ans[word[i]];
    }

    if(su(maxn-minn))
    {
        printf("Lucky Word\n%d",maxn-minn);
    }
    else printf("No Answer\n0");

    getchar();getchar();
    getchar();getchar();
    return 0;
}
