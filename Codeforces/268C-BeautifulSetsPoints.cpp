#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PrintN(int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<i<<" "<<(i+1)<<endl;
    }
}

void PrintM(int m)
{
    for(int i=0;i<=m;i++)
    {
        cout<<i+1<<" "<<i<<endl;
    }
}

void PrintMN(int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<i<<" "<<n-i<<endl;
    }
} 

int main() 
{
    int m,n;
    cin>>n>>m;
    
    cout<<min(m,n)+1<<endl;
    if(n<m)
    PrintN(n);
    else if(m<n)
    PrintM(m);
    else{PrintMN(n);}
}
