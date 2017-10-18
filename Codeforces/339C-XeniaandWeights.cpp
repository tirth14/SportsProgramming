#include <bits/stdc++.h>
using namespace std;

//bal: sum(leftpan)-sum(rightpan) 

bool isPoss(int step,int m,string s,int bal,vector<int> &w)
{
    if(step==m) 
    {
        return true;
    }
    
    for(int i=abs(bal)+1;i<=10;i++)
    {
        if(s[i-1]=='1' && w[w.size()-1]!=i)
        {
        w.push_back(i);
        int new_bal=bal<=0?bal+i:bal-i;
        if(isPoss(step+1,m,s,new_bal,w))
            return true;
        w.pop_back();
        }
    }
    return false;
}

int main() 
{
    string s;
    cin>>s;

    int m;
    cin>>m;
    
    vector<int> w;
    w.push_back(0);
    bool b=isPoss(0,m,s,0,w);
    
    if(!b) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=1;i<w.size();i++)
        {
            cout<<w[i]<<" ";
        }
        cout<<endl;
    }   
}
