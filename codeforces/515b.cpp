#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m,i;
	vector<int> boy,girl;
	cin>>n>>m;
	boy.resize(n);girl.resize(m);
	int b,g,x;
	cin>>b;
	while(b--)
	{
		cin>>x;
		boy[x]=1;
	}
	cin>>g;
	while(g--)
	{
		cin>>x;
		girl[x]=1;
	}
	for(i=0;i<1000000;i++)
	{
		int b1,g1;
		b1 = i%n;b1 = b1 + n;b1 = b1%n;
		g1 = i%m;g1 = g1 + m;g1 = g1%m;
		if(boy[b1]==1)
			girl[g1]=1;
		if(girl[g1]==1)
			boy[b1]=1;
	}
	bool done = true;
	for(i=0;i<n;i++)
	{
		if(boy[i]==0)
		{
			done = false;
			break;
		}
	}
	for(i=0;i<m;i++)
	{
		if(girl[i]==0)
		{
			done = false;
			break;
		}
	}
	if(done)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}