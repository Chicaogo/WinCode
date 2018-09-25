#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    map<int,string> mapStudent;
    //第一种加数据方式
    mapStudent.insert(pair<int,string>(1,"student_one"));
    //第二种加数据方式
    mapStudent.insert(map<int,string>::value_type(2,"student_two"));
    //第三种加数据方式
    mapStudent[3]="student_three";
    //mapStudent[3]="student_//three";

    //map遍历
    for(map<int,string>::iterator i = mapStudent.begin(); i != mapStudent.end(); i++)
    {
        cout<<i->first<<ends<<i->second<<endl;
    }cout<<endl;
    //第二种遍历 反向遍历
    for(map<int, string>::reverse_iterator iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
    {
        cout<<iter->first<<ends<<iter->second<<endl;
    }cout<<endl;
    //第三种遍历
    for(int i = 1; i <= mapStudent.size(); i++)
    {
        cout<<i<<ends<<mapStudent[i]<<endl;
    }cout<<endl;
    
    //查找并获取map中的元素
    //第一种 用 count函数 返回值只有两个 0 or 1
    cout<<mapStudent.count(1)<<ends<<mapStudent.count(6)<<endl;
    //第二种 用 find 定位数据出现位置 返回其迭代器
    map<int, string>::iterator iter;  
    iter = mapStudent.find(1);  
    if(iter != mapStudent.end())  
       cout<<"Find, the value is "<<iter->second<<endl;  
    else
       cout<<"Do not Find"<<endl; 
    cout<<endl;

    //map元素删除
    mapStudent.erase(1);//如果删除了会返回1，否则返回0 
    //清空 map
    mapStudent.erase(mapStudent.begin(),mapStudent.end());
    
    //map默认升序排列
    getchar();
    return 0;
}
