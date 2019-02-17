#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long int n,i;
		cin>>n;
		long int time = -1;
		vector<int> a(n);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(long int tt = 0;tt<(2*n+1);tt++)
		{
			bool change = false;
			for(i=0;i<(n-1);)
			{
				if(a[i]==0 && a[i+1]==1)
				{
					a[i+1]=0;
					a[i]=1;
					change = true;
					i=i+2;
				}
				else
				{
					i=i+1;
				}
			}
			if(!change)
				 {
				 	time = tt;
				 	break;
				 }
		}
		if(time==-1)
			cout<<(2*n)<<"\n";
		else
			cout<<time<<"\n";
	}
	return 0;
}