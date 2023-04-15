/**
 * 二叉搜索树
*/
#include <iostream>

using namespace std;

// 二叉搜索树的节点
struct BSTNode {
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 二叉搜索树的插入
BSTNode *insert(BSTNode *root, int val) {
    if (root == nullptr) {
        return new BSTNode(val);
    }
    if (val < root->val) {  // 如果val小于根节点的值, 则插入到左子树
        root->left = insert(root->left, val); // 递归插入左子树
    } else if (val > root->val) { // 如果val大于根节点的值, 则插入到右子树
        root->right = insert(root->right, val); // 递归插入右子树
    }
    return root;
}

// 二叉搜索树的查找
BSTNode *search(BSTNode *root, int val) {
    if (root == nullptr) { // 二叉搜索树为空, 直接返回
        return nullptr;
    }
    if (val < root->val) { // 如果val小于根节点的值, 则查找左子树
        return search(root->left, val); // 递归查找左子树
    } else if (val > root->val) { // 如果val大于根节点的值, 则查找右子树
        return search(root->right, val); // 递归查找右子树
    } else {
        return root;
    }
}

// 二叉搜索树的删除
BSTNode *remove(BSTNode *root, int val) {
    if (root == nullptr) { // 二叉搜索树为空, 直接返回
        return nullptr;
    }
    if (val < root->val) {
        root->left = remove(root->left, val);
    } else if (val > root->val) {
        root->right = remove(root->right, val);
    } else {
        if (root->left == nullptr) { // 左子树为空
            // 删除根节点, 返回右子树
            BSTNode *right = root->right;
            delete root;
            return right;
        } else if (root->right == nullptr) { // 右子树为空
            // 删除根节点, 返回左子树
            BSTNode *left = root->left;
            delete root;
            return left;
        } else {
            // 左右子树都不为空
            BSTNode *minNode = root->right;
            while (minNode->left != nullptr) { // 找到右子树中的最小节点
                minNode = minNode->left;
            }
            root->val = minNode->val; // 将最小节点的值赋值给根节点
            root->right = remove(root->right, minNode->val); // 删除最小节点
        }
    }
    return root;
}

// 从一个数组构建二叉搜索树
BSTNode *buildBST(int *arr, int n) {
    BSTNode *root = nullptr;
    for (int i = 0; i < n; i++) {
        // 逐个插入数组中的元素
        root = insert(root, arr[i]);
    }
    return root;
}

// 中序遍历二叉搜索树
void inOrder(BSTNode *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}


int main() {
    int arr[] = {5, 3, 6, 8, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << "数组: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    BSTNode *root = buildBST(arr, n); // 从arr数组构建二叉搜索树
    cout << "已从数组构建成二叉搜索树" << endl;

    cout << "中序遍历: ";
    inOrder(root); // 中序遍历二叉搜索树
    cout << endl;

    cout << "查找元素 4:" << endl;
    BSTNode *node = search(root, 4);
    if (node != nullptr) {
        cout << "已找到" << node->val << endl;
    } else{
        cout << "未找到" << endl;
    }

    cout << "删除元素 3" << endl;
    root = remove(root, 3);

    cout << "查找元素 3:" << endl;
    node = search(root, 3);
    if (node != nullptr) {
        cout << node->val << endl;
    } else{
        cout << "未找到" << endl;
    }
    return 0;
}
