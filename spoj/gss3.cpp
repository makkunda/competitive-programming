#include <iostream>
#include <vector>
#include <utility>
using namespace std;
long long int n;
vector<long long int> a;
vector<long long int> tree_sum;
vector<long long int> tree_best_pre;
vector<long long int> tree_best_suf;
vector<long long int> tree_best_subseq;
void construct_sum(long long int node,long long int left,long long int right)
{
	if(left==right){
		tree_sum[node] = a[left];
	}
	else
	{
		long long int mid = (left + right)/2;
		construct_sum(2*node,left,mid);
		construct_sum(2*node + 1,mid+1,right);
		tree_sum[node] = tree_sum[2*node] + tree_sum[2*node+1];
 	}
}
long long int query_sum(long long int node,long long int left,long long int right,long long int q_left,long long int q_right)
{
	if(left==q_left && right==q_right)
		return tree_sum[node];
	long long int mid = (left+right)/2;
	if(q_right<=mid)
		return query_sum(2*node,left,mid,q_left,q_right);
	if(q_left>mid)
		return query_sum(2*node+1,mid+1,right,q_left,q_right);
	return (query_sum(2*node,left,mid,q_left,mid) + query_sum(2*node+1,mid+1,right,mid+1,q_right));
}
void construct_rest(long long int node,long long int left,long long int right)
{
	if(left==right)
	{
		tree_best_subseq[node] = a[left];
		tree_best_suf[node] = a[left];
		tree_best_pre[node] = a[left];
	}
	else
	{
		long long int mid = (left+right)/2;
		construct_rest(2*node,left,mid);
		construct_rest(2*node+1,mid+1,right);
		tree_best_suf[node] = max(tree_best_suf[2*node+1],tree_sum[2*node+1]+tree_best_suf[2*node]);
		tree_best_pre[node] = max(tree_best_pre[2*node],tree_sum[2*node]+tree_best_pre[2*node+1]);
		tree_best_subseq[node] = max(max(tree_best_subseq[2*node],tree_best_subseq[2*node+1]),tree_best_suf[2*node]+tree_best_pre[2*node+1]);
	}
}
pair<long long int,long long int> query_pre_suff(long long int node,long long int left,long long int right,long long int q_left,long long int q_right)
{
	if(q_left==left&&q_right==right)
		return make_pair(tree_best_pre[node],tree_best_suf[node]);
	long long int mid = (left+right)/2;
	if(q_right<=mid)
		return query_pre_suff(2*node,left,mid,q_left,q_right);
	if(q_left>mid)
		return query_pre_suff(2*node+1,mid+1,right,q_left,q_right);
	pair<long long int,long long int> lc = query_pre_suff(2*node,left,mid,q_left,mid);
	pair<long long int,long long int> rc = query_pre_suff(2*node+1,mid+1,right,mid+1,q_right);
	long long int lsum = query_sum(2*node,left,mid,q_left,mid);
	long long int rsum = query_sum(2*node+1,mid+1,right,mid+1,q_right);
	long long int b_pre = max(lc.first,lsum+rc.first);
	long long int b_suf = max(rc.second,rsum+lc.second);
	return make_pair(b_pre,b_suf);
}
long long int query_main(long long int node,long long int left,long long int right,long long int q_left,long long int q_right)
{
	if(q_left==left && q_right==right)
		return tree_best_subseq[node];
	long long int mid = (left+right)/2;
	if(q_right<=mid)
		return query_main(2*node,left,mid,q_left,q_right);
	if(q_left>mid)
		return query_main(2*node+1,mid+1,right,q_left,q_right);
	pair<long long int,long long int> lc = query_pre_suff(2*node,left,mid,q_left,mid);
	pair<long long int,long long int> rc = query_pre_suff(2*node+1,mid+1,right,mid+1,q_right);
	long long int lbest = query_main(2*node,left,mid,q_left,mid);
	long long int rbest = query_main(2*node+1,mid+1,right,mid+1,q_right);
	long long int ans = max(max(lbest,rbest),lc.second+rc.first);
	return ans;
}
void update_main(long long int node,long long int left,long long int right,long long int pos,long long int val)
{
	if(left==right)
	{
		tree_sum[node] = val;
		tree_best_pre[node] = val;
		tree_best_subseq[node] = val;
		tree_best_suf[node] = val;
		a[left] = val;
	}
	else
	{
		long long int mid = (left+right)/2;
		if(pos<=mid)
			update_main(2*node,left,mid,pos,val);
		else
			update_main(2*node+1,mid+1,right,pos,val);
		tree_sum[node] = tree_sum[2*node] + tree_sum[2*node+1];
		tree_best_pre[node] = max(tree_best_pre[2*node],tree_sum[2*node]+tree_best_pre[2*node+1]);
		tree_best_suf[node] = max(tree_best_suf[2*node+1],tree_sum[2*node+1]+tree_best_suf[2*node]);
		tree_best_subseq[node] = max(max(tree_best_subseq[2*node],tree_best_subseq[2*node+1]),tree_best_pre[2*node+1]+tree_best_suf[2*node]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a.resize(n);
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	tree_sum.resize(4*n+1);
	tree_best_subseq.resize(4*n+1);
	tree_best_suf.resize(4*n+1);
	tree_best_pre.resize(4*n+1);
	construct_sum(1,0,n-1);
	construct_rest(1,0,n-1);
	long long int m;
	cin>>m;
	while(m--)
	{
		long long int t,x,y;
		cin>>t>>x>>y;
		if(t==1)
			cout<<query_main(1,0,n-1,x-1,y-1)<<'\n';
		else
			update_main(1,0,n-1,x-1,y);
	}
	return 0;
}
