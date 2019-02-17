#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n>=m)
		cout<<"YES\n";
	else
	{
		vector<int> a;
		bool done = false;
		long long int x;
		int i,j;
		for(i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x%m);
			if(a[i]==0)
				done = true;
		}
		bool pos[2100][2100];
		pos[0][0] = true;
		for(i=1;i<=m;i++)
			pos[i][0]=false;
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=m;i++)
			{
				if(i>=a[j-1])
					pos[i][j]=pos[i-a[j-1]][j-1]||pos[i][j-1];
				else
					pos[i][j]=pos[i][j-1];
			}
		}
		done = done||pos[m][n];
		if(done)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
	return 0;
}