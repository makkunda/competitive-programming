#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<int> tree;
void update(int node,int left,int right,int pos,int val)
{
	if(left==right)
	{
		tree[node] = val;
	}
	else
	{
		int mid = (left+right)/2;
		if(pos<=mid)
			update(2*node,left,mid,pos,val);
		else
			update(2*node+1,mid+1,right,pos,val);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}
int query(int node,int left,int right,int q_left,int q_right)
{
	if(left==q_left&&right==q_right)
		return tree[node];
	int mid = (left+right)/2;
	if(q_right<=mid)
		return query(2*node,left,mid,q_left,q_right);
	if(q_left>mid)
		return query(2*node+1,mid+1,right,q_left,q_right);
	return(query(2*node,left,mid,q_left,mid)+query(2*node+1,mid+1,right,mid+1,q_right));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		cin>>n;
		string s;
		vector<int> pos;
		pos.resize(n);
		map<string,int> mp;
		for(i=0;i<n;i++)
		{
			cin>>s;
			mp[s] = i;
		}
		for(i=0;i<n;i++)
		{
			cin>>s;
			pos[i] = mp[s];
		}
		tree.resize(0);
		tree.resize(4*n+10);
		long long int ans = 0;
		for(i=0;i<n;i++)
		{
			int ps = pos[i];
			ans = ans + query(1,0,n-1,ps,n-1);
			update(1,0,n-1,ps,1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
