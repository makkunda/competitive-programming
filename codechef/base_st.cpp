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
		for(long long int n=2;n<=x;n++)
		{
			long long int temp = x;
			long long int digit;
			while(temp!=0)
			{
				digit = temp%n;
				temp = temp/n;
			}
			if(digit==1)
				{count++;cout<<n<<"\n";}
		}
		cout<<count<<"\n";}
	}
	return 0;
}