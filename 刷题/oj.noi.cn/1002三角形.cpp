#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    float a,b,c,p,s;
    scanf("%f%f%f",&a,&b,&c);
    p = (a+b+c)/2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.4f",s);
    getchar();getchar();
    return 0;
}
