
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int pref[n+1];
	pref[0]=0;
	for(int i=1;i<n;i++){
		pref[i]=arr[i-1]+pref[i-1];
	}
	for(int i=0;i<n;i++){
		cout<<pref[i]<<" ";
	}
	
	
}

