//https://www.luogu.org/problemnew/show/P1049
#include<bits/stdc++.h>
using namespace std;

/*
    �����ʵ���ϻ���һ��0-1�������⣬�������������Ҫ��Ҫ
*/

const int MAXV = 20001;
int n,V,dp[MAXV],v[31];

int main(int argc, char const *argv[])
{
    cin >> V >> n;
    
    for(int i = 0;i < n;++i) cin >> v[i];

    for(int i = 0;i < n;++i)
    //�ӵ�һ��������ʼö�٣�Ҫ���ǲ�Ҫ
    {
        for(int j = V;j >= v[i];j--)
        {
            if(dp[j] < dp[j-v[i]]+v[i])
                dp[j] = dp[j-v[i]]+v[i];
        }
    }

    cout << V-dp[V];

    getchar();getchar();
    return 0;
}
