#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define p 100000000
#define ll long long


string luky(int n)
{
   //1 = two fours- one seven
    
   if(n<4) return "-1";
   
   int sevens=n/7; int fours=0;
   int r=n%7;
   if(r>=4) {r=r-4; fours++;}
   
   sevens=sevens-r;
   fours=fours+2*r;
    
   if(sevens<0) return "-1";
   
   string res="";
   for(int i=0;i<fours;i++) res+="4";
   for(int i=0;i<sevens;i++) res+="7";
    
   return res;
}

int main() 
{
   int n;
   cin>>n;
   cout<<luky(n)<<endl;
    
}
