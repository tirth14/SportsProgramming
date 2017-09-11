#include <bits/stdc++.h>
using namespace std;

void ConstructSegTree(vector<int> &A,vector<int> &segA,int node_idx,int start,int end)
{
    if(start==end)
    {
        segA[node_idx]=A[start];
    }
    else
    {
        int mid=(start+end)/2;
        ConstructSegTree(A,segA,2*node_idx+1,start,mid);
        ConstructSegTree(A,segA,2*node_idx+2,mid+1,end);
        segA[node_idx]=min(segA[2*node_idx+1],segA[2*node_idx+2]);
    }
}

int minQuery(vector<int> &segA,int node_idx,int start,int end,int l,int r)
{
    
    if(l<=start && r>=end)
    {
        return segA[node_idx];
    }
    if(r<start || l>end)
    {
        return INT_MAX;
    }
    
        int mid=(start+end)/2;
        return min(minQuery(segA,2*node_idx+1,start,mid,l,r),minQuery(segA,2*node_idx+2,mid+1,end,l,r));
    
}

void UpdateQuery(vector<int> &segA,vector<int> &A,int node_idx,int start,int end,int val,int idx)
{
    if(start==end)
    {
        segA[node_idx]=val;
        A[idx]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(idx<=mid)
        {
        UpdateQuery(segA,A,2*node_idx+1,start,mid,val,idx);
        }
        else
        {
        UpdateQuery(segA,A,2*node_idx+2,mid+1,end,val,idx);   
        }
        
        segA[node_idx]=min(segA[2*node_idx+1],segA[2*node_idx+2]);
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    
    vector<int> A(n);
    vector<int> segA(4*n); // Why 4n ???????
    
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    
    ConstructSegTree(A,segA,0,0,n-1);
    
    for(int i=0;i<q;i++)
    {
        char t;
        int a,b;
        cin>>t>>a>>b;
        if(t=='q')
        {
            cout<<minQuery(segA,0,0,n-1,a-1,b-1)<<endl;
        }
        else
        {
            UpdateQuery(segA,A,0,0,n-1,b,a-1);
        }
    }
}
