#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	long long int n,k,i;
	cin>>n>>k;
	long long int n1 = n-1;
	long long int mx = n1*(n1+1)/2;
	if(mx<k)
		cout<<"Impossible";
	else
	{
		bool done = true;
		long long int t = n;
		for(i=0;i<=(n+1);i++)
		{
			long long int temp = i*(i-1)/2;
			if(temp>k)
			{
				t = i-1;
				break;
			}
		}
		long long int t1 = t*(t-1)/2;
		long long int d1,t2;
		if(t1==k)
		{
			done = false;
			d1 = 0;
			t2 = n - t;
		}
		else{
		 d1 = k - t1 ;
		 t2 = n - t - 1;
		}
		for(i = 0;i<t2;i++)
			cout<<"()";
		for(i=0;i<d1;i++)
			cout<<'(';
		if(done)
			cout<<"()";
		for(i=d1;i<t;i++)
			cout<<'(';
		for(i=0;i<t;i++)
			cout<<')';
	}
	return 0;
}