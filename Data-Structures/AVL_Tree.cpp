#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int height;

    Node() {
        height = 1;
        left = nullptr;
        right = nullptr;
    }

    Node(int val) : val(val) {
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class Tree {
private:
    int getHeight(Node* root) {
        if (root == nullptr)
            return 0;

        return root->height;
    }

    int getBalance(Node* root) {

        if (root == nullptr)
            return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return left - right;
    }

    Node* findMin(Node* root) {

        while (root->left)
            root = root->left;

        return root;

    }

public:
    Tree() {

    }

    /*
    *
    *      x                       y
    *     /  \                   /  \
    *   t1    y                 x     z
    *        / \      ->       / \   / \
    *       t2  z             t1 t2 t3 t4
    *          / \
    *         t3 t4
    */

    Node* leftRotate(Node* head) {
        Node* x = head;

        Node* y = x->right;
        Node* t2 = y->left;

        x->right = t2;
        y->left = x;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    /*
    *          x                 y
    *        /  \              /   \
    *       y    t1   ->      z      x
    *     /  \               / \     / \
    *    z   t2             t3 t4    t2 t1
    *   / \
    *  t3 t4
    */
    Node* rightRotate(Node* head) {

        // To understand from above diagram
        // Node *x = head;

        // Node *y = x->right;
        // Node *t2 = y->left;

        // x->right = t2;
        // y->left = x;

        // x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        // y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        // return y;

        // To be more clean
        Node* newHead = head->left;
        Node* rightAlready = newHead->right;

        newHead->right = head;
        head->left = rightAlready;

        head->height = max(getHeight(head->left), getHeight(head->right)) + 1;
        newHead->height = max(getHeight(newHead->left), getHeight(newHead->right)) + 1;

        return newHead;
    }

    Node* insert(Node* head, int x) {

        if (head == nullptr) {
            return new Node(x);
        }

        if (x < head->val) {
            head->left = insert(head->left, x);
        } else if (x > head->val) {
            head->right = insert(head->right, x);
        } else {
            return head;
        }

        head->height = max(getHeight(head->left), getHeight(head->right)) + 1;

        int balance = getBalance(head);

        // LL case
        if (balance > 1 && x < head->left->val) {
            // do right rotate on this node.
            return rightRotate(head);
        }

        if (balance < -1 && x > head->right->val) {
            // do left rotate on this node.
            return leftRotate(head);
        }

        if (balance > 1 && x > head->left->val) {
            // do left rotate on left node and then right rotate.
            head->left = leftRotate(head->left);
            return rightRotate(head);
        }

        if (balance < -1 && x < head->right->val) {
            // do right rotate on right node and then left rotate.
            head->right = rightRotate(head->right);
            return leftRotate(head);
        }

        return head;
    }

    Node* remove(Node* head, int x) {

        if (head == nullptr)
            return head;

        if (x < head->val) {
            head->left = remove(head->left, x);
        } else if (x > head->val) {
            head->right = remove(head->right, x);
        } else {

            // normal bst delete

            if (!head->left && !head->right) {
                Node* temp = head;
                head = nullptr;

                delete temp;
            } else if (head->left == nullptr) {

                Node* temp = head->right;
                head = temp;
                delete temp;
            } else if (head->right == nullptr) {
                Node* temp = head->left;
                head = temp;
                delete temp;
            } else {

                Node* temp = findMin(head->right);

                head->val = temp->val;

                head->right = remove(head->right, temp->val);
            }
        }

        if (head == nullptr)
            return nullptr;

        head->height = max(getHeight(head->left), getHeight(head->right)) + 1;

    }
};


void inorder(Node* head) {
    if (head == nullptr)
        return;

    inorder(head->left);
    cout << head->val << ' ';
    inorder(head->right);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    freopen("/ATOMCODES/err_output.txt", "w", stderr);
#endif

    Node* head = new Node(10);

    Tree t;

    for (int i = 0; i < 10; i++) {
        head = t.insert(head, 10 - i - 1);
    }
}