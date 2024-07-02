#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> elem;
    vector<vector<int>> result;
    void backTracking(int n,int k,int startIndex){
        if(elem.size()==k){
            result.push_back(elem);
            return;
        }
        for(int i=startIndex;i<=n;i++){
            elem.push_back(i);
            backTracking(n, k, i+1);
            elem.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backTracking(n,k,1);
        return result;
    }
};

void printVector(const std::vector<std::vector<int>>& vec) {
    // 使用嵌套循环遍历二维vector并输出每个元素
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl; // 在每行结束时输出换行符
    }
}

int main(){
    int n=4;
    int k=2;
    Solution a;
    vector<vector<int>> ans=a.combine(n,k);
    printVector(ans);
    cout<<"Fuck you!!!"<<endl;
    return 0;
}

/*
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

*/