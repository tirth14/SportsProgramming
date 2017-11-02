#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
       int a,b,x;
       cin>>a>>b>>x;
     
    int f=b-x+1;
    if(2*f<=b || f<a)
    {
       cout<<-1<<endl;
       return 0;
    }
   
    for(int i=f;i<=b;i++)
        cout<<i<<" ";
        
        cout<<endl;
    }
}
