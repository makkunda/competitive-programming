#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ifstream fin("names.txt");
	ofstream fout("names_1.txt");
	char x;
	while(fin>>x)
	{
		if(x=='\"')
			fout<<" ";
		else if(x==',')
			fout<<" ";
		else
			fout<<x;
	}
	
	return 0;
}