//LCCM actually it is a knapsack problem without dp


#include<bits/stdc++.h>
using namespace std;

int t[100];
int s[100];
int taken[100];
int x,k,n;

int check(int level){
	int timetaken=0;
	int itemtaken=0;
	for(int i=0;i<level;i++){
		if(taken[i]){
			timetaken+=t[i];
			itemtaken+=1;
			
		}
	}
	timetaken+=t[level];
	itemtaken++;
	if(timetaken<=x && itemtaken<=k){
		return 1;
	}
	return 0;
}
int rec(int level){
	if(level==n){
		return 0;
	}
	int ans=rec(level+1);
	if(check(level)){
		taken[level]=1;
		ans=max(ans,rec(level+1)+s[level]);
		taken[level]=0;
		
	}
	return ans;
	
}
int main(){
	
	cin>>n>>x>>k;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	int ans=rec(0);
	cout<<ans<<endl;
	
}