#include<bits/stdc++.h>
using namespace std;
int ans=0;
inline void chuan(string ch,int i,string res){
    if(i == ch.length()) {
        ++ans;
        cout << res << ends <<ans <<endl;
        return;
    }
    chuan(ch,i+1,res+ch[i]);
    chuan(ch,i+1,res);
}

int main(int argc, char const *argv[])
{
    chuan("123456",0,"");
    getchar();
    return 0;
}