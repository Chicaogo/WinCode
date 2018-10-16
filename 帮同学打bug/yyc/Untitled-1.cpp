#include<iostream>
#include<cstdio>
using namespace std;

int a[32][32];
int ha=0;
int main()
{   

    int s;
    cin>>s;
    for(int ax=1;ax<=s;ax++)
        for(int ay=1;ay<=s;ay++)
        {
            cin>>a[ax][ay];
        }

    for(int ax=1;ax<=s;ax++)
        for(int ay=1;ay<=s;ay++)
        {
            if(a[ax][ay-1]==0&&a[ax][ay]==1&&ha==0)
                {ha=1;
                cout<<1<<endl;}
            if(a[ax][ay]==0&&ha==1)
                {a[ax][ay]=2;
                cout<<2<<endl;}
            if(a[ax][ay]==1&&a[ax][ay+1]==0&&ha==1)
                {ha=0;
                cout<<0<<endl;}
        }
    /*int x,y;
    for(;;)
    {
    cin>>x>>y;
    cout<<a[x][y]<<endl;}*/
    for(int ax=1;ax<=s;ax++)
        {
            for(int ay=1;ay<=s;ay++)
            {
                cout<<a[ax][ay]<<" ";
            }
            cout<<"\n";
        }
} 