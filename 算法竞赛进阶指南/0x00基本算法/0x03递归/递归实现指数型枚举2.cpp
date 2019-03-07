#include <iostream>
using namespace std;

int n;

// u�ǵ�ǰö�ٵ�������state�Ƕ���������¼��Щ����ѡ
void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; i++)
        {
            //�жϵ�iλ�ǲ���1������û�б�ѡ�������ѡ�����
            if (state >> i & 1)
                //��Ϊ��Ŀ�Ǵ�1��ʼ�ģ�����Ҫ��1
                cout << i + 1 << " ";
        }

        cout << endl;
        return ;
    }

    //����������������в���
    dfs (u + 1, state);

    //����������ѵ�uλ���1
    dfs (u + 1, state | (1 << u));
}

int main(void) {
    
    cin >> n;
    
    dfs(0, 0);
    
    return 0;
}