#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 100;
    cout << t << "\n";
    while (t--) {
        int n = rand() % 100 + 1;
        cout << n << "\n";

        //to generate distinct element and printing it in sorted order
        set<int> s;
        while (s.size() != n) {
            s.insert(rand() % 1000 + 1);
        }

        for (auto el : s) {
            cout << el << " ";
        }
        cout << "\n";
    }
}