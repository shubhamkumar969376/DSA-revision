#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int>vis;
vector<int>st;

void dfs(int node ){
	vis[node]=1;
	for(auto i:g[node]){
		if(!vis[node]){
			dfs(i);
		}
	}
	
	st.push_back(node);
	
	
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
	
	vis.assign(n+1,0);
	for(int i=1;i<=n;i++){
		if(!vis[i])
		{
			dfs(i);
		}
	}
	reverse(st.begin(),st.end());
	for(auto i:st){
		cout<<i<<" ";
	}
	cout<<endl;
}