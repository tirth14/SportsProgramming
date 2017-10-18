#include <bits/stdc++.h>
using namespace std;


//Idea : Hang boxes, compact packing, greedy, stack smaller boxes to put on a just larger strength box

int main() 
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    
    int res=0;
    
    sort(A.begin(),A.end());
    
    vector<bool> taken(n);
    
    for(int i=0;i<n;i++)
    {
        if(!taken[i]) 
        {
        res++;
        int strength_required=-1;
        for(int j=i;j<n;j++)
        {
            if(!taken[j] && A[j]>strength_required)
            { taken[j]=true; strength_required++; }
        }
        }
    }
   
    cout<<res<<endl;
}
