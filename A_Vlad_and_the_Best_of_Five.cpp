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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
   char ans;
   int a=0,b=0;
   for (int i = 0; i < n; i++)
   {
    if(s[i]=='A') a++;
    else b++;
   }
   if(a>=b) cout<<"A";
   else cout<<"B";


    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}