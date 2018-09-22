#include <bits/stdc++.h>
using namespace std;
typedef struct edge{
    int u,v;
    edge(int _u,int _v):u(_u),v(_v){}
    edge(){}
}e[100086] ;
void dfs(int u){

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        e[i]=edge(u,v);
    }
    return 0;
}
