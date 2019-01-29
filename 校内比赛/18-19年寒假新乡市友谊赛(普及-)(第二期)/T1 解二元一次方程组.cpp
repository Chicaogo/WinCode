#include<bits/stdc++.h>
using namespace std;

int a1,a2,b1,b2,c1,c2;
double x,y,cnt,cntx,cnty;

void init()
{
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    c1 = -c1;
    c2 = -c2;
}

void find()
{
    //¿ËÀ³Ä·¹æÔò
    cnt = a1*b2 - a2*b1;
    cntx = c1*b2 - b1*c2;
    cnty = a1*c2 - a2*c1;
    if(cnt == 0) cout << "No answer£¡";
    else printf("%.2lf %.2lf",cntx/cnt,cnty/cnt);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    find();

    getchar();getchar();getchar();
    return 0;
}
