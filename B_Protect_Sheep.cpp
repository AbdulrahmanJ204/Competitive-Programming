#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
int n, m;
string s[510];
bool valid(int i,int j) {
    return s[i - 1][j] != 'W' && s[i][j - 1] != 'W' && s[i + 1][j] != 'W' && s[i][j + 1] != 'W';
}
void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    for (int i = 0; i < m + 1; i++) {
        s[0] += "#";
        s[n + 1] += "#";
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (s[i][j] == 'S' && !valid(i, j)) {
                cout << "NO";
                return;
            } else if (s[i][j] == 'S') {
             if(s[i - 1][j]!='S')   s[i - 1][j] = 'D';
             if(s[i][j - 1]!='S')   s[i][j - 1] = 'D';
             if(s[i + 1][j]!='S')   s[i + 1][j] = 'D';
             if(s[i][j + 1]!='S')   s[i][j + 1] = 'D';
            }
        }
    }

  cout<<"YES\n";
 for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
          cout<<s[i][j];
        }cendl;}

}


int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}