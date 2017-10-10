#include <bits/stdc++.h>
using namespace std;

//Idea : recursively try to fix the elements which will definitely be there before kth element. 

//i and j are starting indices of A and B respectively.
//m and n are length of A and B into consideration.

int kth(vector<int> &A,vector<int> &B,int i,int m,int j,int n,int k)
{
    if(n<m) return kth(B,A,j,n,i,m,k); //making A samller than B.
    
    if(m==0) return B[j+k-1];

    if(k==1) return min(A[i],B[j]);
   
    int fixA=min(k/2,m);
    int fixB=min(k/2,n);
    
    if(A[i+fixA-1]>B[j+fixB-1])
    {
         return kth(A,B,i,min(m,k-fixB),j+fixB,n-fixB,k-fixB);
    }
    else 
    {
         return kth(A,B,i+fixA,m-fixA,j,min(n,k-fixA),k-fixA);
    }
   
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,k;
        cin>>m>>n>>k;
        vector<int> A(m),B(n);
        for(int i=0;i<m;i++) cin>>A[i];
        for(int i=0;i<n;i++) cin>>B[i];
        
        //k is 1 indexed.
        
        cout<<kth(A,B,0,m,0,n,k)<<endl;
    }
}
