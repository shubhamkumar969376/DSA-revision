#include<bits/stdc++.h>
using namespace std;            
vector<vector<int>>g;
vector<int>vis;                                                         
int main(){                                                                 
    int n,m;                                                                
    cin>>n>>m;                                                              
    g.resize(n+1);                                                         
    for(int i=0;i<m;i++){                                                  
        int a,b;                                                           
        cin>>a>>b;                                                         
        g[a].push_back(b);                                                 
        g[b].push_back(a);                                                 
    }                                                                       
    vis.assign(n+1,0);                                                    
    queue<int>q;                                                           
    q.push(1);                                                             
    vis[1]=1;                                                              
    while(!q.empty()){                                                     
        int node=q.front();                                               
        q.pop();                                                         
        cout<<node<<" ";                                                  
        for(auto i:g[node]){                                             
            if(!vis[i]){                                                 
                q.push(i);                                              
                vis[i]=1;                                               
            }                                                           
        }                                                               
    }                                                                   
}