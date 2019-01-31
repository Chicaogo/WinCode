#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> num;

void dfs(int k)
{
    if(k == n + 1)
    {
        for(int i = 0;i < num.size();++i)
            cout << num[i] << " ";
    
        cout << endl;
        return;
    }

    dfs(k+1);

    num.push_back(k);
    dfs(k+1);
    num.pop_back();
}

int main(void)
{
    cin >> n;

    dfs(1);

    return 0;
}