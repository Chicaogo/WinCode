#include<bits/stdc++.h>
using namespace std;

int t;

inline void find()
{
	queue<int> q;
	priority_queue<int> pq;
	int n,top;
	cin >> n >> top;
	
	for(int i = 0;i < n;++i)
	{
		int num;
		cin >> num;
		q.push(num);
		pq.push(num);
	}
	
	int x = 0;
	
	while(1)
	{
		if(q.front() == pq.top())
		{
			if(x == top)
			{
				cout << n - q.size() + 1 << endl;
				break;
			}
			else
			{
				q.pop();
				pq.pop();
				x++;
			}
		}
		else
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
			if(x == top)
			{
				x = 0;
				top = q.size() - 1;
			}
			else x++;
		}
	}
}

int main(void)
{
	cin >> t;
	
	for(int i = 1;i <= t;++i)
		find();

	return 0;
}