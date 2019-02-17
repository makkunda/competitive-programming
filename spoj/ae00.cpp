#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i;
	cin>>n;
	vector<long int> a;
	a.resize(10001);
	a[0]=0;a[1]=1;a[2]=2;a[3]=3;a[4]=5;a[5]=6;a[6]=8;
	for(i=7;i<=n;i++)
	 {
	 	a[i]=0;
	 	//int x = (int)sqrt(n);
	 	for(j=1;j<=n;j++)
	 	 {
	 	 	if(i%j==0)
	 	 	     a[i]++;
	 	 }
	 	 if(a[i]%2==0)
	 	 	  a[i]=a[i]/2;
	 	 else
	 	      a[i]=(a[i]+1)/2;
	 	 a[i]=a[i]+a[i-1]; 
	 }
	cout<<a[n]<<"\n"; 
	return 0;
}