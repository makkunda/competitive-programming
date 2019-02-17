#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long int n,k,i,j;
	cin>>n>>k;
	vector<long int> a,b;
	a.resize(n);
	b.resize(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i] = 1;
	}
	sort(a.begin(),a.end());
	long int temp = 0,t1=1;
	for(i=t1;i<n;i++)
	{
		if((a[i]-a[temp])>=k)
			  {
			  	b[i] = 2;
			  	break;
			  }
	}
	t1 = i;
	for(i=t1+1;i<n;i++)
		 {
		 	for(j=temp;j<i;)
		 		 {
		 		 	if((a[i] - a[j])>=k)
		 		 		  j++;
		 		 	else
		 		 	      break;	
		 		 }
		    temp = j - 1;
		    b[i] = b[temp] + 1;  		 
		 }
	cout<<b[n-1]<<endl;	 
	return 0;
}