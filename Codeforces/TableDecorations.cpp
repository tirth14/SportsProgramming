#include <bits/stdc++.h>
using namespace std;


int main()
{
   vector<long long> A(3);
   
   for(int i=0;i<3;i++) cin>>A[i];
    
   sort(A.begin(),A.end());
    
   if((A[0]+A[1])*2<=A[2]) cout<<A[0]+A[1]<<endl;
   else
   {
       cout<<(A[0]+A[1]+A[2])/3<<endl;
   }
   
}


