#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	long long int n,i;
	cin>>n;
	long long int maxn = 2*n;
	for(i=1;i<=n;i++)
		maxn = maxn*i;
	int k1,k2;
	queue<int> q1;
	queue<int> q2;
	cin>>k1;
	int x;
	for(i=0;i<k1;i++)
	{
		cin>>x;
		q1.push(x);
	}
	cin>>k2;
	for(i=0;i<k2;i++)
	{
		cin>>x;
		q2.push(x);
	}
	for(i=0;i<maxn;i++)
	{
		if((!q1.empty())&&(!q2.empty()))
		{
			int n1 = q1.front();
			q1.pop();
			int n2 = q2.front();
			q2.pop();
			if(n1>n2)
			{
				q1.push(n2);
				q1.push(n1);
			}
			else
			{
				q2.push(n1);
				q2.push(n2);
			}

		}
		else if(q1.empty())
		{
			cout<<i<<" "<<2<<'\n';
			return 0;
		}
		else
		{
			cout<<i<<" "<<1<<'\n';
			return 0;
		}

	}
	cout<<-1;
	return 0;
}