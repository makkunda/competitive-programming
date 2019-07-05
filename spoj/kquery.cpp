#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define lli long long int
lli n;
vector<int> a;
vector<int> tree;
void construct(lli node,lli left,lli right)
{
	if(left==right)
		tree[node] = a[left];
	else
	{
		lli mid = (left+right)/2;
		construct(2*node,left,mid);
		construct(2*node+1,mid+1,right);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}
void update(lli node,lli left,lli right,lli pos,lli val)
{
	if(left==right)
		tree[node] = val;
	else
	{
		lli mid = (left+right)/2;
		if(pos<=mid)
			update(2*node,left,mid,pos,val);
		else
			update(2*node+1,mid+1,right,pos,val);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
} 
int query(lli node,lli left,lli right,lli q_left,lli q_right)
{
	if(left==q_left && right==q_right)
		return tree[node];
	lli mid = (left+right)/2;
	if(q_right<=mid)
		return query(2*node,left,mid,q_left,q_right);
	if(q_left>mid)
		return query(2*node+1,mid+1,right,q_left,q_right);
	return (query(2*node,left,mid,q_left,mid)+query(2*node+1,mid+1,right,mid+1,q_right));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<pair<lli,lli> > ele_pos;
	lli x;
	lli i;
	a.resize(n);
	tree.resize(4*n+1);
	for(i=0;i<n;i++)
	{
		cin>>x;
		ele_pos.push_back(make_pair(x,i));
		a[i] = 1;
	}
	ele_pos.push_back(make_pair(1000000001,-1));
	construct(1,0,n-1);
	sort(ele_pos.begin(),ele_pos.end());
	lli q;
	cin>>q;
	vector<lli> q_x;
	vector<lli> q_y;
	vector<pair<lli,lli> > q_k;
	vector<lli> q_ans;
	q_x.resize(q);
	q_y.resize(q);
	q_ans.resize(q);
	lli k;
	for(i=0;i<q;i++)
	{
		cin>>q_x[i]>>q_y[i]>>k;
		q_k.push_back(make_pair(k,i));
	}
	sort(q_k.begin(),q_k.end());
	lli j = 0;
	lli ele_max = ele_pos[n-1].first;
	for(i=0;i<q;i++)
	{
		if(q_k[i].first>ele_max)
			q_ans[q_k[i].second] = 0;
		else
		{
			while(ele_pos[j].first<=q_k[i].first)
			{
				update(1,0,n-1,ele_pos[j].second,0);
				j++;
			}
			q_ans[q_k[i].second] = query(1,0,n-1,q_x[q_k[i].second]-1,q_y[q_k[i].second]-1);
		}
	}
	for(i=0;i<q;i++)
		cout<<q_ans[i]<<'\n';
	return 0;
}
