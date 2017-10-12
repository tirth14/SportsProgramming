#include <bits/stdc++.h>
using namespace std;

void ConstructSegA(vector<int> &A,vector<int> &segA,long long node_idx,int start,int end,int op)
{
    if(start==end)
    {
        segA[node_idx]=A[start];
    }
    else
    {
        int mid=(start+end)/2;
        ConstructSegA(A,segA,2*node_idx+1,start,mid,1-op);
        ConstructSegA(A,segA,2*node_idx+2,mid+1,end,1-op);
        if(op==0)
            segA[node_idx]=segA[2*node_idx+1]|segA[2*node_idx+2];
        else
            segA[node_idx]=segA[2*node_idx+1]^segA[2*node_idx+2];
    }
}

void UpdateSegA(vector<int> &A,vector<int> &segA,long long node_idx,int start,int end,int val,int idx,int op)
{
    if(start==end)
    {
        A[idx]=val;
        segA[node_idx]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(idx<=mid)
            UpdateSegA(A,segA,2*node_idx+1,start,mid,val,idx,1-op);
        else
            UpdateSegA(A,segA,2*node_idx+2,mid+1,end,val,idx,1-op);
        
        if(op==0)
            segA[node_idx]=segA[2*node_idx+1]|segA[2*node_idx+2];
        else
            segA[node_idx]=segA[2*node_idx+1]^segA[2*node_idx+2];
    }
}

int main() 
{
   int n,m;
   cin>>n>>m;
   int op=n%2?0:1;
   n=pow(2,n);
   vector<int> A(n);
   for(int i=0;i<n;i++) cin>>A[i];
   
   vector<int> segA((long long)(4*n));

    //op=0 -> OR and op=1 -> XOR at the root node
    ConstructSegA(A,segA,0,0,n-1,op);
    
    //for(int i=0;i<segA.size();i++) cout<<segA[i]<<" "; cout<<endl;
    
    for(int i=0;i<m;i++)
    {
        int p,b;
        cin>>p>>b;
        
        UpdateSegA(A,segA,0,0,n-1,b,p-1,op);
        cout<<segA[0]<<endl;
    }
}
