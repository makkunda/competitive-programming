#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define lli long long int
lli n;
vector<lli> tree;
vector<lli> a;
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
lli query(lli node,lli left,lli right,lli q_left,lli q_right)
{
	if(left==q_left && right==q_right)
		return tree[node];
	lli mid = (left+right)/2;
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
	int q;
	cin>>q;
	int i;
	vector<char> type;
	vector<int>  quer;
	type.resize(q);
	quer.resize(q);
	for(i=0;i<q;i++)
		cin>>type[i]>>quer[i];

	map<int,int> forw;
	map<int,int> rev;
	set<int> values;

	int counter = 1;
	for(i=0;i<q;i++)
	{
		if(type[i]!='K')
		{
			values.insert(quer[i]);
		}
	}
	vector<int> sort_val;
	set<int>::iterator it;
	for(it=values.begin();it!=values.end();it++)
		sort_val.push_back(*it);
	sort(sort_val.begin(),sort_val.end());
	for(i=0;i<sort_val.size();i++)
	{
		forw[sort_val[i]] = counter;
		rev[counter] = sort_val[i];
		counter++;
	}
	n = counter;
	a.resize(n);
	tree.resize(4*n+4);
	construct(1,0,n-1);

	for(i=0;i<q;i++)
	{
		if(type[i]=='I')
		{
			lli val = forw[quer[i]];
			update(1,0,n-1,val,1);
		}
		else if(type[i]=='D')
		{
			lli val = forw[quer[i]];
			update(1,0,n-1,val,0);
		}
		else if(type[i]=='C')
		{
			lli val = forw[quer[i]];
			lli ans = query(1,0,n-1,0,val-1);
			cout<<ans<<'\n';
		}
		else
		{
			lli mxval = tree[1];
			lli k = quer[i];
			if(k>mxval)
				cout<<"invalid\n";
			else
			{
				lli lo = 0;
				lli hi = n-1;
				while(lo<hi)
				{
					lli mid = lo + (hi-lo)/2;
					lli midval = query(1,0,n-1,0,mid);
					if(midval>=k)
						hi = mid;
					else
						lo = mid + 1;
				}
				lli ans = rev[lo];
				cout<<ans<<'\n';
			}

		}
	}

	return 0;
}
