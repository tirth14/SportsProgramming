#include <bits/stdc++.h>
using namespace std;
#define p 1000000007

int main()
{
   int n;
   cin>>n;
   vector<long long> A(n);
   vector<long long> S(n);
   long long sum=0;
   long long res=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        sum+=A[i];
    }
    
    if(sum%3!=0 || n<3)
    {
        cout<<0<<endl;
    }
    else
    {
        long long curr_sum=0;
        long long count=0;
        for(int i=n-1;i>=0;i--)
        {
            curr_sum+=A[i];
            if(curr_sum==sum/3) count++;
            S[i]=count;
        }
        
        curr_sum=0;
        for(int i=0;i<n-2;i++)
        {
            curr_sum+=A[i];
            if(curr_sum==sum/3)
            {
                res+=S[i+2];
            }
        }
        
        cout<<res<<endl;
    }
    
}


