#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for(int i=0;i<nums.size();i++){
            if(used[i]==true)continue;
            if(uset.find(nums[i])!=uset.end())continue;
            path.push_back(nums[i]);
            used[i]=true;
            uset.insert(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};

int main(){
    vector<int> nums={3,3,0,3};
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