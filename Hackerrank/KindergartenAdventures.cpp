#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//The ++ -- trick

int main() 
{
    int n;
    cin>>n;
    vector<int> t(n+1);
    for(int i=1;i<=n;i++) cin>>t[i];
    
    vector<int> segment(n+2,0);  //add 1 to range if student becomes happy.
    for(int i=1;i<=n;i++)
    {
        if(t[i]<n && t[i]!=0)
        {
          int s=i-t[i]+1;int e=i;
          //unhappy range
          //cout << s << " " << e << endl;
          if(s<=0) 
          {
          s+=n;
          //happy range
          //cout << e+1 << " " << s-1 << endl;
          segment[e+1]++;
          segment[s]--;
          }
        else
        {
          //happy range
          //cout << 1 << " " << s-1 << endl;
          //cout << e+1 << " " << n << endl;
          segment[1]++;
          segment[s]--;
          segment[e+1]++;
          segment[n+1]--;
        }
        }
    } 
    
    //summing vote's for each id
    for(int i=1;i<=n+1;i++)
    {
        segment[i]+=segment[i-1];
    }
    
    //choosing id with maximum votes
    int res=1;int max=segment[1];
    for(int i=1;i<=n+1;i++)
    {
        //cout << segment[i] << " # ";
        if(max<segment[i]) {max=segment[i];res=i;}
    }
      
    cout<<res<<endl;
}
