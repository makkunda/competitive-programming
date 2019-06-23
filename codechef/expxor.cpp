#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define lli long long int 
double pow(double a,int b)
{
	if(b==0)
		return 1;
	double sqrt = pow(a,b/2);
	double ans = sqrt*sqrt;
	if(b%2)
		ans = ans * a;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<long long int> b;
		b.resize(n);
		vector<double> p;
		p.resize(n);
		int i;
		for(i=0;i<n;i++)
			cin>>b[i];
		for(i=0;i<n;i++)
			cin>>p[i];
		int j;
		double ans = 0;
		for(j=0;j<31;j++)
		{
			vector<double> p_0;
			vector<double> p_1;
			p_0.resize(n+1);
			p_1.resize(n+1);
			p_0[0] = 1;
			p_1[0] = 0;
			for(i=1;i<=n;i++)
			{
				if(b[i-1]&(1<<j))
				{
					p_0[i] = p[i-1]*p_1[i-1] + (1-p[i-1])*p_0[i-1];
					p_1[i] = (double)1.0 - p_0[i];
				}
				else
				{
					p_0[i] = p_0[i-1];
					p_1[i] = p_1[i-1];
				}
			}
			ans = ans + p_1[n]*pow(2,j);
		}
		cout<<setprecision(12)<<ans<<'\n';
	}
	return 0;
}
