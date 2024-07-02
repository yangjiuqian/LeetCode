#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if(root==NULL){
        return nullptr;
    }
    vector<vector<int>> result;
    queue<Node*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        // TreeNode* cur=nodeQueue.front();
        while(size--){
            Node* cur=nodeQueue.front();
            if(size==0){
                cur->next=nullptr;
                if(cur->left)nodeQueue.push(cur->left);
                if(cur->right)nodeQueue.push(cur->right);
                nodeQueue.pop();
            }
            else{
                if(cur->left)nodeQueue.push(cur->left);
                if(cur->right)nodeQueue.push(cur->right);
                nodeQueue.pop();
                cur->next=nodeQueue.front();
            }
        }
    }
    return root;
}

int main(){
    Node*a=new Node(1);
    a->left=new Node(2);
    a->right=new Node(3);
    a->left->left=new Node(4);
    a->left->right=new Node(5);
    a->right->left=new Node(6);
    a->right->right=new Node(7);
    connect(a);
    return 0;
}