#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	long long int n,k,i,other;
	cin>>n>>k;
	long long int lim = (long long int)sqrt(n) + 1;
	vector<long long int> factor;
	for(i=1;i<=lim;i++)
	 {
	 	if(n%i==0)
	 	{
	 		other = n/i;
	 		if(i<=other)
	 		{
		 		factor.push_back(i);
		 		if(other!=i)
		 			factor.push_back(other);
		 	}
	 	}
	 }
	sort(factor.begin(),factor.end());
	if(factor.size()<k)
		cout<<-1<<endl;
	else
		cout<<factor[k-1]<<endl; 
	return 0;
}