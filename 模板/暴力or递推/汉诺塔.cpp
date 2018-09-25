#include<bits/stdc++.h>
using namespace std;
int ans=0;
inline void tata(int n,string from,string to,string help){
    if(n == 1) cout << ++ans << ".Move " << n <<" from "<< from << " to " << to <<endl;
    else{
        tata(n-1,from,help,to);
        cout << ++ans <<".Move " << n <<" from "<< from << " to " << to <<endl;
        tata(n-1,help,to,from);

    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    tata(n,"a","c","b");
    getchar();getchar();
    return 0;
}
