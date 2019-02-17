#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
	ifstream fin("lasers.in");
	ofstream fout("lasers.out");
	long int n,xa,ya,xb,yb;
	fin>>n>>xa>>ya>>xb>>yb;
	long int ans = n/4;
	fout<<ans<<"\n";
	return 0;
}