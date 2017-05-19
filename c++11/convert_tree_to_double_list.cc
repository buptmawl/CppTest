
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
#include <stdio.h>
#include <map> 
#include <stack> 
#include <set> 
using namespace std;

// on mac: clang++ -std=c++11 -stdlib=libc++ xxx.cc && ./a.out

struct TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;
        int value;
    public:
        TreeNode( int val, TreeNode* l=NULL, TreeNode* r=NULL){
            left=l;
            right=r;
            value=val;
        }
};

TreeNode* createTree() {

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, node7);
    TreeNode* node1 = new TreeNode(1, node2, node3);

    return node1;
}

TreeNode* convert(TreeNode* node) {
    /*
    if (node == NULL) return NULL;
    if (node->left) {
        convert(node->left);
    }
    cout << " " << node->value;
    if (node->right) {
        convert(node->right);
    }
    return NULL;
    */

    TreeNode *headNode = NULL;
    TreeNode *prevHeadNode = NULL;
    TreeNode *nowHeadNode = NULL;
    set<int> visited;
    TreeNode *tmp;
    std::stack<TreeNode*>tmp_stack;
    tmp_stack.push(node);

    int count = 0;
    while(!tmp_stack.empty()) {
       tmp = tmp_stack.top();
       int top_val = tmp->value;
       if (tmp->left != NULL && visited.find(tmp->left->value) == visited.end() ) {
               tmp_stack.push(tmp->left);
               continue;
       }
       visited.insert(top_val);
       tmp_stack.pop();

       if (headNode == NULL ) {
               headNode = tmp;
       } else {
               prevHeadNode->right = tmp;;
       }
       tmp->left = prevHeadNode;
       prevHeadNode = tmp;
       //cout << " val:" << top_val;

       if (tmp->right != NULL&& visited.find(tmp->right->value) == visited.end()) {
               tmp_stack.push(tmp->right);
       }
    }
    return headNode;
}

void display(TreeNode* node) {
    for (auto &m = node; m != NULL ; m=m->right ) {
            cout << " " << m->value;
    }
    cout << endl;
}

int main() {
    TreeNode* node = createTree();
    TreeNode *retNode = convert(node);
    display(retNode);
    //display(node);


    return 0;
}

