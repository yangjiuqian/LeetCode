#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMax(vector<int> nums,int begin,int end){
    int maxI=end;
    for(int i=begin;i<end;i++){
        if(i+nums[i]>end+nums[end]){
            maxI=i;
            // break;
        }
    }
    return maxI;
}

int jump(vector<int>& nums) {
    if(nums.size()==1)return 0;
    int left = 0;
    int right = 0;
    int step=0;
    while(right<=nums.size()-1){
        int i=findMax(nums, left,right);
        cout<<i<<",";
        step++;
        if(i!=right){
            left=i;
            right=i+nums[i];
        }
        else{
            left=right;
            right+=nums[right];
        }
    }
    return step;
}

int jumpRight(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int curDistance = 0;    // 当前覆盖最远距离下标
    int ans = 0;            // 记录走的最大步数
    int nextDistance = 0;   // 下一步覆盖最远距离下标
    for (int i = 0; i < nums.size(); i++) {
        nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
        if (i == curDistance) {    
            cout<<i<<",";                     // 遇到当前覆盖最远距离下标
            ans++;                                  // 需要走下一步
            curDistance = nextDistance;             // 更新当前覆盖最远距离下标（相当于加油了）
            if (nextDistance >= nums.size() - 1) break;  // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
        }
    }
    return ans;
}

int main(){
    vector<int> vec3={1,2,3};
    vector<int> vec1={5,4,0,1,3,6,8,0,9,4,9,1,8,7,4,8};
    vector<int> vec2={7,8,4,2,0,6,4,1,8,7,1,7,4,1,4,1,2,8,2,7,3,7,8,2,4,4,5,3,5,6,8,5,4,4,7,4,3,4,8,1,1,9,0,8,2};
    cout<<jumpRight(vec2);
    return 0;
}
