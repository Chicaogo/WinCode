#include<bits/stdc++.h>
using namespace std;

const int MAX = 100010;
int num[MAX],n,f;
double l,r;
double sum[MAX];

void init()
{
    cin >> n >> f;

    for(int i = 1;i <= n;++i)
    {
        cin >> num[i];
        r = max(r,(double)num[i]);
    }
}

bool find(double avg)
{
    for(int i = 1;i <= n;++i)
        sum[i] = sum[i-1] + num[i] - avg;
    
    double minn = 0;
    for(int i = f,j = 0;i <= n;++i,++j)
    {
        minn = min(minn,sum[j]);
        if(sum[i] - minn >= 0)
            return true;
    }

    return false;
}

int search()
{
    while(r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if(find(mid)) l = mid;
        else r = mid;
    }
    
    return (int)(r * 1000); 
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    cout << search();
    
    return 0;
}
