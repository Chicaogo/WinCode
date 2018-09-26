#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        int num;
        scanf("%d",&num);
        if (num) {
            if(i!=n&&num>0)cout<<"+";    
            if(abs(num)>1||i==0)cout<<num;  
            if(num==-1&&i)cout<<"-";   
            if(i>1)cout<<"x^"<<i;  
            if(i==1)cout<<"x";   
        }
    }
    getchar();getchar();getchar();getchar();
    return 0;
}
