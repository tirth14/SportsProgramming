#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int x,y,z;
    int a,b,c;
    vector<int> A(7);
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    for(int i=1;i<=6;i++) cin>>A[i];
    
    int res=0;
    
    if(x>a) res+=A[6];
    if(x<0) res+=A[5];
    
    if(y>b) res+=A[2];
    if(y<0) res+=A[1];
    
    if(z>c) res+=A[4];
    if(z<0) res+=A[3];
    
    cout<<res<<endl;
    
}
