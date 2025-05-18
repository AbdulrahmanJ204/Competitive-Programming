#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES"
#define cno cout << "NO"
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int MX = 101;
vector<pair<int, int>> v[MX];
void solve() {
    int n;
    cin >> n;
    cout << v[n].size() << endl;
    for (auto x : v[n])
        cout << x.first << ' ' << x.second << endl;
    return;
}

int main() {
    InTheNameOfAllah 
    for (int i = 1; i <= 9999; i++)
        v[1].push_back({i + 1, i});

    for (int n = 2; n <= 100; n++)
        for (int a = 1; a <= 10000; a++) {
            int number = n * a;
            string s = to_string(number); 
            
            string stringNumber = ""; // a*n - b  :  n repeated 'a' times , size decreased by b
            string ns = to_string(n); // n as a string
            for (int i = 0, j = 0; i < s.size(); i++, j++) 
                j %= ns.size(), stringNumber += ns[j]; // creating string

            int b = number - stoi(stringNumber); // get b from string :  n*a -b= stringNumber -> b= n*a - stringNumber
            if (ns.size() * a - b == stringNumber.size() && b != 0) 
                v[n].push_back({a, b});
        }
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}