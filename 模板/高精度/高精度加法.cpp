#include<bits/stdc++.h>
using namespace std;

//存储
struct big
{
    int num[100001],len;
    big(){
        memset(num,0,sizeof(num));
        len=0;
    }
};

char c[100001],d[100001];
big a,b,ans;

//输入
inline void change()
{
	cin >> c;	cin >> d;	
    a.len = strlen(c); //strlen求串长 	
    b.len = strlen(d);	
    for(int i=0; i<a.len; i++) a.num[a.len - i] = c[i] - '0'; //逆序存储 	
    for(int i=0; i<b.len; i++) b.num[b.len - i] = d[i] - '0';
}

//加法
inline void add()
{
    ans.len=max(a.len,b.len);
    for(int i=1;i<=ans.len;++i)
    {
        ans.num[i]+=a.num[i]+b.num[i];
        ans.num[i+1]+=ans.num[i]/10;
        ans.num[i]%=10;
    }
    if(ans.num[ans.len+1]!=0) ans.len++;
}

//输出
inline void put()
{
    for(int i=ans.len;i>=1;--i) cout<<ans.num[i];
}

int main(int argc, char const *argv[])
{
    change();
    add();
    put();
    getchar();getchar();getchar();
    return 0;
}
