#include<bits/stdc++.h>
using namespace std;
//递归爆搜版 0-1背包问题
const int MAX_N=30;
int w[MAX_N],v[MAX_N];
//w_i 代表重量 v_i 代表价值
int n,W;

int rec(int i,int j)
//搜索 从第 i 个物品开始挑选总重小于 j 的部分
{
    int res;
    if(i==n) {res = 0;}
    //已经没有剩余的物品
    else if (j < w[i]) {rec(i+1, j);}
    //无法挑选这个物品
    else {res = max(rec(i+1,j) , rec(i+1,j-w[i])+v[i]);}
    //要和不要选最大的值
    cout << res << ends;
    return res;
}

int main(int argc, char const *argv[])
{
    cin>> n >> W;
    
    for(int i=0;i<n;++i) cin >> w[i] >> v[i];

    rec(0,W);

    getchar();getchar();
    return 0;
}

/*
4 5
2 3
1 2
3 4
2 2

7
*/