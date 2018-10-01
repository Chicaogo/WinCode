#include<bits/stdc++.h>
using namespace std;
int num[520000],cnt[520000];
long long ans=0,n;
void gsort(int L,int R){
    if(L == R) return;
    int mid = (L+R)/2;
    gsort(L,mid);
    gsort(mid+1,R);
    //cout<<L<<ends<<R<<endl;
    int i = L,j = mid + 1,k = L;
    while(i <= mid && j <= R){
        if(num[i] <= num[j]){
            cnt[k]=num[i];
            k++;
            i++;
        }
        else{
            cnt[k]=num[j];
            k++;
            j++;
            ans+=mid-i+1;
        }
    }
    while(i<=mid){cnt[k]=num[i];k++;i++;}
    while(j<=R){cnt[k]=num[j];k++;j++;}
    for(int qwq=L;qwq<=R;qwq++) {num[qwq]=cnt[qwq];}
}

int main(int argc, char const *argv[])
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    gsort(1,n);
    //for(int i=1;i<=n;i++) cout<<cnt[i]<<ends;
    printf("%lld\n",ans);
    getchar();getchar();getchar();
    return 0;
}
