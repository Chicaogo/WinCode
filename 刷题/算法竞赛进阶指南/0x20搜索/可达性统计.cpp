#include<bits/stdc++.h>
using namespace std;

const int maxn = 30000 + 5;
int n,m;
int in[maxn];
vector<int> e[maxn];
vector<int> topo;
bitset<maxn> f[maxn];

inline void toposort()
{
	topo.clear();
	queue<int> q;
	
	for(int i = 1;i <= n;++i)
		if(in[i] == 0) q.push(i);
	
	while(q.size())
	{
		int u = q.front();
		q.pop();
		
		topo.push_back(u);
		
		for(int i = 0;i < e[u].size();++i)
			if(--in[e[u][i]] == 0) q.push(e[u][i]);
	}
	
}

void init()
{
	cin >> n >> m;
	memset(in,0,sizeof(in));
	
	for(int i = 1;i <= m;++i)
	{
		int x,y;
		cin >> x >> y;
		in[y]++;
		e[x].push_back(y);
	}
}

void find()
{
	toposort();
	
	for(int i = topo.size() - 1;i >= 0;i--)
	{
		int x = topo[i];
		f[x].reset(),f[x][x] = 1;
		for(int k = 0;k < e[x].size();++k)
			f[x] |= f[e[x][k]];
	}
	
	for(int i = 1;i <= n;++i)
		cout << f[i].count() << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    init();

    find();
    
    return 0;
}
