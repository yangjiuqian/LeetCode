#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking (vector<int>& nums, int startIndex) {
        if(result.size()==pow(2,nums.size())-1){
            return;
        }
        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            result.push_back(path);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};


int main(){
    vector<int> vec = {1,2,3};
    Solution a;
    vector<vector<int>> ans = a.subsets(vec);
    for(auto rew:ans){
        for(auto strs:rew){
            cout<<strs<<",";
        }
        cout<<endl;
    }
    cout<<"Fuck you!!!"<<endl;
    return 0;
}