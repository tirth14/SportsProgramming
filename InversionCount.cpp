#include <bits/stdc++.h>
using namespace std;

/*
Inversion Count using Binary Indexed Tree.
Two elements a[i] and a[j] form an inversion if  a[i] > a[j] and i < j. 
*/   

//idx is 1 based.

int getSum(vector<int> &tree, int idx)
{
    int sum=0;
    
    while(idx>0)
    {
       sum+=tree[idx];
       idx-=(idx & -idx);
    }
    return sum;
}

void update(vector<int> &tree, int idx, int val, int n)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

//Replacing elements of A with their corresponding ranking in their sorted version.
//lower_bound(temp.begin(),temp.end(),A[i]) : retuns pointer to the first element which is just greater than or equal to A[i]. 

void convert(vector<int> &A, int n)
{
    vector<int> temp;
    temp=A;
    sort(temp.begin(),temp.end());
    
    for(int i=0;i<n;i++)
    {
        A[i]=lower_bound(temp.begin(),temp.end(),A[i])-temp.begin()+1;
    }
}

int main() 
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    
    convert(A, n);
    
    //BIT Building
    vector<int> tree(n+1,0);
    
    int inv_count=0;
    
    for(int i=n-1;i>=0;i--)
    {
        inv_count+=getSum(tree, A[i]-1);
        update(tree, A[i], 1, n);
    }

    cout<<inv_count<<endl;
}
