//http://oj.noi.cn/oj/#main/show/1014
/*
65  Pass
*/
/*
score>=90 Excellent
90>score>=80 Good
80>score>=60 Pass
60>score Fail
*/

#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int score;
    cin>>score;
    if(score>=90) cout<<"Excellent";
    if(score>=80&&score<90) cout<<"Good";
    if(score>=60&&score<80) cout<<"Pass";
    if(score<60) cout<<"Fail";
    getchar();getchar();getchar();
    return 0;
}

