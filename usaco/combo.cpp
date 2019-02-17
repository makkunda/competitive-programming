/*
ID: makkund2
PROG: combo
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
int ab(int x)
 {
 	if(x>0)
 		return x;
 	return -1*x;
 }
int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int n,i,j,k;
    long long int count = 0;
    int a1,a2,a3,b1,b2,b3;
    fin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		for(k=1;k<=n;k++)
    		{
    			if((ab(a1-i)<=2 || ab(a1+n-i)<=2 || ab(a1 -n - i)<=2) && (ab(a2-j)<=2 || ab(a2+n-j)<=2 || ab(a2-n-j)<=2) && (ab(a3-k)<=2 || ab(a3+n-k)<=2 || ab(a3-n-k)<=2))
    				  {count++;/*fout<<i<<" "<<j<<" "<<k<<endl;*/}
    			else if((ab(b1-i)<=2 || ab(b1+n-i)<=2 || ab(b1-n-i)<=2) && (ab(b2-j)<=2 || ab(b2+n-j)<=2 || ab(b2-n-j)<=2) && (ab(b3-k)<=2 || ab(b3+n-k)<=2 || ab(b3-n-k)<=2))
    				  {count++;/*fout<<i<<" "<<j<<" "<<k<<endl;*/}
    		}
    	}
    }
    fout<<count<<"\n";
    return 0;
}