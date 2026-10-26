#include <iostream>
using namespace std;

template<typename T>
class TreeNode {
public:
    T key;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value)
        : key(value), left(nullptr), right(nullptr) {
    }
};

template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;

    TreeNode<T>* Insert(TreeNode<T>* node, T value) {
        // Empty position found
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value < node->key) {
            node->left = Insert(node->left, value);
        }
        else if (value > node->key) {
            node->right = Insert(node->right, value);
        }

        // Duplicate values are ignored
        return node;
    }

    bool Contains(TreeNode<T>* node, T value) const {
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

    void PrintInorder(TreeNode<T>* node) const {
        if (node == nullptr) {
            return;
        }

        PrintInorder(node->left);
        cout << node->key << " ";
        PrintInorder(node->right);
    }

    void Destroy(TreeNode<T>* node) {
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

    void Insert(T value) {
        root = Insert(root, value);
    }

    bool Contains(T value) const {
        return Contains(root, value);
    }

    void PrintInorder() const {
        PrintInorder(root);
        cout << endl;
    }

    ~BinarySearchTree() {
        Destroy(root);
    }
};

int main() {
    BinarySearchTree<int> tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    cout << "Inorder traversal: ";
    tree.PrintInorder();

    cout << boolalpha;
    cout << "Contains 60: " << tree.Contains(60) << endl;
    cout << "Contains 25: " << tree.Contains(25) << endl;

    return 0;
}
