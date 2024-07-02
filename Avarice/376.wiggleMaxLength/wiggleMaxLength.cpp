#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isValid(int left,int mid,int right){
    if(right-mid<0&&mid-left>0){
        return true;
    }
    if(right-mid>0&&mid-left<0){
        return true;
    }
    return false;
}

int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        int l=0;
        int m=1;
        int r=2;
        while(r<slow){
            if(isValid(nums[l],nums[m],nums[r])){
                nums[l]=nums[r-2];
                nums[m]=nums[r-1];
                nums[m+1]=nums[r];
                l++;
                m++;
                r++;
            }
            else{
                r++;
                if(r<slow&&isValid(nums[r-2],nums[r-1],nums[r])){
                    nums[l]=nums[r-2];
                    nums[m]=nums[r-1];
                    nums[m+1]=nums[r];
                    l++;
                    m++;
                    r++;
                }
            }
        }
        return m+1;
}

int main(){
    vector<int> nums={1,1,1,2,2,2,1,1,1,3,3,3,2,2,2};
    cout<<wiggleMaxLength(nums)<<endl;
    for(auto num:nums){
        cout<<num<<" ";
    }
    return 0;
}

