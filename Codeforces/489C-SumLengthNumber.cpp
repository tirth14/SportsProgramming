#include<bits/stdc++.h>
using namespace std;

string MaxNumber(int m,int sum)
{
    if(sum>9*m || (sum==0 && m>1)) return "-1";
    if(m==1 && sum==0) return "0";
    
    string res="";
    int len=0;
    
    while(sum>=9)
    {
        res=res+"9";len++;
        sum-=9;
    }
    if(len<m && sum>0)
    {
        res=res+char(sum+'0');len++;
    }
    while(len<m)
    {
        res=res+"0";len++;
    }
    
    return res;
}

string MinNumber(int m,int sum)
{
    if(sum>9*m || (sum==0 && m>1)) return "-1";
    if(m==1 && sum==0) return "0";
    
    string res="";
    int len=0;
    
    int q=sum/9; int r=sum%9;
    
    if(r==0) { r=9;q--;}
    while(len<q)
    {
        res="9"+res;len++;
    }
    
    if(len==m-1)
    {
        res=char(r+'0')+res;len++;
        return res;
    }
    else{res=char(r-1+'0')+res;len++;}
    
    while(len<m-1)
    {
        res="0"+res;len++;
    }
    
    res="1"+res;len++;
    
    return res;
}


int main() 
{
  int m, s;
  cin>>m>>s;
  
  cout<<MinNumber(m,s)<<" "<<MaxNumber(m,s)<<endl;
  
}

