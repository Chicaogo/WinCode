//https://blog.csdn.net/flushhip/article/details/79165701
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lowbit(x) ((x) & -(x))

typedef int *ArrayInt;

int sum(int x, ArrayInt c, int n)
{
    int ret = 0;
    for ( ; x > 0; ret += c[x], x -= lowbit(x));
    return ret;
}

void update(int x, int val, ArrayInt c, int n)
{
    for ( ; x <= n; c[x] += val, x += lowbit(x));
}

int main()
{
    int n, i, m;
    ArrayInt arr = NULL, c = NULL;
    char ope[5];

    scanf("%d", &n);
    arr = (ArrayInt)malloc((n + 1) * sizeof(int));
    c = (ArrayInt)malloc((n + 1) * sizeof(int));
    memset(c, 0, (n + 1) * sizeof(int));
    for (i = 1; i <= n; scanf("%d", arr + i), update(i, arr[i], c, n), ++i);

    for (scanf("%d", &m) ; m--; ) {
        int L, R;
        scanf("%s%d%d", ope, &L, &R);

        switch (ope[0]) {
        case 'F' :
            printf("%d\n", sum(R, c, n) - sum(L - 1, c, n));
            break;
        default :
            update(L, R - arr[L], c, n);
            arr[L] = R;
            break;
        }
    }
    return 0;
}
