//https://www.luogu.org/problemnew/show/P1478
#include<bits/stdc++.h>
using namespace std;

int n,s,a,b;
int cnt = 0,ans = 0;
int app[52100];//������ժȡÿ��ƻ�����ĵ�����ֵ

int main(int argc, char const *argv[])
{
    cin >> n >> s >> a >> b;

    for(int i = 0;i < n;++i)
    {
        int x,y;
        cin >> x >> y;
        if(x - b - a <= 0)  //����ѡ�� 
        //�����÷�֤��֤������ƻ���ĸ߶ȸ��ڰ�ʼ����ֵĳ��ȣ�ƻ���϶�ժ����
        {
            app[cnt] = y;
            cnt++;
            //�������ۼ�
        }
    }

    sort(app,app+cnt); 
    //̰�ĵ�ѡ��ÿ������������С��ƻ��

    for(int i = 0;i < cnt;++i)
    {
        s -= app[i];
        if(s >= 0) ans++;
        //���������е�ʱ�� ��++
        if(s < 0) break;
        //����ͬ�������÷�֤��֤��
    }

    cout << ans;

    return 0;
}
/*17�� ��ʡʦ����*/