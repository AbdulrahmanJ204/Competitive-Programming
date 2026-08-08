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
string s[4];
bool check(int x, int y) {
    int a = 0, b = 0;
    for (int i = x; i < x + 2; i++)
        for (int j = y; j < y + 2; j++)
            if (s[i][j] == '.')
                a++;
            else
                b++;

  return a==1||b==1||a==0||b==0;

}
void solve() {
    for (int i = 0; i < 4; i++)
        cin >> s[i];

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if(check(i,j)){
          cout<<"YES";
          return;
        }
      }
      
    }
    cout<<"NO";


    return;
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