#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL){
        return {{}};
    }
    vector<vector<int>> result;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        vector<int> line;
        // TreeNode* cur=nodeQueue.front();
        while(size--){
            TreeNode* cur=nodeQueue.front();
            if(cur->left)nodeQueue.push(cur->left);
            if(cur->right)nodeQueue.push(cur->right);
            line.push_back(cur->val);
            nodeQueue.pop();
        }
        result.push_back(line);
    }
    return result;
}

void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans=levelOrder(root);
    print2DVector(ans);
    return 0;
}