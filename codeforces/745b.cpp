#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	 int n,m,i,j;
	 char a[500][500];
	 cin>>n>>m;
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<m;j++)
	 		cin>>a[i][j];
	 }
	 int tplx,tply,bprx,bpry;
	 
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<m;j++)
	 	{
	 		if(a[i][j]=='X')
	 		{
	 			tplx = i;
	 			tply = j;
	 			break;
	 		}
	 	}
	 }
	 bpry = tply;
	 for(j=tply+1;j<m;j++)
	 	 {
	 	 	if(a[tplx][j]!='X')
	 	 	{
	 	 		bpry = j-1;
	 	 		break;
	 	 	}
	 	 }
	if(j==m)
	    bpry = m -1 ; 	 
	bprx = tplx; 	 
	for(i=tplx+1;i<n;i++)
	  {
	  	if(a[i][tply]!='x')
	  		 {bprx = i - 1;
	  		 	break;
	  		 }	
	  } 
	if(i==n)
	    bprx = n - 1;
	bool ans = true;
	for(i=tplx;i<=bprx;i++)
	  {
	  	for(j=tply;j<=bpry;j++)
	  		 {
	  		 	if(a[i][j]!='x')
	  		 		 {
	  		 		 	ans = false;
	  		 		 	break;
	  		 		 }
	  		 }
	  }  
	if(ans)
	   cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


}