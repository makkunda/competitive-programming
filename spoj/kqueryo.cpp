#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define lli long long int
vector<int> a;
vector<vector<int> > tree;
void build(int node,int left,int right)
{
	if(left==right)
		tree[node].push_back(a[left]);
	else
	{
		int mid = (left+right)/2;
		build(2*node,left,mid);
		build(2*node+1,mid+1,right);
		merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
	}
}
int query(int node,int left,int right,int q_left,int q_right,int k)
{
	if(left==q_left && right==q_right)
	{
		int sz = tree[node].size();
		if(tree[node][sz-1]<k)
			return 0;
		int lo = 0;
		int hi = sz-1;
		int mid;
		while(lo<hi)
		{
			mid = lo + (hi-lo)/2;
			int val = tree[node][mid];
			if(val<k)
				lo = mid+1;
			else
				hi = mid;
		}
		int ans = sz-lo;
		return ans;
	}
	int mid = (left+right)/2;
	if(q_right<=mid)
		return query(2*node,left,mid,q_left,q_right,k);
	if(q_left>mid)
		return query(2*node+1,mid+1,right,q_left,q_right,k);
	return (query(2*node,left,mid,q_left,mid,k)+query(2*node+1,mid+1,right,mid+1,q_right,k));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int i;
	a.resize(n);
	tree.resize(4*n+4);
	for(i=0;i<n;i++)
		cin>>a[i];
	build(1,0,n-1);
	int last_ans = 0;
	int q;
	cin>>q;
	while(q--)
	{
		int i,j,k;
		int a,b,c;
		cin>>a>>b>>c;
		i = a^last_ans;
		j = b^last_ans;
		k = c^last_ans;
		i = max(i,1);
		j = min(j,n);
		int ans = 0;
		if(i<=j)
			ans = query(1,0,n-1,i-1,j-1,k+1);
		cout<<ans<<'\n';
		last_ans = ans;
	}
	return 0;
}
