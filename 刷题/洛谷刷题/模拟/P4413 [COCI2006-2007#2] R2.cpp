//https://www.luogu.org/problemnew/show/P4413
#include<bits/stdc++.h>
using namespace std;

int r1 , r2, s;

void init()
{
    //s = (r1 + r2) / 2
    //r1 + r2 = s * 2
    //r2 = s * 2 - r1
    cin >> r1 >> s;
    r2 = s * 2 - r1;
    cout << r2;
}

void find()
{
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    find();

    return 0;
}
