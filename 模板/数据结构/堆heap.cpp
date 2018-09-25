#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    vector<int> a;
    int num,n=10;
    for(int i=0;i<n;i++)
    {
        num = rand()%(233*2);
        a.push_back(num);
    }
    
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) 
    {
        cout<<*i<<ends;
    }cout<<endl<<endl;

    make_heap(a.begin(),a.end());//默认的大根堆
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) 
    {
        cout<<*i<<ends;
    }cout<<endl<<endl;

    make_heap(a.begin(),a.end(),cmp);//自制的小根堆
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) 
    {
        cout<<*i<<ends;
    }cout<<endl<<endl;

    a.push_back(2333);
    push_heap(a.begin(),a.end(),cmp);//将新加的元素加入堆中
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) 
    {
        cout<<*i<<ends;
    }cout<<endl<<endl;
    
    a.pop_back(); //删除尾部
    for(vector<int>::iterator i=a.begin();i!=a.end();i++) 
    {
        cout<<*i<<ends;
    }cout<<endl<<endl;

    getchar();getchar();getchar();getchar();
    return 0;
}