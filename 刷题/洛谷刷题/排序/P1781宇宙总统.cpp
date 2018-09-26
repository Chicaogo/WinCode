#include<bits/stdc++.h>
using namespace std;
/*
5
98765
12365
87954
1022356
985678
*/
int main(int argc, char const *argv[])
{
    int n;
    int fuuuuck;
    string max="";
    string in;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        int inSize = in.size();
        int Cnmde = max.size();
        if (inSize > Cnmde || (inSize >= Cnmde && in > max))
        {
            max = in;
            fuuuuck = i + 1;
        }
    }
    cout << fuuuuck << '\n' << max << '\n';
    getchar();getchar();getchar();
    return 0;
}
