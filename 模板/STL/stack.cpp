#include <stack>
#include <iostream>
using namespace std;
int main()
{
    // ������ջ����
    stack<int> s;
    // Ԫ����ջ
    s.push(3);
    s.push(19);
    s.push(23);
    s.push(36);
    s.push(50);
    s.push(4);
 
    // Ԫ�����γ�ջ
    while(!s.empty())
    {
        // ��ӡջ��Ԫ�أ���ӡ����4 50 36 23 19 3
        cout << s.top() << endl;
        // ��ջ
        s.pop();
    }
 
    return 0;
}