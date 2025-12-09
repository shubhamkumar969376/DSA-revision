#include<bits/stdc++.h>
using namespace std;
bool check(int x,int target){

    if(x>target){
        return true;
    }
    return false;
    

}

int BS(int arr[],int n){
    int l=0,h=n-1;
    int ans=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(arr[mid],3)){
            ans=mid;
            h=mid-1;


        }
        else{
            l=mid+1;

        }
    }

    return ans;


}
int main(){
    int arr[]={1,2,3,3,4,5,6,7};

    int ans=BS(arr,8);
    cout<<ans<<endl;
}