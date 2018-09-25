#include<bits/stdc++.h>
using namespace std;
int tata(int n,string from,string to,string help){
    if(n == 1) cout << "Move " << n << ends << from << " to " << to <<endl;
    else{
        tata(n-1,from,help,to);
        cout << "Move " << n << ends << from << " to " << to <<endl;
        tata(n-1,help,to,from);

    }
}
int main(int argc, char const *argv[])
{
    tata(3,"a","b","c");
    getchar();getchar();
    return 0;
}
