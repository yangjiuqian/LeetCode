#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class sulotion{
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    bool result = false;
    int pathSum=0;
public:
    sulotion(){
        cout<<"start"<<endl;
    }

    TreeNode* createBinaryTree(const vector<int>& arr, int index, int n) {
        if (index < n) {
            if (arr[index] == INT_MAX) {
                return NULL; 
            }
            TreeNode* root = new TreeNode(arr[index]);
            root->left = createBinaryTree(arr, 2 * index + 1, n);
            root->right = createBinaryTree(arr, 2 * index + 2, n);
            return root;
        }
        return NULL;
    }

    void findPath(TreeNode* root,int target){
        if(root->left==NULL&&root->right==  NULL){
            pathSum+=root->val;
            if(pathSum==target){
                result = true;
            }
            return;
        }
        pathSum+=root->val;
        if(root->left){
            findPath(root->left, target);
            pathSum-=root->left->val;
        }
        if(root->right){
            findPath(root->right, target);
            pathSum-=root->right->val;
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        findPath(root, targetSum);
        return result;
    }

    void showResult(){
        cout<<result;
    }
};


int main(){
    vector<int> arr={5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,1};
    int n=arr.size();
    sulotion a;
    a.hasPathSum(a.createBinaryTree(arr,0,n),22);
    a.showResult();
    return 0;
}