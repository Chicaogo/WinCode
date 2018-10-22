#include<bits/stdc++.h>
using namespace std;

const int maxx = 66;
int n,maxn = -maxx,minn = maxx;
int tong[maxx];

void dfs( int res , int sum , int target , int p ) {
    if( res == 0 ) {
        printf("%d", target  );
        exit( 0 );
    }
    if( sum == target ) {
        dfs( res - 1 , 0 , target , maxn );
        return;
    }
    for( int i = p ; i >= minn ; i -- ) { 
        if( tong[ i ] && i + sum <= target ) {
            tong[ i ] -- ;
            dfs( res , sum + i , target , i );
            tong[ i ] ++ ;
            if ( sum == 0 || sum + i == target )
                break;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    
    int x,cnt = 0,sum;

    while(n--)
    {
        scanf("%d",&x);
        if(x <= 50)
        {
            cnt++;
            tong[x]++;
            sum += x;
            maxn = max(maxn,x);
            minn = min(minn,x);
        }
    }

    x = sum/2;

    for(int i = maxn;i <= x;i++)
    {
        if(sum%i == 0)
        {
            dfs(sum/i,0,i,maxn);
        }
    }

    printf("%d",sum);

    return 0;
}
