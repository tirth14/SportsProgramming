#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;  cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++)
            cin>>A[i];
     
    if(n>1 && A[n-1]>A[n-2])
        swap(A[n-1],A[n-2]);
    else
    { 
        // k is the index of element left to the peak element
        int k=n-2;
        while(k>=0 && A[k]>=A[k+1])
            k--;
        
            if(k!=-1)
            {
                int x=n-1;
                while(A[x]<A[k]) x--;
                swap(A[x],A[k]);
            }
            sort(A.begin()+k+1,A.end());
    }
    
    for(int i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
}
