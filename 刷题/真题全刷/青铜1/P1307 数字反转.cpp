#include<iostream>
using namespace std;
int main()
{
  int n;  cin>>n;   //��ת֮ǰ����
  if(n<0) {cout<<"-";n=-n;}  //��������������ת�������������������Ǹ����������һ��"-"
  if(n%10==0) {n=n/10;}  //���һ���������һλΪ0��ȥ������
  int sum=0;    //��ת֮�����
  while(n!=0)
  {
    int k=n%10;
    sum=sum*10+k;   //sum*10+k����˼����ԭ��sum�Ļ�������չһ����λ���洢k���е���ջ�Ĳ�����
    n=n/10;   //ȥ��һλ
  }
  cout<<sum<<endl;
  return 0;
}