#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#define lli long long int
vector<lli> a;
vector<lli> t;
vector<lli> lazy;

void build(int node,int l,int r)
{
	if(l==r)
		t[node] = a[l];
	else
	{
		int mid = (l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		t[node] = min(t[2*node],t[2*node+1]);
	}
}
void push(int node)
{
	t[2*node] = t[2*node] + lazy[node];
	lazy[2*node] = lazy[2*node] + lazy[node];
	t[2*node+1] = t[2*node+1] + lazy[node];
	lazy[2*node+1] = lazy[2*node+1] + lazy[node];
	lazy[node] = 0;
}
void update(int node,int l,int r,int ul,int ur,lli val)
{
	if(l==ul && r==ur)
	{
		t[node] = t[node] + val;
		lazy[node] = lazy[node] + val;
	}
	else
	{
		push(node);
		int mid = (l+r)/2;
		if(ur<=mid)
			update(2*node,l,mid,ul,ur,val);
		else if(ul>mid)
			update(2*node+1,mid+1,r,ul,ur,val);
		else
		{
			update(2*node,l,mid,ul,mid,val);
			update(2*node+1,mid+1,r,mid+1,ur,val);
		}
		t[node] = min(t[2*node],t[2*node+1]);
	}
}
lli query(int node,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)
		return t[node];
	push(node);
	int mid = (l+r)/2;
	if(qr<=mid)
		return query(2*node,l,mid,ql,qr);
	if(ql>mid)
		return query(2*node+1,mid+1,r,ql,qr);
	return min(query(2*node,l,mid,ql,mid),query(2*node+1,mid+1,r,mid+1,qr));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n;
	a.resize(n);
	t.resize(4*n+4);
	lazy.resize(4*n+4);
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	build(1,0,n-1);
	cin>>m;
	char c;
    while (cin.get(c) && c != '\n')
        {
        	continue;
        }
	while(m--)
	{
		string s;
		getline(cin,s);
		int spc=0;
		for(i=0;i<s.length();i++)
		{
			if(s[i]==' ')
				spc++;
		}
		stringstream ss(s);
		// cout<<"****"<<s<<"***"<<endl;
		if(spc==1)
		{
			int lb,ub;
			ss>>lb>>ub;
			// cout<<lb<<" "<<ub<<endl;
			lli ans;
			if(lb<=ub)
				ans = query(1,0,n-1,lb,ub);
			else
				ans = min(query(1,0,n-1,lb,n-1),query(1,0,n-1,0,ub));
			cout<<ans<<'\n';
		}
		else
		{
			int lb,ub;
			lli val;
			ss>>lb>>ub>>val;
			// cout<<lb<<" "<<ub<<" "<<val<<endl;
			if(lb<=ub)
				 update(1,0,n-1,lb,ub,val);
			else
				{
					update(1,0,n-1,lb,n-1,val);
					update(1,0,n-1,0,ub,val);
				}
		}

	}
	return 0;
}