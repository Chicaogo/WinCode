#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a=2.5;
    cout<<ceil(a)<<endl;   //向上取整
    cout<<floor(a)<<endl;   //向下取整
    cout<<round(a)<<endl;   //四舍五入
    //不使用函数实现
    //向下取整
    cout<<(int)a<<endl;
    //向上取整
    cout<<(a>(int)a?(int)a+1:(int)a)<<endl;
    //四舍五入
    cout<<(int)(a+0.5)<<endl;
    getchar();
    return 0;
}
