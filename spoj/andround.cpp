#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define lli long long int
vector<lli> a;
vector<lli> tree;
lli n;
lli N;
void construct(lli node,lli left,lli right)
{
	if(left==right)
		tree[node] = a[left];
	else
	{
		lli mid = (left+right)/2;
		construct(2*node,left,mid);
		construct(2*node+1,mid+1,right);
		tree[node] = (tree[2*node]) & (tree[2*node+1]);
	}
}
lli query(lli node,lli left,lli right,lli q_left,lli q_right)
{
	if(left==q_left&&right==q_right)
		return tree[node];
	lli mid = (left+right)/2;
	if(q_right<=mid)
		return query(2*node,left,mid,q_left,q_right);
	if(q_left>mid)
		return query(2*node+1,mid+1,right,q_left,q_right);
	return((query(2*node,left,mid,q_left,mid))&(query(2*node+1,mid+1,right,mid+1,q_right)));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		lli k;
		cin>>N>>k;
		n = 3*N;
		a.resize(0);
		a.resize(n);
		tree.resize(0);
		tree.resize(4*n+10);
		lli i;
		for(i=0;i<N;i++)
		{
			cin>>a[i];
			a[N+i] = a[i];
			a[2*N+i] = a[i];
		}
		construct(1,0,n-1);
		if(k>=(N-1))
		{
			for(i=0;i<N;i++)
				cout<<tree[1]<<" ";
			cout<<'\n';
		}
		else
		{
			for(i=0;i<N;i++)
				cout<<query(1,0,n-1,N+i-k,N+i+k)<<" ";
			cout<<'\n';
		}
	}
	return 0;
}
