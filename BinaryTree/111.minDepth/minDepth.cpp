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


int minDepth(TreeNode* root) {
    queue<TreeNode*> nodeQ;
    if(root==NULL){
        return 0;
    }
    nodeQ.push(root);
    int depth=0;
    while(!nodeQ.empty()){
        int size=nodeQ.size();
        while(size--){
            TreeNode* cur=nodeQ.front();
            if(cur->left)nodeQ.push(cur->left);
            if(cur->right)nodeQ.push(cur->right);
            if(cur->left==NULL&&cur->right==NULL)return depth+1;
            nodeQ.pop();
        }
        depth++;
    }
    return depth;
}

