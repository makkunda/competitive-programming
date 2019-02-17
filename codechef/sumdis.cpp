#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,i,n1,n2;
		cin>>n;
		vector<int> a,b,c;
		a.resize(n-1);b.resize(n-2);c.resize(n-3);
		for(i=0;i<(n-1);i++)
			cin>>a[i];
		for(i=0;i<(n-2);i++)
			cin>>b[i];
		for(i=0;i<(n-3);i++)
			cin>>c[i];
		long long int ans = 0;
		if(n>1000){
		n1 = 2;n2 = n-2;
		vector<long long int> acntr,bcntr;
		acntr.resize(n-1);bcntr.resize(n-2);
		if((a[0]+a[1])<=b[0])
		  acntr[0] = n-1;
		else
		  acntr[0]=1;
		for(i=1;i<(n-2);i++)
		{
			if(((a[i]+a[i+1])<=b[i])&&((a[i]+a[i-1])<=b[i-1]))
				 acntr[i] = n1*n2;
			else if(((a[i]+a[i+1])<=b[i]))
				 acntr[i] = n2;
			else if((a[i]+a[i-1])<=b[i-1])
			   acntr[i] = n1;
			else
			   acntr[i] = 1;
			n1++;
			n2--;
		}
		if((a[i]+a[i-1])<=b[i-1])
			acntr[i]=n1*n2;
		else
			acntr[i]=1;
		n1 = 1;n2 = n-2;
		for(i=0;i<(n-2);i++)
		 {
			 if((a[i]+a[i+1])>b[i])
			   bcntr[i] = n1*n2;
			 else
			   bcntr[i] = 0;
			 n1++;
			 n2--;
		 }
		for(i=0;i<(n-1);i++)
		   ans = ans + a[i]*acntr[i];
		for(i=0;i<(n-2);i++)
		 	 ans = ans + b[i]*bcntr[i];
		}
		else
		{
		    vector<vector<pair<int,int> > > adj;
		    adj.resize(n);
		    for(i=0;i<(n-1);i++)
				{
				pair <int,int> ac(i+1,a[i]);
				adj[i].push_back(ac);
				}
			for(i=0;i<(n-2);i++)
			{
			pair <int,int> ac(i+2,b[i]);
			adj[i].push_back(ac);
			}
			for(i=0;i<(n-3);i++)
			{
			pair <int,int> ac(i+3,c[i]);
			adj[i].push_back(ac);
			}
			for(i=0;i<n;i++)
			{
				long long int inf = 1000000000;
				vector<long long int> d(n,inf);
				d[i] = 0;
				vector<bool> mr (n,false);
				priority_queue<pair<long long int,int>> q;
				q.push({0,i});
				while(!q.empty())
				 {
					 int a = q.top().second;q.pop();
					 if(mr[a])
					  continue;
					 mr[a] = true;
					 for(auto bb: adj[a]){
						 if((d[a]+bb.second) <d[bb.first])
						     {
									 d[bb.first] = d[a] + bb.second;
									 q.push({-1*d[bb.first],bb.first});
								 }
					 }
				 }
				 for(int j = (i+1);j<n;j++)
				    ans = ans + d[j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
