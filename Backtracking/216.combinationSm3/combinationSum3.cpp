#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> elem;
    vector<vector<int>> result;
    void backTracking(int n,int k,int startIndex){
        if(elem.size()==k){
            int sum=0;
            for(int j=0;j<k;j++){
                sum +=elem[j];
            }
            if(sum==n){
                result.push_back(elem);
                return;
            }
            else{
                return;
            }
        }
        for(int i=startIndex;i<=9;i++){
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
    int n=7;
    int k=3;
    Solution a;
    vector<vector<int>> ans=a.combine(n,k);
    printVector(ans);
    cout<<"Fuck you!!!"<<endl;
    return 0;
}