#include<bits/stdc++.h>
using namespace std;

const int inf = 1e5;

int random(int n)
{
    return (long long)rand()*rand()%n;
}

//���������������
inline void listed() //�������n <= 1e5 , ����ֵ�� 1e9 ֮�ڵ�����
{
    int n = random(100000) + 1;
    int m = 1e9;
    for(int i = 1;i <= n;i++)
    {
        long long ans = random(2 * m + 1) - m ;
        if(ans < 0) cout << -ans << " ";
        else cout << ans << " ";
    }
}

//�������������
inline interval()  //�������m <= 100 ��[1,n]��������
{
    int m = random(100) + 1;
    int n = 99;
    for(int i = 1;i <= m;i++)
    {
        int l = random(n) + 1;
        int r = random(n) + 1;
        if(l > r) swap(l , r);
        cout << l << " " << r << endl;
    }
}

inline tree()  //�������n�������
{
    int n = random(100000) + 1;
    for(int i = 2; i <= n;++i)
    {
        int fa = random(i - 1) + 1;
        int val = random(inf) + 1;
        cout << fa << " " << i << " " << val << endl;
    }
}

inline tu()
{
    pair<int,int> e[1000005];
    map<pair<int ,int > ,bool> h;
    int n = random(10) + 1;
    int m = random(100000) + 1;
    for(int i = 1; i <= n;++i)
    {
        int fa = random(i - 1) + 1;
        e[i] = make_pair(fa , i+1);
        h[e[i]] = h[make_pair(i+1,fa)] = 1;
    }
    for(int i = n;i <= m;i++)
    {
        int x,y;
        do{
            x = random(n) + 1,y = random(n) + 1;
        }while(x == y || h[make_pair(y,x)]);
        random_shuffle(e+1,e+m+1);
        for(int i = 1;i <= m;i++) 
            cout << e[i].first << " " << e[i].second << endl;
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(0));
    freopen("out.txt","w",stdout);
    //����������Ϲ���Ҹ���

    //listed();
    
    //interval();

    //tree();

    tu();

    return 0;
}
