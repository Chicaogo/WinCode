#include<bits/stdc++.h>
using namespace std;

string one,two;
int q,N,ans;            //q个句子，N题目要求复杂度，ans当前在第几层循环
int tong[27],qwq[27];   //tong统计变量名是否用过了，qwq存下每个循环的变量   
int v,cnt;              //v是当前所达到的复杂度，cnt特判程序是否继续执行
int l[110],n;           //l数组存那个数组增加了复杂度，n存下多少次询问
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
