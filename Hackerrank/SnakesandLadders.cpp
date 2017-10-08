#include <bits/stdc++.h>
using namespace std;

struct cell
{
  int val;
  int lvl;
};

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> move(101,-1);
        vector<bool> v(101,false);
        int n;cin>>n;
        for(int i=0;i<n;i++) 
        {
            int src,dest;
            cin>>src>>dest;
            move[src]=dest;
        }
        int m;cin>>m;
        for(int i=0;i<m;i++) 
        {
            int src,dest;
            cin>>src>>dest;
            move[src]=dest;
        }
        
        queue<cell> q;
        cell c0; c0.val=1;c0.lvl=0;
        q.push(c0);
        v[c0.val]=true;
        
        int res=-1; 
        
        while(!q.empty())
        {
            cell ctp=q.front(); q.pop();
            if(ctp.val==100) {res=ctp.lvl; break;}
            
            for(int j=ctp.val+1;j<=ctp.val+6 && j<=100;j++)
            {
                int next=move[j]!=-1?move[j]:j;
                if(!v[next])
                {
                    cell nc; nc.val=next;nc.lvl=ctp.lvl+1;
                    q.push(nc);
                    v[next]=true;
                }
            }
        }
        cout<<res<<endl;
    }
}
