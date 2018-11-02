#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    int x = 0,t = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') t = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
    return x*t;
}

struct qwq
{
    int first,second;
    bool operator < (const qwq &a)
    {
        return first < a.first;
    }
}num[100010];

int n;
double sum = 0;

inline void init()
{
    n = read();

    for(int i = 1;i <= n;++i)
    {
        num[i-1].first = read();
        num[i-1].second = i;
    }
    
    std::sort(num,num+n);
    
    for(int i = 0;i < n;++i)
    {
        sum += num[i].first*(n-i-1);
        std::cout << num[i].second << " ";
    }
    
    printf("\n%.2lf",sum/n);

}

int main(void)
{
    init();
    return 0;
}
