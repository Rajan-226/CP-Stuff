#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        left = right = NULL;
        data = value;
    }
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(int x, TreeNode* root) {
        if (!root)
            return new TreeNode(x);

        if (x > root->data) {
            root->right = insert(x, root->right);
        } else {
            root->left = insert(x, root->left);
        }

        return root;
    }

    bool search(int x, TreeNode* root) {
        if (!root)
            return 0;
        if (x == root->data)
            return 1;
        if (x > root->data)
            return search(x, root->right);
        return search(x, root->left);
    }

    TreeNode* min(TreeNode* root) {
        if (!root)
            return NULL;

        while (root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* remove(int x, TreeNode* root) {
        if (!root)
            return NULL;

        if (root->data == x) {
            if (!root->left && !root->right)
                return NULL;
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            TreeNode* smallest = min(root->right);
            root->data = smallest->data;
            root->right = remove(x, root->right);

            return root;
        }

        if (x > root->data) {
            root->right = remove(x, root);
        } else {
            root->left = remove(x, root);
        }

        return root;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);
    }

    bool search(int x) {
        return search(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

};

int main() {

}