#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	 ios::sync_with_stdio(false);cin.tie(0);
	long int t;
	//cin>>t;
	t = 10000010;
	while((t--)>10000000)
	{
		long long int x;
		//cin>>x;
		x = t;
		if(x==1)
			cout<<"INFINITY"<<"\n";
		else{
		long long int count = 0;
		for(int n=1;n<6;n++)
		{
			long long int y = x/2;
			double pwr = 1/(double)n;
			long long int lb = (long long int)ceil(pow(y,pwr));
			//cout<<"lb "<<pow(y,pwr)<<"\n";
			//cout<<"ub "<<pow(x,pwr)<<"\n";
			long long int ub = (long long int)floor(pow(x,pwr) + 0.0000001);
			if(pow(lb,n)==(double)y)
				 lb = lb + 1;

			if(ub>=2 && ub>=lb)	
			count = count + ub - lb + 1;
		}
		for(long long int n=2;n<=100;n++)
		{
			long long int temp = x;int ctr = 0;
			long long int digit;
			while(temp!=0)
			{
				digit = temp%n;ctr++;
				temp = temp/n;
			}
			if(digit==1 && ctr>6)
				{count++;}
		}
		long int count1=0;
		for(long long int n=2;n<=x;n++)
		{
			long long int temp = x;int ctr = 0;
			long long int digit;
			while(temp!=0)
			{
				digit = temp%n;ctr++;
				temp = temp/n;
			}
			if(digit==1)
				{count1++;}
		}
		//cout<<count<<"\n";
		if(count!=count1)
			 cout<<t<<" myans "<<count<<" str "<<count1<<"\n";
	}

	}
	
	return 0;
}