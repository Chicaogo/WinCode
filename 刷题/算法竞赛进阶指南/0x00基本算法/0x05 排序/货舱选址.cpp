#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
int num[MAX],n;

inline void init()
{
    cin >> n;

    for(int i = 1;i <= n;++i)
        cin >> num[i];
}

inline long long find()
{
    sort(num+1,num+n+1);

    int mid = num[(1+n)/2];
    long long ans = 0;

    for(int i = 1;i <= n;++i)
        ans += abs(num[i] - mid);
    
    return ans;
}

int main(void)
{
    init();

    cout << find();

    return 0;
}