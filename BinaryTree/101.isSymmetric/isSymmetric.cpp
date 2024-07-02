#include<iostream>
#include<vector>
#include<stack>
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

// void traversal(TreeNode* cur, vector<int>& vec) {
//     if (cur == NULL) {
//         return;
//     }
//     traversal(cur->left, vec);  // 左
//     vec.push_back(cur->val);    // 中
//     traversal(cur->right, vec); // 右
// }

bool judge(vector<int> level){
    stack<int> frontHalf;
    for(int i=0;i<level.size();i++){
        if(i<level.size()/2){
            frontHalf.push(level[i]);
        }
        else{
            if(level[i]!=frontHalf.top()){
                return false;
            }
            frontHalf.pop();
        }
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    if(root==NULL){
        return true;
    }
    queue<TreeNode*> nodeQ;
    vector<vector<int>> trevelResult;
    nodeQ.push(root);
    while(!nodeQ.empty()){
        int size=nodeQ.size();
        vector<int> level;
        while(size--){
            TreeNode* cur=nodeQ.front();
            if(cur==nullptr){
                level.push_back(101);
                nodeQ.pop();
                continue;
            }
            if(cur->left){
                nodeQ.push(cur->left);
            }
            else{
                nodeQ.push(nullptr);
            }
            if(cur->right){
                nodeQ.push(cur->right);
            }
            else{
                nodeQ.push(nullptr);
            }
            level.push_back(cur->val); 
            nodeQ.pop();
        }
        if(level.size()==1){  
            continue;
        }
        else if(judge(level)==false){
            return false;
        }
        else{
            continue;
        }
    }
    return true;
}

int main(){
    TreeNode* a=new TreeNode(1);
    a->left=new TreeNode(2);
    a->right=new TreeNode(2);
    a->left->left = new TreeNode(3);
    a->left->right = new TreeNode(4);
    a->right->left=new TreeNode(4);
    a->right->right = new TreeNode(3);
    cout<<isSymmetric(a);
    vector<int> b={3,4,4,3};
    judge(b);
    return 0;
}
