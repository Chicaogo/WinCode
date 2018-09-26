#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    set<int> ss;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        ss.insert(num);
    }
    cout<<ss.size()<<endl;
    for(set<int>::iterator it=ss.begin();it != ss.end();it++){
        cout<<*it<<ends;
    }
    getchar();getchar();getchar();
    return 0;
}
