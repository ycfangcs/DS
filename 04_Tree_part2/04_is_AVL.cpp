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

/**
 * O(n^2)的算法
*/
// 求一棵二叉树的深度
int treeDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
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

/**
 * O(n)的算法
*/
bool isAVL_improved(TreeNode *root, int &depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return true;
    }
    int leftDepth, rightDepth;
    if (isAVL_improved(root->left, leftDepth) && isAVL_improved(root->right, rightDepth))
    {
        int diff = leftDepth - rightDepth;
        if (diff <= 1 && diff >= -1)
        {
            depth = 1 + max(leftDepth, rightDepth);
            return true;
        }
    }
    return false;
}



int main()
{   
    // 1. 构建一棵平衡二叉树
    TreeNode *root = createTree_blance();
    cout << "已构建一棵平衡二叉树:" << endl;
    cout << "O(n^2)算法判断结果为: " << isAVL(root) << endl; // 1
    int depth = 0;
    cout << "O(n)算法判断结果为: " << isAVL_improved(root, depth) << endl; // 1

    // 2. 构建一棵非平衡二叉树
    root = createTree_not_blance();
    cout << "已构建一棵非平衡二叉树:" << endl;
    cout << "O(n^2)算法判断结果为: " << isAVL(root) << endl; // 0
    depth = 0;
    cout << "O(n)算法判断结果为: " << isAVL_improved(root, depth) << endl; // 0
    
    return 0;
}