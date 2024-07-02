#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    if(nums[0]>=0){
        if(k=k%2){
            nums[0]=-nums[0];
        }
    }
    else{
        int i=0;
        while(nums[i]<0&&k>0&&i<nums.size()){
            nums[i]=-nums[i];
            i++;
            k--;
        }
        if(i==nums.size()){
            i--;
        }
        if(k=k%2){
            if(nums[i]>nums[i-1]){
                nums[i-1]=-nums[i-1];
            }
            else{
                nums[i]=-nums[i];
            }
        }
    }
    int sum=0;
    for(auto num:nums){
        sum+=num;
    }
    return sum;
}


int main(){
    vector<int> vec={-4,-2};
    cout<<largestSumAfterKNegations(vec,5);
    return 0;
}