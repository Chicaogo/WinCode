#include<bits/stdc++.h>
using namespace std;
//�ݹ鱬�Ѱ� 0-1��������
const int MAX_N=30;
int w[MAX_N],v[MAX_N];
//w_i �������� v_i �����ֵ
int n,W;

int rec(int i,int j)
//���� �ӵ� i ����Ʒ��ʼ��ѡ����С�� j �Ĳ���
{
    int res;
    if(i==n) {res = 0;}
    //�Ѿ�û��ʣ�����Ʒ
    else if (j < w[i]) {rec(i+1, j);}
    //�޷���ѡ�����Ʒ
    else {res = max(rec(i+1,j) , rec(i+1,j-w[i])+v[i]);}
    //Ҫ�Ͳ�Ҫѡ����ֵ
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