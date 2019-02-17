#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	int i,j;
	cin>>n;
	string s,m;
	cin>>s>>m;
	vector<int> s1,m1;
	s1.resize(10);
	m1.resize(10);
	for(i=0;i<n;i++)
	{
		int s11 = (int)s[i] - (int)'0';
		int m11 = (int)m[i] - (int)'0';
		s1[s11]++;
		m1[m11]++;
	}
	for(i=0;i<10;i++)
	{
		
	}
	return 0;
}