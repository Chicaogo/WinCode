#include<bits/stdc++.h>
using namespace std;
int main( ){
    char c[20]={0},s[1000010]={0},c1;//c1是单词的第一个字母，用于寻找对应的一截字母组，让运行速度更快 
    int i,j,clen,slen,sum=0,v=-1;//clen，slen是字符串长度，让运行速度更快，v=-1是有用的 
    bool k=0;
    
    gets(c);
    gets(s);
    
    clen=strlen(c);
    slen=strlen(s);
    for(i=0;i<clen;i++)
        if(c[i]>='A' && c[i]<='Z')//大小写转换 
            c[i]+=-'A'+'a';

    for(i=0;i<slen;i++)
        if(s[i]>='A' && s[i]<='Z')//大小写转换 
            s[i]+=-'A'+'a';

    c1=c[0];//一定大小写转换后存入c1，不然可能是大写字母 
    for(i=0;i<=slen-clen;i++)//搜索第一个字母，如果第slen-clen+1或以上的字母匹配也没用，后面也不够装 
        if(s[i]==c1)//是否与第一个字母匹配 
            if(i==0 || s[i-1]==' '){//看他前一位是不是空格，但还可能是第一位 
                for(j=1;j<clen;j++)//逐一匹配 
                    if(s[i+j]!=c[j]){
                        k=1;//并不匹配 
                        break;
                    }
                if(k==0)//匹配 
                    if(i+clen==slen || s[i+clen]==' '){//后一位是不是空格 
                        sum++; 
                        if(v==-1)//记录第一个 
                            v=i;
                    }
                k=0;//归零，这个很重要！！！ 
            }
    
    if(v==-1)//如果自始至终都没有 
        cout<<-1;
    else
        cout<<sum<<" "<<v;
    
    return 0;
}