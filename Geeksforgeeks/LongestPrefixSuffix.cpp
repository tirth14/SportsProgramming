#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        vector<int> lps(n);
        
        lps[0]=0;
        
        for(int i=1;i<n;i++)
        {
            int len=lps[i-1];
            if(s[i]==s[len])
            {lps[i]=len+1;}
            else if(len!=0 && s[lps[len-1]]==s[i])
            {
                lps[i]=lps[len-1]+1;
            }
            else
            {
                lps[i]=s[0]==s[i]?1:0;
            }
        }
        
        cout<<lps[n-1]<<endl;
    }
}
