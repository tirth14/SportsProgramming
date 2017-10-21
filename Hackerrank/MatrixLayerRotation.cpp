#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

void rvrs(vector<int> &A,int l,int r)
{
    int n=A.size();
    while(l<r)
    {
        swap(A[l],A[r]);
        l++;r--;
    }
}

void rotatebyk(vector<int> &A,int k)
{
    int n=A.size();
    k=k%n;
    
    rvrs(A,0,k-1);
    rvrs(A,k,n-1);
    rvrs(A,0,n-1);
}

int main() 
{
    int m,n,rr;
    cin>>m>>n>>rr;
    
    vector<vector<int> > A(m,vector<int> (n));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>A[i][j];
    }
    
    
    for(int k=0;k<min(m,n)/2;k++)
    {
        int r=m-2*k,c=n-2*k;
        
        vector<int> s(2*(r+c-2));
        
        int x=0;
        
        for(int j=k;j<n-k-1;j++) { s[x]=A[k][j];x++; }
        for(int i=k;i<m-k-1;i++)   { s[x]=A[i][n-k-1];x++;}
        for(int j=n-k-1;j>k;j--) {s[x]=A[m-k-1][j]; x++;}
        for(int i=m-k-1;i>k;i--) {s[x]=A[i][k];x++;}
        
        rotatebyk(s,rr);
         
        x=0;
       
        for(int j=k;j<n-k-1;j++) { A[k][j]=s[x];x++; }
        for(int i=k;i<m-k-1;i++)   { A[i][n-k-1]=s[x];x++;}
        for(int j=n-k-1;j>k;j--) {A[m-k-1][j]=s[x]; x++;}
        for(int i=m-k-1;i>k;i--) {A[i][k]=s[x];x++;}
        
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
