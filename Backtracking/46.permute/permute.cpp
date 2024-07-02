#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking (vector<int>& nums, int startIndex,vector<bool>& used) {
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true)continue;
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i,used);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,0,used);
        return result;
    }
};

int main(){
    vector<int> nums={1,2,3};
    Solution a;
    vector<vector<int>> ans=a.permute(nums);
    for(auto row:ans){
        for(auto num:row){
            cout<<num<<",";
        }
        cout<<endl;
    }
    return 0;
}