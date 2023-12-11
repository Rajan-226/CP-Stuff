#include <bits/stdc++.h>
using namespace std;

string longestPal(int n, string s1, int m, string s2)
{
    vector<int> f1(26), f2(26);
    for (auto c : s1)
        f1[c - 'a']++;
    for (auto c : s2)
        f2[c - 'a']++;

    string ans = "";
    int first = -1, final = -1;
    for (int i = 0; i < 26; i++)
    {
        ans += string(f1[i] / 2 + f2[i] / 2, char(i + 'a'));

        f1[i] %= 2;
        f2[i] %= 2;

        if (final == -1)
        {
            if (f1[i] && f2[i])
            {
                ans.push_back(char(i + 'a'));
                final = 0;
            }
            else if (first == -1 && (f1[i] || f2[i]))
                first = i;
        }
    }
    string temp = ans;
    reverse(temp.begin(), temp.end());

    if (final == -1 && first != -1)
        ans += char(first + 'a');

    ans += temp;

    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Longest Palindromic String/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Longest Palindromic String/output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    assert(1 <= T && T <= 100);
    int sn = 0, sm = 0;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        sn += N;
        assert(1 <= N && N <= (int)1e5);
        string s1;
        cin >> s1;
        for (auto c : s1)
            assert('a' <= c && c <= 'z');
        int M;
        cin >> M; 
        sm += M;
        assert(1 <= M && M <= (int)1e5);
        string s2;
        cin >> s2;
        for (auto c : s2)
            assert('a' <= c && c <= 'z');

        string out_;
        out_ = longestPal(N, s1, M, s2);
        cout << out_;
        cout << "\n";
    }
    assert(1 <= sn && sn <= (int)1e6);
    assert(1 <= sm && sm <= (int)1e6);
}