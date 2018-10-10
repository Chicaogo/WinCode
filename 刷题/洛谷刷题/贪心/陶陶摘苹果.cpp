//https://www.luogu.org/problemnew/show/P1478
#include<bits/stdc++.h>
using namespace std;

int n,s,a,b;
int cnt = 0,ans = 0;
int app[52100];//用来存摘取每个苹果消耗的体力值

int main(int argc, char const *argv[])
{
    cin >> n >> s >> a >> b;

    for(int i = 0;i < n;++i)
    {
        int x,y;
        cin >> x >> y;
        if(x - b - a <= 0)  //在线选择 
        //可以用反证法证明：当苹果的高度高于板凳加上手的长度，苹果肯定摘不到
        {
            app[cnt] = y;
            cnt++;
            //计数器累加
        }
    }

    sort(app,app+cnt); 
    //贪心的选择每次消耗体力最小的苹果

    for(int i = 0;i < cnt;++i)
    {
        s -= app[i];
        if(s >= 0) ans++;
        //当体力还有的时候 答案++
        if(s < 0) break;
        //这里同样可以用反证法证明
    }

    cout << ans;

    return 0;
}
/*17级 蛤省师大附中*/