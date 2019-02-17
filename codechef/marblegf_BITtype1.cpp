#include <iostream>
#include <vector>
using namespace std;
vector<long long int> a;
long long int n;
void update(long long int loc,long long int val)
 {
 	while(loc<=n)
 	{
 		a[loc]=a[loc]+val;
 		loc = loc + (loc&(-loc));
 	}
 }
long long int sum(long long int loc)
{
	long long int ans = 0;
	while(loc>=1)
	{
		ans = ans + a[loc];
		loc = loc - (loc&(-loc));
	}
	return ans;
}
long long int rangesum(long long int start,long long int end)
{
	return (sum(end) - sum(start-1));
}
int main()
{
	long long int q,i,x;
	cin>>n>>q;
	a.resize(n+1);
	for(i=0;i<n;i++)
	{
		cin>>x;
		update(i+1,x);
	}
	char y;
	long long int xx;
	while(q--)
	{
		cin>>y;
		if(y=='S')
		{
			cin>>x>>xx;
			cout<<rangesum(x+1,xx+1)<<"\n";
		}
		else if(y=='G')
		{
			cin>>x>>xx;
			update(x+1,xx);
		}
		else
		{
			cin>>x>>xx;
			update(x+1,-1*xx);		
		}
	}
	return 0;
} 