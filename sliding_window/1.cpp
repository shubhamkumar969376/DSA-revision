  
  // you can thinks as snake eating apples or flipping k zeros to 1s
  #include<bits/stdc++.h>
using namespace std;
int main(){
	
	int head=-1;
	int tail=0;
	int cnt=0;
	int ans=0;
	vector<int>nums={1,0,0,0,1,0,0,0,1,1};
	int n=nums.size();
	int k=3;
	
	while(tail<n )
	{
		while( head+1<n&& ((cnt<k && nums[head+1]==0 ) ||(cnt==k && nums[head+1]==1)))
		{
			head++;
			if(nums[head]==0){
				cnt++;
			}
			
		}
		ans=max(ans,head-tail+1);
		if(head>tail){
			if(nums[tail]==0){
				cnt--;
			}
			tail++;
			
		}
		else {
			tail++;
			head=tail-1;
			
			
		}
	}
	cout<<ans<<endl;
}