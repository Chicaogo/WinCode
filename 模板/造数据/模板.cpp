#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
using namespace std;

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

int main(int argc, char const *argv[])
{
    srand((unsigned)time(0));
    freopen("out.txt","w",stdout);
    //����������Ϲ���Ҹ���

    //listed();
    
    //interval();

    return 0;
}
