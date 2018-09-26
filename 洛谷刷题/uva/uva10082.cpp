#include<bits/stdc++.h>
using namespace std;
char rxz[]="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
int main(){
	int i,zcy;
	while((zcy=getchar())!=EOF){
		for(i=1;rxz[i]&&rxz[i]!=zcy;i++);
		if(rxz[i]) putchar(rxz[i-1]);
		else putchar(zcy);
	}
	return 0;
}
