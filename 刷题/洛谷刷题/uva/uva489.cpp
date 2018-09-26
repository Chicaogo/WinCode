#include<bits/stdc++.h>
using namespace std;

int len;
int seven;
string s1,s2;
bool win,lose;

inline int read(){
	char c;int x=0,t=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}return x*t;
}

void guess(char rxz){
	bool bad=1;
	for(int i=0;i<s1.length();i++){
		if(s1[i]==rxz){
			bad=0;
			s1[i]=' ';
			len--;
		}
	}
	if(bad) seven--;
	if(!len) win=1;
	if(!seven) lose=1;
}

int main(void){
	int tp;
	while(2333){
		tp=read();
		if(tp==-1) break;
		seven=7;win=0;lose=0;
		cin>>s1>>s2;
		printf("Round %d\n",tp);
		len=s1.length();
		for(int i=0;i<s2.length();i++){
			guess(s2[i]);
			if(win||lose) break;
		}
		if(win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
} 
