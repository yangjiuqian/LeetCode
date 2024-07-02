#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    string elem;
    vector<string> result;
    void backTracking(string digits,int index){
        if(index==digits.length()){
            result.push_back(elem);
            return;
        }
        int dig=digits[index]-'0';
        string letter = letterMap[dig];
        for(int i=0;i<=letter.size();i++){
            elem.push_back(letter[i]);
            backTracking(digits,index+1);
            elem.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        backTracking(digits,0);
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
    string bn="234";
    Solution a;
    vector<string> ans=a.letterCombinations(bn);
    cout<<"Fuck you!!!"<<endl;
    return 0;
}