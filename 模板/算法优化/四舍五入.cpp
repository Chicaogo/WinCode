#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a=2.5;
    cout<<ceil(a)<<endl;   //����ȡ��
    cout<<floor(a)<<endl;   //����ȡ��
    cout<<round(a)<<endl;   //��������
    //��ʹ�ú���ʵ��
    //����ȡ��
    cout<<(int)a<<endl;
    //����ȡ��
    cout<<(a>(int)a?(int)a+1:(int)a)<<endl;
    //��������
    cout<<(int)(a+0.5)<<endl;
    getchar();
    return 0;
}
