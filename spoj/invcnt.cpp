#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
long long int count_inv(int left,int right)
{
	if(left==right)
		return 0;
	int mid = (left+right)/2;
	long long int lft = count_inv(left,mid);
	long long int rght = count_inv(mid+1,right);
	long long int ans = lft + rght;
	int t_size = right - left + 1;
	int r_size = right - mid;
	int l_size = mid-left+1;
	int i=0,j=0,k=0;
	vector<int> rep;
	rep.resize(t_size);

	while((i<l_size)&&(j<r_size))
	{
		if(a[left+i]<=a[mid+1+j])
		{
			rep[k] = a[left+i];
			i++;
			k++;
		}
		else
		{
			rep[k] = a[mid+1+j];
			j++;
			k++;
			ans += (l_size - i);
		}
	}
	while(i<l_size)
	{
		rep[k] = a[left+i];
		i++;
		k++;
	}
	while(j<r_size)
	{
		rep[k] = a[mid+1+j];
		j++;
		k++;
	}
	for(i=0;i<t_size;i++)
		a[left+i] = rep[i];
	rep.resize(0);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		a.resize(0);
		a.resize(n);
		int i;
		for(i=0;i<n;i++)
			cin>>a[i];
		long long int ans = count_inv(0,n-1);
		cout<<ans<<'\n';
	}
	return 0;
}
