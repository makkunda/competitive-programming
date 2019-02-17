#include <iostream>
#include <cmath>
using namespace std;
long long int pwr1(long long int x,int m)
   {
   	long long int ans = 1;
   	for(int i =0;i<m;i++)
   		  ans = ans*x;
   	return x;	
   }
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
		for(int n=1;n<6;n++)
		{
			long long int y = x/2;long long int lb ,ub;
			double pwr = 1/(double)n;
			if(n!=3)
			{lb = (long long int)ceil(pow(y,pwr));
			//cout<<"lb "<<pow(y,pwr)<<"\n";
			//cout<<"ub "<<pow(x,pwr)<<"\n";
			ub = (long long int)floor(pow(x,pwr) + 0.000000000001);
			if(pow(lb,n)==(double)y)
				 lb = lb + 1;
 			}
 			else
 			{lb = (long long int)ceil(cbrt(y));
			//cout<<"lb "<<pow(y,pwr)<<"\n";
			//cout<<"ub "<<pow(x,pwr)<<"\n";
			ub = (long long int)floor(cbrt(x));
			if(pow(lb,n)==(double)y)
				 lb = lb + 1;
 			}
 		/*	long long int max = (long long int )pow(1e12,pwr) + 1;
 			cout<<n<<" "<<max<<"\n";
 			long long int bsu = max,bsl = 2;
 			long long int mid ;
 			while(bsu>bsl)
 			{
 				mid = bsl + (bsu - bsl + 1)/2;
 				long long int temp = pwr1(mid,n);
 				if(temp>x)
 					  bsu = mid - 1;
 				else if(temp<x)
 				      bsl = mid + 1;
 				else      	
 					break;
 			}
 			ub = mid;
 			bsu = max;bsl = 2;
 			while(bsu>bsl)
 			{
 				mid = bsl + (bsu - bsl + 1)/2;
 				long long int temp = pwr1(mid,n);
 				if(2*temp>=x)
 					  bsu = mid - 1;
 				else if(2*temp<x)
 				      bsl = mid + 1;
 				else      	
 					break;
 			}
 			lb = mid; */
			if(ub>=2 && ub>=lb)	
			count = count + ub - lb + 1;
			//cout<<n<<" "<<lb<<" "<<ub<<"\n";	
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
				count++;
		}
		cout<<count<<"\n";}
 
	}
	
	return 0;
}  