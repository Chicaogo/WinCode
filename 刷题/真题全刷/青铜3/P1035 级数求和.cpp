#include<iostream>
#include<cstdio>
using namespace std;
double sum=0;
int main()
{
    double n;
    cin>>n;
    for(double i=1;i<=1000000;++i)//ҪС�ķ�Χ��С���ǲ����Եġ�
    {
        sum=sum+1/i;
        if(sum>=n)
        {
            cout<<i;
            return 0;
        }
    }
}