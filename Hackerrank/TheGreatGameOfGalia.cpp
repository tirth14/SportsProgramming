#include <bits/stdc++.h>
using namespace std;

//Idea : Probability of being a leaf node
//       1/3 non-extreme node
//       1/2 extreme node

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        long long sum=0;
        long long mx=a[0],mn=a[0];
        
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        
        if(n==1) {cout<<a[0]<<endl;continue;}
        
        sum-=(mx+mn);
        
        long long p=2*sum+3*(mx+mn);
        long long q=6;
        if(p%2==0)
        {
            p/=2;
            q/=2;
        }
        if(p%3==0)
        {
            p/=3;
            q/=3;
        }
        
        if(q==1)
        {
            cout<<p<<endl;
        }
        else
        {
            cout<<p<<"/"<<q<<endl;
        }
    } 
}
