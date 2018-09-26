#include<bits/stdc++.h>
using namespace std;

struct qwq
{
    int mark,number;
    bool operator < (const qwq &a) const{
        if(mark>a.mark) return mark>a.mark;
        else if(mark == a.mark) {
            if(number<a.number) return true;
            else return false;
        }
        else return false;
    }
}fuck[100086];
/*6 3
1000 90
3239 88
2390 95
7231 84
1005 95
1001 88*/
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;++i) cin>>fuck[i].number>>fuck[i].mark;
    sort(fuck,fuck+n);
    int wow=(m-1)*1.5,ans=0;
    int Garde = fuck[wow].mark;
    for(int i = 0;i < n;++i) if(fuck[i].mark>=Garde) ans++;
    cout<<Garde<<" "<<ans<<endl;
    for(int i = 0;i < ans;++i) cout<<fuck[i].number<<" "<<fuck[i].mark<<endl;
    //getchar();getchar();getchar();
    return 0;
}
