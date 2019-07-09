#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define lli long long int
using namespace std;
vector<int> a;
vector<int> tree;
void construct(int node,int left,int right)
{
	if(left==right)
		tree[node] = a[left];
	else
	{
		int mid = (left+right)/2;
		construct(2*node,left,mid);
		construct(2*node+1,mid+1,right);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}
void update(int node,int left,int right,int pos,int val)
{
	if(left==right)
	{
		tree[node] = val;
		a[pos] = val;
	}
	else
	{
		int mid = (left+right)/2;
		if(pos<=mid)
			update(2*node,left,mid,pos,val);
		else
			update(2*node+1,mid+1,right,pos,val);
		tree[node] = min(tree[2*node],tree[2*node+1]);
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
	return min(query(2*node,left,mid,q_left,mid),query(2*node+1,mid+1,right,mid+1,q_right));
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
		a.resize(n+1);
		tree.resize(0);
		tree.resize(4*n+10);
		int i;
		for(i=0;i<=n;i++)
		{
			a[i] = 100001;
		}
		construct(1,0,n);
		// vector<pair<int,pair<int,int> > data;
		vector<tuple<int,int,int> > data;
		int a,b,c;
		for(i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			// data.push_back(make_pair(a,make_pair(b,c)));
			data.push_back(make_tuple(a,b,c));
		}
		sort(data.begin(),data.end());
		int ans = 0;
		for(i=0;i<n;i++)
		{
			a = get<0>(data[i]);
			// b = data[i].second.first;
			b = get<1>(data[i]);
			// c = data[i].second.second;
			c = get<2>(data[i]);
			int min_val = query(1,0,n,0,b);
			if(min_val>c)
				ans++;
// 			cout<<a<<" "<<b<<" "<<c<<" "<<min_val<<endl;
			update(1,0,n,b,c);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
