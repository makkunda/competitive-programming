#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a,b,c;
	vector<long long int> nfact;
	cin>>a>>b>>c;
	long long int n = a*b*c;
	nfact.resize(n+1);
	long long int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j=j+i)
			nfact[j]++;
	}
	long long int ans = 0;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			for(k=1;k<=c;k++)
				ans = ans + nfact[i*j*k];
		}
	}
	ans = ans%1073741824;
	ans = ans + 1073741824;
	ans = ans%1073741824;
	cout<<ans<<endl;
	return 0;
}