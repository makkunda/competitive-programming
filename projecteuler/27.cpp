//ans = -59231

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long int> prime;

long long int quadeval(int n,int a,int b)
{
	long long int ans = n*n + n*a + b;
	return ans;
}

bool isp(long long int a)
{
	int i;
	for(i=0;i<prime.size();i++)
	{
		if(prime[i]==a || prime[i]==-1*a)
			return true;
		if(a%prime[i]==0)
			return false;
	}
	return true;
}

int main()
{
	int i,j,k,a,b;
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	prime.push_back(7);
	for(i=11;i<2000;i++)
	{
		bool toadd = true;
		for(j=0;j<prime.size();j++)
		{
			if(i%prime[j]==0)
			{
				toadd = false;
				break;
			}
		}
		if(toadd)
			prime.push_back(i);
	}
	int mx = 0;
	int mxa,mxb;
	int cntr;
	for(a=-999;a<1000;a++)
	{
		for(b=-1000;b<=1000;b++)
		{
			cntr = 0;
			for(i=0;i<=1000;i++)
			{
				if(isp(quadeval(i,a,b)))
					cntr++;
				else
					break;
			}
			if(cntr>mx)
			{
				mx = cntr;
				mxa = a;
				mxb = b;
			}
			if(a==1 && b==41)
				cout<<cntr<<endl;
		}
	}
	cout<<mx<<" "<<mxa<<" "<<mxb<<endl;
	cout<<mxa*mxb<<endl;
	return 0;
}