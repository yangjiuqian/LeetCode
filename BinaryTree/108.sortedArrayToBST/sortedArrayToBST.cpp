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


class sulotion{
private:

    int _depth;
    TreeNode* _root=NULL;
public:
    sulotion(){
        cout<<"start constructMaximumBinaryTree and print it"<<endl;
    }
    ~sulotion(){

    }

    TreeNode* traversal(vector<int>& nums){
        int mid=0;
        TreeNode* node = new TreeNode();
        if(nums.size()==0)return NULL;
        if(nums.size()==1){
            node->val=nums[0];
            return node;
        }
        else{
            mid = nums.size()/2;
            node->val=nums[mid];
        }
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        node->left = traversal(left);
        node->right = traversal(right);
        return node;
    }

    TreeNode* createBinaryTree(const vector<int>& arr) {
        if (arr.empty() || arr[0] == INT_MAX) return nullptr;

        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (arr[i] != INT_MAX) {
                node->left = new TreeNode(arr[i]);
                q.push(node->left);
            }
            ++i;

            if (i < arr.size() && arr[i] != INT_MAX) {
                node->right = new TreeNode(arr[i]);
                q.push(node->right);
            }
            ++i;
        }

        return root;
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        _depth = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return _depth;
    }

    void drawBinaryTree(TreeNode* root, int depth) {
        if (!root) return;
        
        drawBinaryTree(root->right, depth + 1); // 打印右子树

        // 控制节点的缩进
        cout << string(depth * 4, ' ') << root->val << endl;

        drawBinaryTree(root->left, depth + 1); // 打印左子树
    }

    void showDepth(){
        cout<<"Depth of this tree:  "<<maxDepth(_root)<<endl;
    }

    void showTree(TreeNode* root){
        if(root==NULL){
            cout<<"Waring: Draw befor construction!"<<endl;
            return;
        }
        maxDepth(root);
        drawBinaryTree(root,_depth);
    }
};


int main(){
    vector<int> arr={-10,-3,0,5,9};
    sulotion fuck;
    TreeNode* a = fuck.createBinaryTree(arr);
    cout<<"Be like:"<<endl;
    fuck.showTree(a);
    //processing
    TreeNode* b = fuck.traversal(arr);
    cout<<"After processing be like:"<<endl;
    fuck.showTree(b);
    return 0;
}