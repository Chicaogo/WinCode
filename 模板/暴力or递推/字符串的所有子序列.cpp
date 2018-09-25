#include<bits/stdc++.h>
using namespace std;
inline void chuan(string ch,int i,string res){
    if(i == ch.length()) {
        cout << res << endl;
        return;
    }
    chuan(ch,i+1,res+ch[i]);
    chuan(ch,i+1,res);
}

int main(int argc, char const *argv[])
{
    chuan("abc",0,"");
    getchar();
    return 0;
}