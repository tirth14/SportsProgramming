#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
int commDiv(int a,int b)
{
    // find gcd of a,b
    int n = gcd(a, b);
 
    // Count divisors of n.
    int result = 0;
    for (int i=1; i<=sqrt(n); i++)
    {
        // if 'i' is factor of n
        if (n%i==0)
        {
            // check if divisors are equal
            if (n/i == i)
                result += 1;
            else
                result += 2;
        }
    }
    return result;
}
 

int lps(string s)
{
    int n=s.length();
    vector<int> lps(n);
    lps[0]=0;
    
    for(int i=1;i<n;i++)
    {
       if(s[i]==s[lps[i-1]])
       {
           lps[i]=lps[i-1]+1;
       } 
       else
       {
           if(lps[i-1]>0)
           {
           int x=lps[lps[i-1]-1];
           if(s[x]==s[i])
               lps[i]=x+1;
           }
           else
               lps[i]=s[0]==s[i]?1:0;
       }
    }
    
    return lps[n-1];
}

bool isUnit(string s,int l)
{   
    int n=s.length();
    
    l=n-l;  //length of unit
    
    if(n%l!=0) return false;
    
    string unit=s.substr(0,l);
    
    for(int i=0;i<n;i+=l)
    {
        if(s.compare(i,l,unit)!=0) return false;
    }
    return true;
}

int main() 
{
    string s1,s2;
    cin>>s1>>s2;
    
    if(s1.length()<s2.length())
    {
        string temp=s2;
        s2=s1;
        s1=temp;
    }
    
    int lps1=lps(s1);
    int lps2=lps(s2);
    
    string u1=s1.substr(0,s1.length()-lps1);
    string u2=s2.substr(0,s2.length()-lps2);
    
    //For aba abaaba
    if(s2.compare(u1)==0 && isUnit(s1,lps1)) cout<<1<<endl;
    
    else if(u1.compare(u2)!=0 || !isUnit(s1,lps1) || !isUnit(s2,lps2)) cout<<"0"<<endl;
    
    else
    {
        int res=0;
        int m=u1.length();
        int n1=s1.length()/m;
        int n2=s2.length()/m;
        int new_n=min(n1,n2);
        
        res=commDiv(n1,n2);
       
        cout<<res<<endl;
    }
}
