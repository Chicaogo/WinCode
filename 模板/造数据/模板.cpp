#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
using namespace std;

int random(int n)
{
    return (long long)rand()*rand()%n;
}

//随机生成整数序列
inline void listed() //随机生成n <= 1e5 , 绝对值在 1e9 之内的整数
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

//随机生成区间列
inline interval()  //随机生成m <= 100 个[1,n]的子区间
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
    //接下来可以瞎胡乱搞了

    //listed();
    
    //interval();

    return 0;
}
