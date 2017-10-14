#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    
    sort(A.begin(),A.end());  
    
    int s=0; int count=0; int i=1; int ep=0;
    while(i<n)
    {
        if(A[i]-A[s]<=k)
        {
            //moving towards right keeping in mind the leftmost point
            i++;ep=0;
        }
        else
        {   //transmitter installed
            count++;
            int tr=i-1;
            while(i<n && A[i]-A[tr]<=k) //finding rightmost point that will be served by this transmitter 
                i++;
            s=i;ep=1;
        }
    }
   
    if(ep==0) count++;
    cout<<count<<endl;
}
