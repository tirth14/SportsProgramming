#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++)
            cin>>A[i];
        
        sort(A.begin(),A.end());
        
        int res=0;
        
        for(int i=0;i<n-2;i++)
        {
            int k=i+2;
            for(int j=i+1;j<n-1;j++)
            {
                while(k<n && A[i]+A[j]>A[k]) 
                {
                    res+=(k-j);
                    k++;
                }
            }
            
        }
        
        cout<<res<<endl;
    }
}
