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

int maxDepth(TreeNode* root){
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

int main(){
    TreeNode*a=new TreeNode(3);
    a->left=new TreeNode(9);
    a->right=new TreeNode(20);
    a->right->left=new TreeNode(15);
    a->right->right=new TreeNode(7);
    cout<<maxDepth(a);
    return 0;

}