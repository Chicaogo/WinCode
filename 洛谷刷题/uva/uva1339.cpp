#include<bits/stdc++.h>
#define MAX 26
using namespace std;
int main(){
	int num1[MAX],num2[MAX];
	string rxz,zcy;
	while(cin>>rxz>>zcy){
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		size_t len=rxz.length();
		for(size_t i=0;i<len;i++){
			++num1[rxz[i]-'A'];
			++num2[zcy[i]-'A'];
		}
		sort(num1,num1+MAX);
		sort(num2,num2+MAX);
		bool ans=1;
		for(size_t i=0;i<26;i++){
			if(num1[i]!=num2[i]) {ans=0;break;}
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
