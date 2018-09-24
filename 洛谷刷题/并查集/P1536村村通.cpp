/*
题目描述
某市调查城镇交通状况，得到现有城镇道路统计表。表中列出了每条道路直接
连通的城镇。市政府“村村通工程”的目标是使全市任何两个城镇间都可以实现
交通（但不一定有直接的道路相连，只要相互之间可达即可）。请你计算出最
少还需要建设多少条道路？
输入输出格式
输入格式：
每个输入文件包含若干组测试测试数据，每组测试数据的第一行给出两个用空
格隔开的正整数，分别是城镇数目N（N<1000）和道路数目M；随后的M行对应
M条道路，每行给出一对用空格隔开的正整数,分别是该条道路直接相连的两个
城镇的编号。简单起见，城镇从1到N编号。
注意：两个城市间可以有多条道路相通。例如：
3 3 1 2 1 2 2 1 这组数据也是合法的。当N为0时，输入结束。
输出格式：
对于每组数据，对应一行一个整数。表示最少还需要建设的道路数目。
输入输出样例:
输入：
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
输出：
1
0
2
998
*/
#include<bits/stdc++.h>
int fa[20010];

int fin(int a){
    if(fa[a] == a) return a;
    else return fin(fa[a]);
}
int main(int argc, char const *argv[])
{
    int n; scanf("%d",&n);
    int m; 

    while(n){
        scanf("%d",&m);
        int t[10010];
        memset(t,0,sizeof(t));
        for(int i = 1;i <= n;i++ ) fa[i]=i;
        for(int i = 1;i <= m;i++ ){
            int a,b;
            scanf("%d%d",&a,&b);
            int k1=fin(b);
            fa[k1]=fin(a);
        }
        for(int i = 1; i <= n; i++) fa[i] = fin(fa[i]);
        for(int i = 1; i <= n; i++) t[fa[i]] ++;
        int ans=0;
        for(int i = 1; i <= 1000; i++) if(t[i]) ans++;
        printf("%d\n",ans-1);
        scanf("%d",&n);
    }
    return 0;
}
