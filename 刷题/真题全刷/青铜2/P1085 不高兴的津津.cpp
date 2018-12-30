#include<iostream>
using namespace std;
int main(){
    int i,day=0,a,b,max=0,num;
    for (i=0;i<7;i++){
        cin>>a>>b;
        if((a+b)>8&&(a+b)>max) {
            max=a+b;
            day=i+1;
        }
    }
    cout<<day;
    return 0;
}