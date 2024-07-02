#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
private:

public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0,used);
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
    vector<int> bn={10,1,2,7,6,1,5};
    Solution a;
    vector<vector<int>> ans=a.combinationSum(bn,8);
    printVector(ans);
    cout<<"Fuck you!!!"<<endl;
    return 0;
}