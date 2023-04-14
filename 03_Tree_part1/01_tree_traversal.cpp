/**
 * 树的基本概念
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

// 前序遍历
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// 后序遍历
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main()
{
    TreeNode *root = createTree();
    // 前序遍历
    cout << "前序遍历: ";
    preOrder(root);
    cout << endl;
    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;
    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;
    return 0;
}