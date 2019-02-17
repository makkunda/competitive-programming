#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	 ios::sync_with_stdio(false);cin.tie(0);
	long int t;
	cin>>t;
	while(t--)
	{
		long long int x;
		cin>>x;
		if(x==1)
			cout<<"INFINITY"<<"\n";
		else{
		long long int count = 0;
		for(int n=1;n<40;n++)
		{
			long long int y = x/2;
			double pwr = 1/(double)n;
			long long int lb = (long long int)ceil(pow(y,pwr));
			//cout<<"lb "<<pow(y,pwr)<<"\n";
			//cout<<"ub "<<pow(x,pwr)<<"\n";
			long long int ub = (long long int)(pow(x,pwr) + 0.0000000000000001);
			if(pow(lb,n)==(double)y)
				 lb = lb + 1;	
			if(ub>=2 && ub>=lb)	
			count = count + ub - lb + 1;
			//cout<<n<<" "<<lb<<" "<<ub<<"\n";	
		}
		cout<<count<<"\n";}
	}
	return 0;
}