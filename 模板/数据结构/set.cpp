#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v;
    //set 的两种数据插入方法（注意：set不可以重集）
    for (int i = 0; i < 10; i++){
            v.push_back(rand()%100);
            v.push_back(rand()%100);
    }
    set<int> s(v.begin(), v.end());
    s.insert(rand()%100);
    //set遍历(set自带排序)
    for (set<int>::iterator it=s.begin(); it != s.end(); it++){
            cout<<*it<<ends;
    }cout<<endl;
    //set长度
    printf("%d\n", v.size());
    s.insert(233);
    printf("%d\n", s.size());
    //set中元素查找
    printf("%d\n", s.count(233));
    printf("%d\n", *(s.find(233)));
    //set中元素删除
    s.erase(233);
    printf("%d\n", s.count(233));
    getchar();
    return 0;
}