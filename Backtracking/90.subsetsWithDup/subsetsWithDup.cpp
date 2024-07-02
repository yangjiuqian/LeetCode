#include<iostream>
#include<vector>
#include <cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking (vector<int>& nums, int startIndex,vector<bool>& used) {
        result.push_back(path);
        // if(startIndex>1&&used[startIndex-1]==false)return;
        if(startIndex>=nums.size()){
            return;
        }
        for(int i=startIndex;i<nums.size();i++){
            if(i>1&&used[i-1]==false)continue;
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i+1,used);
            path.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums,0,used);
        return result;
    }
};


int main(){
    vector<int> vec = {1,2,2};
    Solution a;
    vector<vector<int>> ans = a.subsetsWithDup(vec);
    for(auto rew:ans){
        for(auto strs:rew){
            cout<<strs<<",";
        }
        cout<<endl;
    }
    cout<<"Fuck you!!!"<<endl;
    return 0;
}