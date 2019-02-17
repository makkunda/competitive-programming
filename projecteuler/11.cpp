//ans = 70600674
#include <iostream>
#include <fstream>
//#define cin 
using namespace std;
long long int mx(long long int a,long long int b)
 {
 	if(a>b)
 		 return a;
 	return b;	
 }
int main()
{
	ifstream fin("11.in");
	int i,j,d1,d2,k;
	char x,y;
	int a[20][20];
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
			 {
			 	cin>>x>>y;
			 	d1 = (int)x - (int)'0';
			 	d2 = (int)y - (int)'0';
			 	a[i][j] = 10*d1 + d2;
			 }
	}
	long long int ans = 1788696,m1,m2,m3;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			m1=m2=m3=1;
			if((i+3)<20 && (j+3)<20 )
			{
				for(k=0;k<4;k++)
					  {
					  	m1 = m1*a[i+k][j];
					  	m2 = m2*a[i][j+k];
					  	m3 = m3*a[i+k][j+k];
					  }
				ans = mx(mx(m1,m2),mx(m3,ans));	  
			}
			else if((i+3)<20)
			{
				for(k=0;k<4;k++)
					  {
					  	m1 = m1*a[i+k][j];
					  	//m2 = m2*a[i][j+k];
					  	//m3 = m3*a[i+k][j+k];
					  }
				//ans = mx(mx(m1,m2),mx(m3,ans));
				ans = mx(ans,m1);	  
			}
			else if((j+3)<20)
			{
				for(k=0;k<4;k++)
					  {
					  	//m1 = m1*a[i+k][j];
					  	m2 = m2*a[i][j+k];
					  	//m3 = m3*a[i+k][j+k];
					  }
				//ans = mx(mx(m1,m2),mx(m3,ans));
				ans = mx(ans,m2);	  
			}
		}
	}
	for(i=0;i<20;i++)
	  {
	      for(j=0;j<20;j++)
	        {
	            if((i-3)>=0 && (j+3)<20)
	                {
	                    long int mm = 1;
	                    for(k=0;k<4;k++)
	                        mm = mm*a[i-k][j+k];
	                    ans = mx(ans,mm);     
	                }
	        }
	  }
	cout<<ans<<"\n";
	return 0;
}