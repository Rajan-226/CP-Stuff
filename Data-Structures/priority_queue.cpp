/**
 *
 * push : push the element to some leaf, and then will adjust it's position by going up
 *
 * pop : swap the position of top with one of the leaf, and then adjust the position of swapped top element, and remove that leaf directly
 *       For simplicity, just consider last node in the array as leaf   
 *
 *
*/

#include<bits/stdc++.h>
using namespace std;

//using binary heap(complete binary tree with children greater than the parent)
class priorityQueue {
private:
    int N;
    vector<int> arr;

    //going up from the leaf node
    void swim(int child) {
        while (child > 1) { 
            int parent = child / 2;

            if (arr[parent] >= arr[child])
                break;

            swap(arr[parent], arr[child]);
            child = parent;
        }
    }

    //going down from the root node
    void sink(int parent) {
        while (2 * parent <= N) {
            int left = 2 * parent;

            //taking maximum of left and right child
            if (left < N && arr[left] < arr[left + 1])
                left++;

            //parent is already greater than any of it's child
            if (arr[parent] >= arr[left])
                break;

            swap(arr[parent], arr[left]);
            parent = left;
        }
    }

public:
    //calling parameterized constructor with size 1
    priorityQueue() :priorityQueue(1) {}

    priorityQueue(int capacity) {
        arr = vector<int>(capacity + 1);
        N = 0;
    }

    void push(int x) {
        if (N + 1 == arr.size())
            arr.resize(2 * ((int) arr.size()));

        arr[++N] = x;
        swim(N);
    }

    int pop() {
        int peek = arr[1];

        swap(arr[1], arr[N--]);
        sink(1);
        arr[N + 1] = NULL;

        return peek;
    }

    int top() {
        return arr[1];
    }

    int size() {
        return N;
    }

    bool empty() {
        return N == 0;
    }
};

int main() {
    priorityQueue q(100);
    assert(q.empty());
    q.push(5);
    assert(q.size() == 1);
    assert(q.top() == 5);
    assert(q.pop() == 5);
    assert(q.empty());
    q.push(2);
    q.push(3);
    assert(q.top() == 3);
    q.push(2);
    assert(q.pop() == 3);
    assert(q.pop() == 2);
    assert(q.pop() == 2);
    assert(q.empty());

    priority_queue<int> temp;
    for (int i = 0; i < 50; i++) {
        int x = rand() % 100;
        temp.push(x);
        q.push(x);
        assert(temp.top() == q.top());
    }

    while (!temp.empty()) {
        assert(temp.top() == q.top());
        q.pop();
        temp.pop();
    }

    assert(q.empty());

    cout << "Good Job!!\n";
    return 0;
}