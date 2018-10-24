#include<bits/stdc++.h>
using namespace std;
int a,i,num1,num2,num3,x;
int qwq(int x)
{
    for (i=2;i<=sqrt(x);i++)
        if (x%i==0)
            return 1;
    return 0;
}
int main(void)
{
    cin>>a;
    for (num1=2;num1<=a-4;num1++)
        for (num2=2;num2<=a-4;num2++)
        {
            num3=a-num1-num2;
            if (qwq(num1)+qwq(num2)+qwq(num3)!=0)
                continue;
            cout<<num1<<' '<<num2<<' '<<num3;
        }
    return 0;
}