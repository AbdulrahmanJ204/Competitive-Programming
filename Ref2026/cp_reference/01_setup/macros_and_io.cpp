
// ============================================================================
//                              BASIC MACROS
// ============================================================================

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define oo LLONG_MAX
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)

// Fast IO
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

// File IO
void setIO(string name = "") {
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Unique function - removes consecutive duplicates
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));

