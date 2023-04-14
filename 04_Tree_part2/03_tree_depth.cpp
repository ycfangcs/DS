/**
 * 求树的深度
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
 构建一棵上图所示的树
*/
TreeNode *createTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

// 求树的深度
int treeDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = treeDepth(root->left); // 左子树的深度
    int rightDepth = treeDepth(root->right); // 右子树的深度
    return max(leftDepth, rightDepth) + 1; // 树的深度等于左右子树深度的最大值加1
}

int main()
{
    TreeNode *root = createTree();
    cout << treeDepth(root) << endl;
    return 0;
}