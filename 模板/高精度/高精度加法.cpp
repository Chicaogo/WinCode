#include<bits/stdc++.h>
using namespace std;

//�洢
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

//����
inline void change()
{
	cin >> c;	cin >> d;	
    a.len = strlen(c); //strlen�󴮳� 	
    b.len = strlen(d);	
    for(int i=0; i<a.len; i++) a.num[a.len - i] = c[i] - '0'; //����洢 	
    for(int i=0; i<b.len; i++) b.num[b.len - i] = d[i] - '0';
}

//�ӷ�
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

//���
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
