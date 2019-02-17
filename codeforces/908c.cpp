#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
long double ab(long double a)
{
	if(a>0)
		return a;
	return (-1*a);
}
int main()
{
	int n,i,j;
	long double r;
	cin>>n>>r;
	vector<long double> x;
	vector<long double> y;
	// long double inf = 2000000.0*r;
	x.resize(n);
	y.resize(n);
	long double dif = 2.0*r;
	for(i=0;i<n;i++)
		cin>>x[i];
	y[0]=r;
	for(i=1;i<n;i++)
	{
		long double maxv = r;
		for(j=0;j<i;j++)
		{
			if(ab(x[i]-x[j])<=dif)
			{
				long double d1 = ab(x[i]-x[j]);
				long double d2 = (long double)sqrt(dif*dif - d1*d1);
				d2 = d2 + y[j];
				maxv = max(maxv,d2);
			}
		}
		y[i]=maxv;
	}
	for(i=0;i<n;i++)
		cout<<setprecision(20)<<y[i]<<" ";
	return 0;
}