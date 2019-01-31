#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> num;

void dfs(int k)
{
    //到达枚举边界，输出结果并结束
    if(k == n + 1)
    {
        for(int i = 0;i < num.size();++i)
            cout << num[i] << " ";
    
        cout << endl;
        return;
    }

    //不选择这个数
    dfs(k+1);

    //选择这个数
    num.push_back(k);
    dfs(k+1);
    //回溯
    num.pop_back();
}

int main(void)
{
    cin >> n;

    dfs(1);

    return 0;
}