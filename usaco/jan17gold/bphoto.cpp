
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ofstream fout ("bphoto.out");
    ifstream fin ("bphoto.in");
    long int n,i;
    fin>>n;
    vector<long long int> h(n);
    for(i=0;i<n;i++)
         fin>>h[i];
    long int ans = 0;
    for(i=0;i<n;i++)
      {
        long int l=0,r=0;
        for(long int j=0;j<i;j++)
            {
              if(h[j]>h[i])
                   l++;
            }
         for(long int j=i+1;j<n;j++)
            {
              if(h[j]>h[i])
                   r++;
            } 
          if(l>2*r)
              ans++;
          if(r>2*l)
               ans++;        
      }   
    fout<<ans<<"\n";  
    return 0;
}