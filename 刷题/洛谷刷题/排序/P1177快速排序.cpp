#include<algorithm>
#include<cstdio>
using namespace std;
int num[10000010],n; 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num,num+n);
	for(int i=0;i<n;i++) printf("%d ",num[i]);
	return 0;
} 
