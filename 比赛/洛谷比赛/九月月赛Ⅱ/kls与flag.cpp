/*
题目描述
有n个Ol选手，每个人插了一个flag。有一天因为某种原因，flag都被触发了，所以地上有一排n根竹竿，竹竿的间距均为一个单位长度，高度在1~m之间。
kls看到这些竹竿，感觉不好看，于是准备把它们全部放倒。
在这之前，kls想到了一个数学问题。每根竹竿可以往左倒或者往右倒。如果两根竹竿在选择方向放倒之后，它们的顶端可以重合，那么称它们是优秀的。现在kls想要知道，有多少对竹竿是优秀的。
输入输出格式
输入格式：
第一行两个数n，m，表示竹竿的个数和最大高度。
第二行n个正整数，表示每根竹竿的高度。
输出格式：
输出一行，只有一个数，表示有多少对竹竿是优秀的。
输入样例:
5 5
2 3 3 3 2
输出样例:
3
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 200010;
int d[MAX],b[MAX];
int main(int argc, char const *argv[])
{
    int n;//杆的数目
    long long m;
    scanf("%d%lld",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        long long num;
        scanf("%lld",&num);
        d[i]=i-num;
        b[i]=i+num;
    }
    sort(d+1,d+n+1);
    sort(b+1,b+n+1);
    int ans=0;
    for(int i = 1; i < n; i++)
    {
        if(d[i]==d[i+1]) ++ans;
        if(b[i]==b[i+1]) ++ans;
    }
    int z=1,c=1,w=0;
    while(z < n+1 && c < n+1)
    {
        if(d[z]==b[c]) {ans++;c++;z++;}
        else if(d[z]>b[c]) c++;
        else if(d[z]<b[c]) z++;
    }
    cout << ans <<endl;
    getchar();getchar();getchar();
    return 0;
}