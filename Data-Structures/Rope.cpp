#include <bits/stdc++.h>
using namespace std;

struct RopeNode {
    RopeNode *left, *right;
    string curr;
    int lCount;

    RopeNode() {
        curr = "";
        left = right = nullptr;
        lCount = 0;
    }
};

class Rope {
    int leafLength;

public:
    RopeNode *head;

    Rope(string str, int leafLength) {
        this->leafLength = leafLength;
        head = init(str, 0, str.length() - 1);
    }

    RopeNode *init(string &str, int left, int right) {

        RopeNode *node = new RopeNode();

        if (right - left + 1 > leafLength) {
            int mid = left + (right - left) / 2;
            node->lCount = (mid - left + 1);
            node->left = init(str, left, mid);
            node->right = init(str, mid + 1, right);
        } else {

            node->lCount = (right - left + 1);
            node->curr = str.substr(left, (right - left + 1));
        }

        return node;
    }

    RopeNode *concat(Rope *a, Rope *b, int size) {
        RopeNode *newHead = new RopeNode();
        newHead->left = a->head;
        newHead->right = b->head;
        newHead->lCount = size;

        head = newHead;
    }

    char find_char_at_index(int index, RopeNode *node) {

        if (!node->left && !node->right) {
            if (index > node->lCount) {
                return '$';
            }

            return node->curr[index];
        }

        if (index > node->lCount) {
            return find_char_at_index(index - node->lCount, node->right);
        } else {
            return find_char_at_index(index, node->left);
        }
    }

    void printString(RopeNode *node) {
        if (node == nullptr)
            return;

        printString(node->left);
        if (!node->left && !node->right) {
            cout << node->curr;
        }
        printString(node->right);
    }
};

int main() {
    Rope r("Manuj Grover", 3);

    r.printString(r.head);
    cout << '\n';
    cout << r.find_char_at_index(22, r.head);
}