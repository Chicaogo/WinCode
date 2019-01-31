#include <iostream>
using namespace std;

int n;

// u是当前枚举到的数，state是二进制数记录哪些数被选
void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; i++)
        {
            //判断第i位是不是1，即有没有被选，如果被选就输出
            if (state >> i & 1)
                //因为题目是从1开始的，所以要加1
                cout << i + 1 << " ";
        }
        cout << endl;
        return ;
    }

    //不用这个数，不进行操作
    dfs (u + 1, state);
    //用这个数，把第u位变成1
    dfs (u + 1, state | (1 << u));
}

int main(void) {
    cin >> n;
    dfs(0, 0);
    return 0;
}