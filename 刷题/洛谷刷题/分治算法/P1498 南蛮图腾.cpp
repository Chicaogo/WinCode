#include<iostream>
using namespace std;

char a[1024][2048];

int main(void)
{
    ios::sync_with_stdio(false);//����ٶ��Ż� 

    int n,length=4,k=1;//length��ʾ��ǰͼ�ڵĿ�length/2��ͼ�ڵĸ� 
    cin>>n;
    for(int i=0;i<1024;i++)
        for(int j=0;j<2048;j++)
            a[i][j]=' ';//��ȫ����Ϊ�ո�(����������ĩ�ո�2333) 
    
    a[0][0]=a[1][1]='/',a[0][1]=a[0][2]='_',a[0][3]=a[1][2]='\\';//��n=1ʱ�Ļ���ͼ�ڣ����ŵģ� 
        
    while(k<n)//���ϸ��� 
    {
        for(int i=0;i<length/2;i++)
        for(int j=0;j<length;j++)
        a[i+(length/2)][j+(length/2)]=a[i][j+length]=a[i][j];
        length*=2,k++;
    } 
    
    for(int i=(length/2)-1;i>=0;i--)//������� 
    {   
        for(int j=0;j<length;j++)
        cout<<a[i][j]; 
        cout<<endl;
    }
    return 0;
}