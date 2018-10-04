#include <bits/stdc++.h>
using namespace std;

int n,a;
long long O,Y,ans=0,sum=0;

int main(int argc, char const *argv[])
{
    scanf("%d%lld%lld",&n,&O,&Y);

    for(int i=1;i<=n-1;++i)
	{
		long long num;
		scanf("%lld",&num);
		sum+=num;
	}

/*
	do
	{
		ans++;
		if(ans>Y)
		{
			printf("wxhwxh\n");
			getchar();getchar();
			return 0;
		}
	} while ((ans+sum)/n < Y);*/

	int mid,L=0,R=O,tong=0;
	
	while(L <= R){
		mid=L+(R-L)/2;
		if((mid+sum)/n > Y)
			R=mid-1;
		else if((mid+sum)/n < Y)
			L=mid+1;
		else if((mid+sum)/n == Y)
		{
			ans=mid;tong=1;
			if(ans<=O)
				printf("%d",ans);
			else if (ans>O)
			{
				printf("wxhwxh\n");
			}
			break;
		}
	}

	if(tong == 0) printf("wxhwxh\n");

	getchar();getchar();
	return 0;
}
