/**
 * 从先序遍历和中序遍历序列构造二叉树
*/
#include <iostream>
#include <vector>

using namespace std;

// 树的结点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> pre = {3, 9, 20, 15, 7}; // 先序序列
vector<int> in = {9, 3, 15, 20, 7}; // 中序序列

// 先序中序建树
TreeNode *buildTree(int pl, int pr, int il, int ir) {
    // pl, pr分别是先序序列的左右边界，il, ir分别是中序序列的左右边界 
    if (pl > pr) 
        return nullptr; // 递归终止条件
    int rootVal = pre[pl]; // 先序序列的第一个元素必定是根结点
    int k = il;
    while (in[k] != rootVal) // 在中序序列中找到根结点的位置
        k++;
    int leftLen = k - il; // 左子树的长度
    TreeNode *root = new TreeNode(rootVal); // 创建根结点
    root->left = buildTree(pl + 1, pl + leftLen, il, k - 1); // 递归构造左子树
    root->right = buildTree(pl + leftLen + 1, pr, k + 1, ir); // 递归构造右子树
    return root;
}

// 前序遍历
void preOrder(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode *root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    TreeNode *root = buildTree(0, pre.size() - 1, 0, in.size() - 1);
    cout << "先序遍历:";
    preOrder(root);
    cout << endl;
    cout << "中序遍历:";
    inOrder(root);
    return 0;
}