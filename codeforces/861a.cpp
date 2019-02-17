#include <iostream>
#include <string>

using namespace std;

int main() {
    long long int n,k;
    long long int ans = 1 ;
    long int fv=0,tw=0;
    cin>>n>>k;
    long long int temp = n;
    while(temp%5==0)
    {
    temp = temp/5;
    fv++;
    }
    while(temp%2==0)
    {
    temp = temp/2;
    tw++;
    }
    if(k<tw)
    	tw = 0;
    else
    	tw = k - tw;
    if(k<fv)
    	fv = 0;
    else
    	fv = k - fv;
    int i;
    for(i=0;i<tw;i++)
    	ans = ans*2;
    for(i=0;i<fv;i++)
    	ans = ans*5;
    ans = ans*n;
    cout<<ans<<endl;
    return 0;
}