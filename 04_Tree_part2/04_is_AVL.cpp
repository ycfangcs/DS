/**
 * 判断一棵二叉树是否是平衡二叉树
*/
#include <iostream>

using namespace std;

// 树的结点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
     1
    / \
   2   3
  / \   \
 4   5   6
 构建一棵平衡二叉树
*/
TreeNode *createTree_blance()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

/*
     1
    / 
   2   
  / \   
 4   5  
 构建一棵非平衡二叉树
*/
TreeNode *createTree_not_blance() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// 判断一棵二叉树是否是平衡二叉树
bool isAVL(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int leftDepth = treeDepth(root->left); // 左子树的深度
    int rightDepth = treeDepth(root->right); // 右子树的深度
    if (abs(leftDepth - rightDepth) > 1) // 如果左右子树深度相差大于1，则不是平衡二叉树
        return false;
    return isAVL(root->left) && isAVL(root->right); // 递归判断左右子树是否是平衡二叉树
}