#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,t;
	cin>>n>>t;
	char x;
	int i;
	vector<int> l;
	l.resize(n);
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x=='B')
			l[i]=1;
		else
			l[i]=0;
	}
	while(t--)
	{
		for(i=0;i<(n-1);i++)
		{
			if(l[i]==1&&l[i+1]==0)
			{
				l[i]=0;
				l[i+1]=1;
				i=i+1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(l[i]==1)
			cout<<'B';
		else
			cout<<'G';
	}
	return 0;
}