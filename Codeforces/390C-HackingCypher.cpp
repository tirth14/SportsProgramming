#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsDiv(string s,int a)
{
    int n=s.length();
    if(s[0]-'0'==0) return false;
    
    int rem=(s[0]-'0')%a;
    for(int i=1;i<n;i++)
    {
        rem=(rem*10+s[i]-'0')%a;
    }
    return rem==0;
}


int main() 
{
  string s;
  cin>>s;
  int n=s.length();  
  int a,b;
  cin>>a>>b;
  string res="NO";
  vector<int> remp(n),rems(n);
 
    remp[0]=(s[0]-'0')%a;
    for(int i=1;i<n;i++)
    {
        remp[i]=(remp[i-1]*10+s[i]-'0')%a;
    }
    
    int x=1;
    rems[n-1]=(s[n-1]-'0')%b;
    for(int i=n-2;i>=0;i--)
    {
        x=(10*x)%b;
        rems[i]=(((s[i]-'0')*x)%b+rems[i+1])%b;
    }
    
  for(int i=0;i<n-1;i++)
  {
      if(remp[i]==0 && s[i+1]-'0'!=0 && rems[i+1]==0) 
      {res="YES\n"+s.substr(0,i+1)+"\n"+s.substr(i+1,n-(i+1));break;}
  }
   cout<<res<<endl;
}
