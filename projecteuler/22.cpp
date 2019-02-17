// ans = 871198282

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ifstream fin("names_1.txt");
	int n;
	int i = 0;
	string name[10000];
	while(fin>>name[i++])
	{

	}
	n = i;
    sort(name,name + (n-1));
	long long int ans = 0;
	int j;
	long long int nmsum;
	for(i=0;i<(n-1);i++)
	{
		//cout<<i<<" "<<name[i]<<" ";
		int x = name[i].length();
		nmsum = 0;
		for(j=0;j<x;j++)
		{
			nmsum = nmsum + 1 + (int)name[i][j] - (int)'A';
		}
		nmsum = nmsum*(i+1);
		//cout<<ans<<" "<<nmsum<<" ";
		ans = ans + nmsum;
		//cout<<ans<<endl;
	}
	//ans = ans - nmsum ;
	cout<<ans<<endl;
	return 0;
}