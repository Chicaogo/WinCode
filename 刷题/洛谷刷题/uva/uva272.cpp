#include<bits/stdc++.h>
using namespace std;
int main() {
    int rxz,q=1;
    while((rxz=getchar())!=EOF) {
        if(rxz=='"'){printf("%s",q?"``":"''");q=!q;}
        else printf("%c",rxz);
    }
    return 0;
}
