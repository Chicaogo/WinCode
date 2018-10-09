#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
char txt[20] = "0123456789ABCDEF";
int n;
string m;

bool fuck(string a)
{
    string s = a;
    reverse(s.begin(),s.end());
    return s == a;
}

string addddd(int k, string b) { //高精度加法过程，推广到 k 进制
    string a = b;
    reverse(a.begin(), a.end());
    int numa[maxn], numb[maxn], numc[maxn];
    int len = a.length(), lenc = 1;
    string ans;
    for (int i=0; i<len; i++) {
        if (isdigit(a[i])) numa[len-i] = a[i] - '0'; //对于十六进制的特判，如果是数字减去 0 ，下同
        else numa[len-i] = a[i] - 'A' + 10; //如果不是数字减去 A 再加上 10
        if (isdigit(b[i])) numb[len-i] = b[i] - '0';
        else numb[len-i] = b[i] - 'A' + 10;
    }
    int x = 0;
    while (lenc <= len) {
        numc[lenc] = numa[lenc] + numb[lenc] + x;
        x = numc[lenc] / k; //把除以 10 修改为除以 k
        numc[lenc] %= k; //这里把对 10 取模修改为对 k 取模
        lenc++;
    }
    numc[lenc] = x;
    while (numc[lenc] == 0) lenc--;
    for (int i=lenc; i>=1; i--) ans += txt[numc[i]];
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
      for (int i=0; i<=30; i++){ //模拟过程
        if(fuck(m)) { //如果是回文数就输出步骤数
            printf("STEP=%d", i);
            return 0;
        }
        else m = addddd(n, m);
    }
    printf("Impossible!"); //如果超过 30 步则输出 Impossible!  
    
    return 0;
}
