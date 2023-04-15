/**
 * AVL树（平衡二叉树）
*/
#include <iostream>

using namespace std;

// AVL树的节点
struct AVLNode {
    int val;
    int height; // 记录节点的高度
    AVLNode *left;
    AVLNode *right;
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

// 获取节点的高度
int getHeight(AVLNode *node) {
    // 空节点的高度为0
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// 计算节点的平衡因子
int getBalanceFactor(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// 右旋转
AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T3 = x->right;
    // 右旋转
    x->right = y;
    y->left = T3;
    // 更新节点的高度
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    // 返回新的根节点
    return x;
}

// 左旋转
AVLNode *leftRotate(AVLNode *y) {
    AVLNode *x = y->right;
    AVLNode *T2 = x->left;
    // 左旋转
    x->left = y;
    y->right = T2;
    // 更新节点的高度
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    // 返回新的根节点
    return x;
}

// AVL树的插入
AVLNode *insert(AVLNode *root, int val) {
    if (root == nullptr) {
        return new AVLNode(val);
    }
    if (val < root->val) { // 如果val小于根节点的值, 则插入到左子树
        root->left = insert(root->left, val); // 递归插入左子树
    } else if (val > root->val) { // 如果val大于根节点的值, 则插入到右子树
        root->right = insert(root->right, val); // 递归插入右子树
    }
    // 更新节点的高度
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    // 计算平衡因子
    int balanceFactor = getBalanceFactor(root);
    // 平衡维护
    // LL
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }
    // RR
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }
    // LR
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// AVL树的删除
AVLNode *remove(AVLNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (val < root->val) { // 如果val小于根节点的值, 则删除左子树中的val
        root->left = remove(root->left, val);
    } else if (val > root->val) { // 如果val大于根节点的值, 则删除右子树中的val
        root->right = remove(root->right, val);
    } else { // val == root->val
        if (root->left == nullptr && root->right == nullptr) { // 如果左右子树都为空, 则直接删除
            delete root;
            root = nullptr;
        } else if (root->left != nullptr && root->right != nullptr) { // 如果左右子树都不为空, 则找到右子树中的最小节点, 用它替换当前节点
            AVLNode *minNode = root->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            root->val = minNode->val;
            root->right = remove(root->right, minNode->val);
        } else { // 如果左右子树只有一个不为空, 则用不为空的子树替换当前节点
            AVLNode *child = root->left != nullptr ? root->left : root->right;
            AVLNode *temp = root;
            root = child;
            delete temp;
        }
    }
    if (root == nullptr) {
        return nullptr;
    }
    // 更新节点的高度
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    // 计算平衡因子
    int balanceFactor = getBalanceFactor(root);
    // 平衡维护
    // LL
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }
    // RR
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }
    // LR
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// AVL树的查找
AVLNode *search(AVLNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (val == root->val) {
        return root;
    } else if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// AVL树的中序遍历
void inOrder(AVLNode *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// 从一个数组构建二叉搜索树
AVLNode *createAVLTree(int *arr, int n) {
    AVLNode *root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

int main() {
    int arr[] = {6, 4, 7, 3, 5, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << "数组:";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    AVLNode *root = createAVLTree(arr, n);
    cout << "已从数组构建AVL树" << endl;

    cout << "树高:" << getHeight(root) << endl; // 3

    cout << "中序遍历:"; // 3 4 5 6 7 8
    inOrder(root);
    cout << endl;

    cout << "删除节点6" << endl;
    root = remove(root, 6); // 删除节点6

    cout << "中序遍历:"; // 3 4 5 7 8
    inOrder(root);
    cout << endl;

    cout << "树高:" << getHeight(root) << endl; // 3
    return 0;
}