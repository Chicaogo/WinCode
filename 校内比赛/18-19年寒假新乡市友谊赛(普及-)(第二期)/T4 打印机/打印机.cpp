#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    freopen("9.in","r",stdin);
	freopen("9.out","w",stdout); 
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
    
    while(true)
    {
        if(q.front() == pq.top())
        {
            if(x == top)
            {
                cout << n - q.size() + 1;
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

	return 0;
}
