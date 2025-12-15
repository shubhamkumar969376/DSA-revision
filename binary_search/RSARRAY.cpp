#include<bits/stdc++.h>
using namespace std;

bool check(int x,int val){

}
int RSarr(int arr[],int n){

    int l=0;
    int h=n-1;
    int ans=-1;
    while(l<=h){
        int mid=(l+h)/2;

        if(check(arr[mid])){
            ans=mid;
            h=mid-1;

        }
        else{

            l=mid+1;
        }
    }

}
int main(){

}