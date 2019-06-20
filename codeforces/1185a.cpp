#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long int a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<long long int> a1;
	a1.resize(3);
	a1[0] = a;
	a1[1] = b;
	a1[2] = c;
	sort(a1.begin(),a1.end());
	long long int ans = 0;
	long long int z = 0;
	ans = ans + max(z,d-a1[1]+a1[0]) + max(z,d-a1[2]+a1[1]);
	cout<<ans<<endl;
	return 0;
}
