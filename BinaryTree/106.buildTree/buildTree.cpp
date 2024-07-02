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
public:
    sulotion(){
        cout<<"start"<<endl;
    }

    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
            if (postorder.size() == 0) return NULL;

            // 后序遍历数组最后一个元素，就是当前的中间节点
            int rootValue = postorder[postorder.size() - 1];
            TreeNode* root = new TreeNode(rootValue);

            // 叶子节点
            if (postorder.size() == 1) return root;

            // 找到中序遍历的切割点
            int delimiterIndex;
            for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
                if (inorder[delimiterIndex] == rootValue) break;
            }

            // 切割中序数组
            // 左闭右开区间：[0, delimiterIndex)
            vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
            // [delimiterIndex + 1, end)
            vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

            // postorder 舍弃末尾元素
            postorder.resize(postorder.size() - 1);

            // 切割后序数组
            // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
            // [0, leftInorder.size)
            vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
            // [leftInorder.size(), end)
            vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

            root->left = traversal(leftInorder, leftPostorder);
            root->right = traversal(rightInorder, rightPostorder);

            return root;
        }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }

    void inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }
};


int main(){
    vector<int> inorder ={9,3,15,20,7};
    vector<int> postorder  ={9,15,7,20,3};
    sulotion bulidT;
    bulidT.inorderTraversal(bulidT.buildTree(inorder,postorder));
    return 0;
}