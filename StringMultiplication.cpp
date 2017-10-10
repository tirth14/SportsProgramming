
https://discuss.leetcode.com/topic/30508/easiest-java-solution-with-graph-explanation

#include <bits/stdc++.h>
string multiplyStrings(string s1, string s2) 
{
    int m=s1.length();
    int n=s2.length();
    string sum(m+n,'0'); //maximum length of result
   
   //building result from left to right
   
   for(int i=m-1;i>=0;i--)
   {
       for(int j=n-1;j>=0;j--)
       {
           int mul=(s1[i]-'0')*(s2[j]-'0');
           int tmp=(sum[i+j+1]-'0')+mul; //total dump at (i+j+1)th position
           sum[i+j+1]=tmp%10+'0';        //finalizing (i+j+1)th position of sum
           sum[i+j]+=tmp/10;             //carry forwarding to (i+j)th position
       }
   }
   
   int start=0;
   while(sum[start]=='0') start++;
   if(start==n+m+1) return "0";
   return sum.substr(start);
}
