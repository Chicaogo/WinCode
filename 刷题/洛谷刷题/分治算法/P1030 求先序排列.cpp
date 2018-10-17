//https://www.luogu.org/problemnew/show/P1030
#include<bits/stdc++.h>
using namespace std;
void fin(string in,string after){
    if (in.size()>0){
        char ch=after[after.size()-1];
        cout<<ch;
        int kkksc03=in.find(ch);
        fin(in.substr(0,kkksc03),after.substr(0,kkksc03));
        fin(in.substr(kkksc03+1),after.substr(kkksc03,in.size()-kkksc03-1));
    }
}
int main(){
    string a,b;
    cin>>a;cin>>b;
    fin(a,b);
    return 0;
}