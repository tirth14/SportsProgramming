#include <bits/stdc++.h>
using namespace std;

int c(int a,int b)
{
    if(a%b==0) return a/b;
    
    return 1+a/b;
}

int main()
{
   int z,n;
   cin>>z>>n;
   
   if(c(n,2)>z+1 || z>n+1)
   {
        cout<<-1<<endl;    
   } 
   else
   {
       string res="";
       if(z==n)
       {
           for(int i=0;i<z;i++) res+="01";
       }
       else if(z==n+1)
       {
           for(int i=0;i<n;i++) res+="01";
           res+="0";
       }
       else
       {
           vector<int> A(z+1,0);
           for(int i=0;i<A.size();i++)
           {
               A[i]++;n--;
           }
           for(int i=0;i<A.size()&&n>0;i++)
           {
               A[i]++;n--;
           }
           
           for(int i=0;i<A.size()-1;i++)
           {
               if(A[i]==1) res+="10";
               else{res+="110";}
           }
           
           if(A[A.size()-1]==1) 
             {res+="1";}
           else{res+="11";}
       } 
       
       cout<<res<<endl;
   }
    
}

