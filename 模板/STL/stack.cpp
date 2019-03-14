#include <stack>
#include <iostream>
using namespace std;
int main()
{
    // 创建堆栈对象
    stack<int> s;
    // 元素入栈
    s.push(3);
    s.push(19);
    s.push(23);
    s.push(36);
    s.push(50);
    s.push(4);
 
    cout << s.size() << endl;
    // 元素依次出栈
    while(!s.empty())
    {
        // 打印栈顶元素，打印出：4 50 36 23 19 3
        cout << s.top() << endl;
        // 出栈
        s.pop();
    }
 
    return 0;
}