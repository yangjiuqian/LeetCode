#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
private:

public:
    vector<int> nums;
    vector<vector<int>> result;
    void backTracking(vector<int>& candidates, int target,int sum,int index){
        if(sum==target){
            result.push_back(nums);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            sum+=candidates[i];
            nums.push_back(candidates[i]);
            backTracking(candidates,target,sum, i);
            sum-=candidates[i];
            nums.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates,target,0,0);
        return result;
    }
};

void printVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}


int main(){
    vector<int> bn={3,5,8};
    Solution a;
    vector<vector<int>> ans=a.combinationSum(bn,11);
    printVector(ans);
    cout<<"Fuck you!!!"<<endl;
    return 0;
}