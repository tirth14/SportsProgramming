#include <bits/stdc++.h>

using namespace std;

long maximumSum(vector<long> a, long m)
{
    int n=a.size();
    set<long> set;
    
    long prefix=0;
    long res=0;

    for(int i=0;i<n;i++)
    {
        prefix=(prefix+a[i])%m;
        res=max(res,prefix);
        
        // maxSum_i=(prefix_i-prefix_j+m)%m; 
        // prefix_j should be just greater than prefix_i for maximum maxSum_i
        
        auto itr=set.lower_bound(prefix+1);
        
        if(itr!=set.end())
        {
            res=max(res,(prefix-*(itr)+m)%m);
        }
        set.insert(prefix);
    }
    
    return res;
}


int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        long m;
        cin >> n >> m;
        vector<long> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        long result = maximumSum(a, m);
        cout << result << endl;
    }
    return 0;
}
