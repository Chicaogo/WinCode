#include <bits/stdc++.h>
using namespace std;

int n,k,a[200010],c[20000000];

int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&k);

	for(int i=1;i<=n;++i) scanf("%d",&a[i]);

	int cnt = 0;

    for(int i=1;i<n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(a[i]-a[j]>=0)
				{c[cnt]=a[i]-a[j];cnt++;}
			if(a[i]-a[j]<0)
				{c[cnt]=a[j]-a[i];cnt++;}
		}
	}

	sort(c,c+cnt);

    printf("%d",c[k-1]);

	getchar();getchar();getchar();
    return 0;
}
