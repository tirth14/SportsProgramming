#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string pat;
        cin>>pat;
        
        stack<int> s;
        string res="";
        
        s.push(1);
        
        for(int i=1;i<=pat.length();i++)
        {
           if(pat[i-1]=='D'){ s.push(i+1);}
            
            if(pat[i-1]=='I')
            {
                while(!s.empty())
                {
                    res+=to_string(s.top());
                    s.pop();
                }
                s.push(i+1);
            }
        }
        
                while(!s.empty())
                {
                    res+=to_string(s.top());
                    s.pop();
                }
                
                cout<<res<<endl;
    }
}
