#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include <cmath>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getDepth(TreeNode* root){
    if(root==NULL)return 0;
    int leftDeepth = getDepth(root->left);
    if(leftDeepth==-1)return -1;
    int rightDeepth = getDepth(root->right);
    if(rightDeepth==-1)return -1;
    int result;
    if(abs(leftDeepth-rightDeepth)>1){
        result=-1;
    }
    else{
        result =1+max(leftDeepth, rightDeepth);
    }
    return result;
}

bool isBalenced(TreeNode* root){
    return getDepth(root) == -1 ? false : true; 
}

int main(){
    TreeNode* a=new TreeNode(1);
    a->left=new TreeNode(2);
    a->right=new TreeNode(2);
    a->left->left = new TreeNode(3);
    a->left->right = new TreeNode(4);
    a->right->left=new TreeNode(4);
    a->right->right = new TreeNode(3);
    cout<<isBalenced(a);
    return 0;
}
