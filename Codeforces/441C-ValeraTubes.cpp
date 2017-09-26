#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define p 1000000007

void PrintTube(int n,int m,int k)
{
    int dir=0;
    int l=2;
    int lk=m*n-2*(k-1);   //longest length
    for(int i=1;i<=n;i++)
    {   dir=1-dir;
        for(int j=1;j<=m;j++)
        {   
            if(k>0 && l==2)
            {
             l=0;k--;if(i!=1||j!=1) cout<<endl;
             if(k>0) cout<<2<<" "; else{cout<<lk<<" ";}
            }
            if(dir==1)
               {cout<<i<<" "<<j<<" ";l++;}
            else
               {cout<<i<<" "<<(m+1)-j<<" ";l++;}
        }
    }
}

int main() 
{
    int n,m,k;
    cin>>n>>m>>k;
    PrintTube(n,m,k);
}
