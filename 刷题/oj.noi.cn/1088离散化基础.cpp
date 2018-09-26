#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>//STL要用此头文件 
using namespace std;
int sub[10000],n;
int a[10000];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&sub[i]),a[i]=sub[i];
	sort(sub,sub+n);
	int size=unique(sub,sub+n)-sub;
	for(int i=0;i<n;i++)
	    a[i]=lower_bound(sub,sub+size,a[i])-sub+1;
	for(int i=0;i<n;++i) cout<<a[i]<<' ';
    getchar();getchar();getchar();getchar();getchar();
	return 0;
}
