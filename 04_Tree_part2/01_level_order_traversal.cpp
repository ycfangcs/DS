/**
 * 层序遍历
*/
#include <iostream>
#include <queue>

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

// 层序遍历
void levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 用队列来实现层序遍历
    queue<TreeNode *> q;
    q.push(root); // 根结点入队
    while (!q.empty()) // 队列不为空
    {
        TreeNode *node = q.front();
        q.pop(); // 队首结点出队

        cout << node->val << " "; // 访问队首结点

        // 如果队首结点的左孩子不为空，将其入队
        if (node->left != nullptr)
            q.push(node->left);
        // 如果队首结点的右孩子不为空，将其入队
        if (node->right != nullptr)
            q.push(node->right);
    }
}

int main()
{
    TreeNode *root = createTree();
    // 层序遍历
    cout << "层序遍历: ";
    levelOrder(root);
    return 0;
}