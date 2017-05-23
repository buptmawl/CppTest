
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <queue> 
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

void myconvert(TreeNode* node,TreeNode** plistnode)
{
    if(NULL == node)
        return ;
    TreeNode* pThisnode = node;   
    if(NULL != pThisnode->left)
       myconvert(pThisnode->left,plistnode); 

    pThisnode->left = *plistnode;
    if(NULL != *plistnode)
       (*plistnode)->right = pThisnode;
    *plistnode = pThisnode;

    if(NULL != pThisnode->right)
       myconvert(pThisnode->right,plistnode);
}

TreeNode* convert(TreeNode* node) 
{

    if(NULL == node)
        return NULL;
    TreeNode* presult = new TreeNode(-1);
    TreeNode* presult = presult;
    myconvert(node, presult);
    return *presult;
   
}

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

void display(TreeNode* node) {
    for (auto &m = node; m != NULL ; m=m->left ) {
            cout << " " << m->value;
    }
    cout << endl;
}

int main() {
    TreeNode* node = createTree();
    TreeNode *retNode = convert(node);
    display(retNode);
    return 0;
}

