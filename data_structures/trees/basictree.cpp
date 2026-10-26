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

int main() {
    TreeNode<int>* root = new TreeNode<int>(50);

    root->left = new TreeNode<int>(30);
    root->right = new TreeNode<int>(70);

    root->left->left = new TreeNode<int>(20);
    root->left->right = new TreeNode<int>(40);

    root->right->left = new TreeNode<int>(60);
    root->right->right = new TreeNode<int>(80);

    cout << "Root: " << root->key << endl;
    cout << "Left child: " << root->left->key << endl;
    cout << "Right child: " << root->right->key << endl;

    return 0;
}
