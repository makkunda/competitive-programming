
#include <iostream>
#include <string>

using namespace std;

int main() {
    int s;
    cin>>s;
    while(s--)
    {
        int n,i;
        bool corr = true;
        int h[100];
        cin>>n;
        for(i=0;i<n;i++)
            cin>>h[i];
        if(n%2==0)
           corr = false;
        else
         {
            int t = (n+1)/2;
            for(i=0;i<t;i++)
             {
                 if(h[i]==(i+1) && h[n-1-i]==(i+1))
                   {
                       
                   }
                 else
                   {
                       corr = false;
                       break;
                   }
             }
         }
        if(corr)
           cout<<"yes\n";
        else
           cout<<"no\n";
    }
    return 0;
}