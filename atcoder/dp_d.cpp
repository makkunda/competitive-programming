#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	int i;
	for(i=0;i<n;i++)
		cin>>a[i]>>b[i]>>c[i];
	vector<int> a_1;
	vector<int> b_1;
	vector<int> c_1;
	a_1.resize(n);
	b_1.resize(n);
	c_1.resize(n);
	a_1[0] = a[0];
	b_1[0] = b[0];
	c_1[0] = c[0];

	for(i=1;i<n;i++)
	{
		a_1[i] = a[i] + max(b_1[i-1],c_1[i-1]);
		b_1[i] = b[i] + max(a_1[i-1],c_1[i-1]);
		c_1[i] = c[i] + max(b_1[i-1],a_1[i-1]);
	}
	int ans = max(a_1[n-1],max(b_1[n-1],c_1[n-1]));
	cout<<ans<<endl;
	return 0;
}