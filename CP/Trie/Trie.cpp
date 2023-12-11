#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second

struct Node {
    unordered_map<char, Node*> child; //make it an array if you can, it will reduce memory usage
    //Node* child[2];
    //Node* child[26];
    bool is_end; //it is set true if any string is ended at this

    Node()
    {
        is_end = false;
        // for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

class Trie {
public:
    Node* root;

    Trie()
    {
        root = new Node;
    }

    void insert(string str)
    {
        Node* cur = root;

        for (auto ch : str) {
            if (cur->child[ch] == 0) // there is no Node belonging to this character "ch"
            {
                cur->child[ch] = new Node; //so making a new Node of this character
            }

            cur = cur->child[ch]; // going down from cur to child "ch" in the Trie
        }

        cur->is_end = true; //setting is_end true to tell that some string is ended here
    }

    bool search(string str)
    {
        Node* cur = root;

        for (auto ch : str) {
            if (cur->child[ch] == 0)
                return 0;

            cur = cur->child[ch];
        }

        return cur->is_end;
    }
};

void fun()
{
    Node root;
    Node cur;
    cur.child[1] = &root;
    Trie t;
    int n;
    cin >> n;
    fi(0, n)
    {
        string s;
        cin >> s;
        t.insert(s);
    }
    int query;
    cin >> query;
    while (query--) {
        string s;
        cin >> s;
        if (t.search(s)) {
            cout << s << " is present\n";
        } else {
            cout << s << " is not present\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("/ATOM/input.txt", "r", stdin);
    //     freopen("/ATOM/output.txt", "w", stdout);
    // #endif
    int t = 1;
    cin >> t;
    while (t--) {
        fun();
    }
}