#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,i;
	vector<int> t;
	cin>>n;
	t.resize(n);
	long long int ans = 0;
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		ans=ans+t[i];
	}
	int lim = (int)sqrt(n) + 1;
	for(i=2;i<=lim;i++)
	{
		if(n%i==0)
		{
			int other = n/i;
			if(i<=other)
			{
				int j,k;
				if(other>2){
				for(j=0;j<i;j++)
				{
					long long int tempsum = 0;
					for(k=j;k<n;k=k+i)
						tempsum = tempsum + t[k];
					ans = max(ans,tempsum);
				}}
				if(i>2){
				for(j=0;j<other;j++)
				{
					long long int tempsum = 0;
					for(k=j;k<n;k=k+other)
						tempsum = tempsum + t[k];
					ans = max(ans,tempsum);
				}}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}