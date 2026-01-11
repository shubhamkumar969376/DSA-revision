#include<bits/stdc++.h>
using namespace std; 
vector<vector<int>>g;
vector<int>color;   
bool checkBipartite=true;
bool bipartiteDfs(int node,int c){
    color[node]=c;
    for(auto i:g[node]){
        if(color[i]==-1){
            bipartiteDfs(i,1-c);
        }
        else if(color[i]==c){
            //conflict in coloring
            //not bipartite
            //you can set a global flag here
            checkBipartite=false;
        }
    }
    return checkBipartite;
}    
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
    color.assign(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            bipartiteDfs(i,0);
        }
    }

}