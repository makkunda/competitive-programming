#include <iostream>
using namespace std;
int main()
{
	int i = 8;
	long int x ;
	bool done = true;
	while(done)
	{
		x = i*(i+1)/2;
		int ct = 0;
		for(long int j=1;j<=(x/2);j++)
			 {
			 	if(x%j==0)
			 		ct++;
			 }
		if(ct>=499)
		  {
		  	cout<<i<<endl;
		  	cout<<x<<endl;
		  	return 0;
		  }
		//cout<<i<<" "<<ct<<endl;  	 
		i++;  
	}
	return 0;
}
