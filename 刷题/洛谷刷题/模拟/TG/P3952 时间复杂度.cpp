#include<bits/stdc++.h>
using namespace std;

string one,two;
int q,N,ans;            //q�����ӣ�N��ĿҪ���Ӷȣ�ans��ǰ�ڵڼ���ѭ��
int tong[27],qwq[27];   //tongͳ�Ʊ������Ƿ��ù��ˣ�qwq����ÿ��ѭ���ı���   
int v,cnt;              //v�ǵ�ǰ���ﵽ�ĸ��Ӷȣ�cnt���г����Ƿ����ִ��
int l[110],n;           //l������Ǹ����������˸��Ӷȣ�n���¶��ٴ�ѯ��
int k,qaq,m;

int main(int argc, char const *argv[])
{
    cin >> n;
    while(n--)
    {
        q=N=ans=v=cnt=k=qaq=m=0;
        memset(tong,0,sizeof(tong));
        memset(l,0,sizeof(l));
        do
        {
            one=two;
            cin >> two;
        }while(two[0]!='O');

        for(int i=0;i < one.length();++i) q = q*10+one[i]-'0';
        for(int i=4;i < two.length()-1;++i) N = N*10+two[i]-'0';

        while(q > 0)
        {
            q--;
            cin >> one;
            if(one[0] == 'F')
            {
                ans++;
                cin >> one;
                
                if(tong[one[0]-96]) ans = -1;
                else tong[one[0]-96] = 1,qwq[ans] = one[0]-96;

                cin >> one >> two;

                if(one[0] != 'n' && two[0] == 'n' && k==0) v++,l[ans] = 1;
                else if(((one.length()==two.length()&&one>two)||(one.length()>two.length())||(one[0]=='n'&&two[0]!='n'))&&k==0)
                {
                    k = 1;
                    qaq = ans;
                }
            }
            else
            {
                m = max(m,v);
                tong[qwq[ans]] = 0;

                if(l[ans]==1) v--,l[ans] = 0;
                ans--;
                if(qaq>0 && ans<qaq) k = 0,qaq = 0; 
            }

            if(ans == -1) 
            {
                cout << "ERR" << endl;
                q=-1;
            }
        }

        if(ans > 0) cout << "ERR";
        if(ans == 0 && m == N) cout << "Yes" << endl;
        if(ans == 0 && m != N) cout << "No" << endl;
    }
    return 0;
}
