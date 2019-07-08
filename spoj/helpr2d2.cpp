#include <iostream>
#include <vector>
#include <string>
#include <sstream>
// #include <cstdio>
using namespace std;
#define lli long long int
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
	if(left==right){
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
		int k;
		int n;
		cin>>k>>n;
		a.resize(0);
		tree.resize(0);
		a.resize(n+1);
		tree.resize(4*n+10);
		a[0] = 1001;
		construct(1,0,n);
		string s;
		int tmp = n;
		getline(cin,s);
		while(tmp>0)
		{
			getline(cin,s);
			stringstream ss(s);
			int r,v;
			r=1;
			if(s[0]=='b')
			{
				char x;
				ss>>x>>r>>v;
			}
			else
			{
				ss>>v;
			}
			// cout<<s<<" "<<r<<" "<<v<<endl;
			tmp = tmp - r;
			int i;
			for(i=0;i<r;i++)
			{
				int posval = k-v;
				int lo = 0;
				int hi = n;
				while(lo<hi)
				{
					int mid = lo + (hi-lo)/2;
					int qval = query(1,0,n,0,mid);
					if(qval>posval)
						lo = mid + 1;
					else
						hi = mid;
				}
				int upval = a[lo] + v;
				update(1,0,n,lo,upval);
			}
		}
		int ans = 0;
		int cnt = 0;
		int i;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
				break;
			cnt++;
			ans += k - a[i];
			// cout<<a[i]<<" ";
		}
		// cout<<'\n';
		cout<<cnt<<" "<<ans<<"\n";
	}
	return 0;
}
