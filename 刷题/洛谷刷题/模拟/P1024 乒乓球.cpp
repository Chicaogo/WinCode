#include<bits/stdc++.h>
using namespace std;
char a;
int s11a,s21a,s11b,s21b,f21[10000000][2],j;
int main()
{
    while(cin>>a && a!='E') 
    {
        if (a=='W')
        {    
            s11a++;
            s21a++;
        }
        if (a=='L') 
        {
        s21b++;
        s11b++;
        }
        if((s11a>=11&&s11a-s11b>=2)||(s11b>=11&&s11b-s11a>=2)){printf("%d:%d\n",s11a,s11b);s11a=0;s11b=0;};
        if((s21a>=21&&s21a-s21b>=2)||(s21b>=21&&s21b-s21a>=2)){f21[j][0]=s21a;f21[j][1]=s21b;s21a=0;s21b=0;j++;};
    }
    printf("%d:%d\n\n",s11a,s11b);
    for(int i=0;i<j;i++) printf("%d:%d\n",f21[i][0],f21[i][1]);
    printf("%d:%d",s21a,s21b);
    return 0;
}