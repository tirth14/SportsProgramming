#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> s;
bool v[101][101]={0};

bool dfs(int i,int j,int &count)
{
    v[i][j]=true;
    
    bool r=s[i][j]=='*';
    if(r) return r;
    bool a=true;
  
    int x[]={0,1,0,-1}; int y[]={1,0,-1,0};
  
    for(int k=0;k<4;k++)
    {
        int x1=i+x[k],y1=j+y[k];
     
        if(x1>=0 && x1<n && y1>=0 && y1<m && !v[x1][y1] && s[x1][y1]!='X')
        {
            bool x=dfs(x1,y1,count);
            r=r||x;  //true if node lies on main path
            a=a&&x;  //false if there is atleast one unnecessary branch from this point
        }
    }
    if(r && !a) 
    count++;
   
    return r; 
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
       
        cin>>n>>m;
   
        for(int i=0;i<n;i++) 
        {
          string st; cin>>st; s.push_back(st);
        }
        int k; cin>>k;
       
        int x,y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) if(s[i][j]=='M'){x=i;y=j;break;}
        }
        
        int count=0;
        bool b=dfs(x,y,count);
             
        if(count==k) cout<<"Impressed"<<endl;
        else cout<<"Oops!"<<endl;
                              
         s.clear();
         for(int i=0;i<101;i++)
         {
           for(int j=0;j<101;j++) v[i][j]=false;
         }
    }
}
