#include<bits/stdc++.h>
using namespace std;
int main( ){
    char c[20]={0},s[1000010]={0},c1;//c1�ǵ��ʵĵ�һ����ĸ������Ѱ�Ҷ�Ӧ��һ����ĸ�飬�������ٶȸ��� 
    int i,j,clen,slen,sum=0,v=-1;//clen��slen���ַ������ȣ��������ٶȸ��죬v=-1�����õ� 
    bool k=0;
    
    gets(c);
    gets(s);
    
    clen=strlen(c);
    slen=strlen(s);
    for(i=0;i<clen;i++)
        if(c[i]>='A' && c[i]<='Z')//��Сдת�� 
            c[i]+=-'A'+'a';

    for(i=0;i<slen;i++)
        if(s[i]>='A' && s[i]<='Z')//��Сдת�� 
            s[i]+=-'A'+'a';

    c1=c[0];//һ����Сдת�������c1����Ȼ�����Ǵ�д��ĸ 
    for(i=0;i<=slen-clen;i++)//������һ����ĸ�������slen-clen+1�����ϵ���ĸƥ��Ҳû�ã�����Ҳ����װ 
        if(s[i]==c1)//�Ƿ����һ����ĸƥ�� 
            if(i==0 || s[i-1]==' '){//����ǰһλ�ǲ��ǿո񣬵��������ǵ�һλ 
                for(j=1;j<clen;j++)//��һƥ�� 
                    if(s[i+j]!=c[j]){
                        k=1;//����ƥ�� 
                        break;
                    }
                if(k==0)//ƥ�� 
                    if(i+clen==slen || s[i+clen]==' '){//��һλ�ǲ��ǿո� 
                        sum++; 
                        if(v==-1)//��¼��һ�� 
                            v=i;
                    }
                k=0;//���㣬�������Ҫ������ 
            }
    
    if(v==-1)//�����ʼ���ն�û�� 
        cout<<-1;
    else
        cout<<sum<<" "<<v;
    
    return 0;
}