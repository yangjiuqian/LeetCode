#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.size()==1)return nums[0];
    int result=nums[0];
    int sum=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>0&&sum>0){
            sum+=nums[i];
            result=max(sum,result);
        }
        else if(nums[i]>0&&sum<=0){
            sum=nums[i];
            result=max(sum,result);
        }
        else if(nums[i]<0&&sum>0){
            sum+=nums[i];
        }
        else{
            continue;
        }
    }
    return result;
}


int main(){
    vector<int> nums={1,2,-1,-2,2,1,-2,1,4,-5,4};
    cout<<maxSubArray(nums);
    return 0;
}