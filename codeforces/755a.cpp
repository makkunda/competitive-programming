#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long int i,j,n,m,prod;
	cin>>n;
	if(n==1)
		cout<<3<<endl;
	else if(n%2)
		cout<<1<<endl;
	else
	{
		vector<bool> isp;
		isp.resize(1001);
		vector<int> prime;
		for(i=0;i<=1000;i++)
			isp[i]=true;
		for(i=2;i<=1000;i++)
		{
			if(isp[i])
			{
				prime.push_back(i);
				for(j=i*i;j<=1000;j=j+i)
					isp[j]=false;
			}
		}
		for(m=1;m<=1000;m++)
		{
			prod = n*m+1;
			for(i=0;i<prime.size();i++)
			{
				if(prod==prime[i])
				{

				}
				else if(prod%prime[i]==0)
				{
					cout<<m<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}