#include <cstdio>

int main(void)
{
    int N,lin,cnt=0,ord;

    scanf("%d",&N);

    for(lin=1;cnt<N;lin++)
        cnt+=lin;
    lin--;cnt-=lin;

    ord=N-cnt;

    if(lin%2==0)
        printf("%d/%d",ord,lin-ord+1);
    else
        printf("%d/%d",lin-ord+1,ord);

    getchar();getchar();getchar();
    return 0;
}