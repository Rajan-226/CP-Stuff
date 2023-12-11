#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second

int fastexp(int a, int n, int nod = LLONG_MAX)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
#define mxsize (int)3e5
int mat[1000][1000];
void fun()
{
    srand(time(0));
    int T = 10;
    int N = 1000;
    int limitM = 1e9;
    int countOfOnes = N / 3;

    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(1, limitM);

    cout << T << "\n";
    fk(0, T)
    {
        cout << N << "\n";
        int d = rand() % N;
        for (int i = 0; i < N; i++)
        {
            if (i == d)
                cout << "1";
            else if (!countOfOnes)
                cout << "0";
            else
            {
                int k = rand() % 2;
                cout << k;
                if (k)
                    countOfOnes--;
            }

            if (i != N - 1)
                cout << " ";
        }
        cout << "\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    mat[i][i] = 0;
                else if (i < j)
                    mat[j][i] = mat[i][j] = dis(gen);

                cout << mat[i][j];
                if (j != N - 1)
                    cout << " ";
            }
            cout << "\n";
        }
    }
}
/*

*/
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("/ATOM/HackerEarth Problems/Nodes coloring/input.txt", "w", stdout);

    fun();
}