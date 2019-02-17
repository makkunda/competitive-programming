#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int hsh(char a,char b)
 {
 	int a1 = (int)a - (int)'A';
 	int a2 = (int)b - (int)'A';
 	return (a1 + 26*a2);
 }
int main()
{
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	long int adj[676][676];
	long int n,i,j;
	string s1,s2;
	fin>>n;
	for(i=0;i<676;i++)
	{
		for(j=0;j<676;j++)
			  adj[i][j] = 0;
	}
	for(i=0;i<n;i++)
	{
		fin>>s1>>s2;
		int a = hsh(s1[0],s1[1]);
		int b = hsh(s2[0],s2[1]);
		adj[a][b]++;
	}
	long long int ans = 0;
	for(i=0;i<676;i++)
	{
		for(j=i+1;j<676;j++)
		{
			ans = ans + adj[i][j] * adj[j][i] ;
		}
	}
	fout<<ans<<"\n";
	return 0;
}