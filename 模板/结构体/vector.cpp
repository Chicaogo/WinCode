#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> zz;
    int n = 10;
    //vector数据添加
    for(int i = 0; i < n; i++)
    {
        zz.push_back(rand()%100);
    }
    //vector数据遍历 
    for(int i = 0; i < zz.size(); i++)
    {
        cout<<zz[i]<<ends;
    }cout<<endl;
    getchar();
    return 0;
}
