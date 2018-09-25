#include<bits/stdc++.h>
using namespace std;

struct student{
    int grade;
    string name;
};
struct cmp{
    bool operator() (student s1,student s2){
    return s1.grade < s2.grade;
    }
};

int main(int argc, char const *argv[])
{
    int n=10,num;
    /*
    1. push 【入队插到队尾】

    2. pop 【队首元素出队】

    3. size 【返回队列中元素的个数】

    4. front 【返回队列中第一个元素】

    5. back 【返回队列中最后一个元素】

    6. empty 【判断队列是否为空】
    */
    //cout<<"队列:"<<endl;
    queue<int> a;
    for(int i=1;i<n;i++){
        num = rand()%233;
        a.push(num);
    }
    //数列长度
    cout<<a.size()<<endl;
    //数列头元素
    cout<<a.front()<<endl;
    //数列尾元素
    cout<<a.back()<<endl;
    //数列是否为空
    while(!a.empty()){
        cout<<a.front()<<ends;
        a.pop();
    }cout<<endl<<endl;
    
    priority_queue<int> pq_1;
    for(int i=1;i<n;i++){
        num = rand()%233;
        pq_1.push(num);
    }
    //默认情况下，数值大的在队首位置(降序)
    while(!pq_1.empty()){
        //注意这里的访问头元素为.top
        cout<<pq_1.top()<<ends;
        pq_1.pop();
    }cout<<endl;
    
    //以下情况下，数值小的在队首位置(升序)
    priority_queue<int,vector<int>,greater<int> > pq_2;
    for(int i=1;i<n;i++){
        num = rand()%233;
        pq_2.push(num);
    }

    while(!pq_2.empty()){
        //注意这里的访问头元素为.top
        cout<<pq_2.top()<<ends;
        pq_2.pop();
    }cout<<endl;cout<<endl;
    
    //运算符重载
    
    priority_queue<student,vector<student>,cmp> q;
    student s1,s2,s3;
    s1.grade = 90;
    s1.name = "Tom";

    s2.grade = 80;
    s2.name = "Jerry";

    s3.grade = 100;
    s3.name = "Kevin";

    q.push(s1);
    q.push(s2);
    q.push(s3);

    while(!q.empty()){
        cout<<q.top().name<<":"<<q.top().grade<<endl;
        q.pop();
    } 
    getchar();
    return 0;
}