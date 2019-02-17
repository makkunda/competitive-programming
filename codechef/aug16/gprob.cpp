#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int mx(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	long long int n,i,j;
	cin>>n;
	int a[100000];
	for(i=0;i<n;i++)
		cin>>a[i];
	int table[100000][18];
	for(i=0;i<n;i++)
	{
		for(j=0;j<18;j++)
			table[i][j]=0;
	}
	for(i=0;i<n;i++)
		    table[i][0]=a[i];
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;(i+(1<<j)-1)<n;i++)
		{
			table[i][j]=mx(table[i][j-1],table[i+(1<<(j-1))][j-1]) ;
		}
	}
	long long int sum = 0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(((a[i]&a[j])==a[i])||((a[i]&a[j])==a[j]))
			{
				int k = (int)log2(j-i+1);
				sum = sum + mx(table[i][k],table[j-(1<<k)+1][k]);
			}

		}
	}
	cout<<sum<<endl;
	return 0;
}