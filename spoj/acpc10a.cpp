#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
    bool done = true;
    while(done)
    {
        int a,b,c ;
        long int ans;
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)
           done = false;
        else
         {
            if(2*b==(a+c))
               {
                   cout<<"AP "<<c+b-a<<"\n";
               }
            else
               {
                   cout<<"GP "<<c*b/a<<"\n";
               }
         }    
    }
	return 0;
}
