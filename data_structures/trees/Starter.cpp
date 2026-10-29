#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
        : key(value), left(nullptr), right(nullptr) {
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* Insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->key) {
            node->left = Insert(node->left, value);
        }
        else if (value > node->key) {
            node->right = Insert(node->right, value);
        }

        // Duplicate values are ignored.
        return node;
    }

    bool Contains(TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->key) {
            return true;
        }

        if (value < node->key) {
            return Contains(node->left, value);
        }

        return Contains(node->right, value);
    }

    void PrintInorder(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }

        PrintInorder(node->left);
        cout << node->key << " ";
        PrintInorder(node->right);
    }

    void PrintPreorder(TreeNode* node) const {
        // TODO:
        // 1. Handle the base case.
        // 2. Print the current node.
        // 3. Traverse the left subtree.
        // 4. Traverse the right subtree.
    }

    void PrintPostorder(TreeNode* node) const {
        // TODO:
        // 1. Handle the base case.
        // 2. Traverse the left subtree.
        // 3. Traverse the right subtree.
        // 4. Print the current node.
    }

    void Destroy(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        Destroy(node->left);
        Destroy(node->right);

        delete node;
    }

public:
    BinarySearchTree()
        : root(nullptr) {
    }

    void Insert(int value) {
        root = Insert(root, value);
    }

    bool Contains(int value) const {
        return Contains(root, value);
    }

    void PrintInorder() const {
        PrintInorder(root);
        cout << endl;
    }

    void PrintPreorder() const {
        PrintPreorder(root);
        cout << endl;
    }

    void PrintPostorder() const {
        PrintPostorder(root);
        cout << endl;
    }

    ~BinarySearchTree() {
        Destroy(root);
    }
};

int main() {
    BinarySearchTree tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    cout << "Inorder:   ";
    tree.PrintInorder();

    cout << "Preorder:  ";
    tree.PrintPreorder();

    cout << "Postorder: ";
    tree.PrintPostorder();

    cout << endl;

    cout << boolalpha;
    cout << "Contains 60: " << tree.Contains(60) << endl;
    cout << "Contains 25: " << tree.Contains(25) << endl;

    return 0;
}
