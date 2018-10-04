#include <cstdio>

using namespace std;

void Get_Val(int &Ret)
{
    Ret = 0;
    char ch;
    while (ch = getchar(), ch > '9' || ch < '0')
        ;
    do
    {
        (Ret *= 10) += ch - '0';
    }
    while (ch = getchar(), ch >= '0' && ch <= '9');
}

const int MOD(998244353);
typedef long long int LL;

inline int Mult(const int &a, const int &b)
{
    return (a * 1LL) * b % MOD;
}

constexpr int Add(int a, int b)
{
    return a + b >= MOD ? a + b - MOD : a + b;
}

int main()
{
    int N, A, Ans(0);
    Get_Val(N);
    for (int i = 1;i <= N;++i)
        Get_Val(A), Ans = Add(Ans, A);
    for (int i = 1;i <= N - 1;++i)
        Ans = Mult(Ans, 2);
    printf("%d", Ans);
    return 0;
}