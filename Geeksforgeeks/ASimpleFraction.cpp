#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,D;
        cin>>N>>D;
        
        if(N%D==0) 
            cout<<N/D<<endl;
        else
        {
            string res=to_string(N/D);
            res+='.';
            
            map<int,int> hash;
            string after_decimal="";
            
            int rem=N%D;
            
            while(rem!=0 && hash.find(rem)==hash.end() )
            {
                hash[rem]=after_decimal.length();
                rem*=10;
                int res_part=rem/D;
                after_decimal+=to_string(res_part);
                rem=rem%D;
            }
            
            if(rem==0) 
                res+=after_decimal;
            else
            {
                 string recurring_part=after_decimal.substr(hash[rem]);
                 string non_recurring_part=after_decimal.substr(0,after_decimal.length()-recurring_part.length());
                 res+= non_recurring_part+'('+recurring_part+')';
            }
            
            cout<<res<<endl;
               
            //string x="abcdefgh";
            //cout<<x.substr(0)<<endl;
        }
    }
}
