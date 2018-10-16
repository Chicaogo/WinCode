#include<bits/stdc++.h>
using namespace std;

inline int lobit(int x)
{
    return x & (-x);
}

int main(int argc, char const *argv[])
{
    int a[1234];
    
    for(int i = 0; i < 100 ;++i)
    {
        a[i] = i + 1;
        cout << a[i] << ": " << lobit(a[i]) << endl ;
    }

    getchar();
    return 0;
}
