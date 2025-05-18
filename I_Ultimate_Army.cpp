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
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
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

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    string s;
    cin >> s;
    stack<string> st;
    st.push("0");
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (!st.empty())
                st.pop();
        } else if (s[i] != '(') {
          string temp="";
          while(isdigit(s[i])){
            temp+=s[i];
            i++;
          }i--;
        //   for (int j = i; s[j]!=')'&&s[j]!='('; j++)
        //   {
        //     temp+=s[j];
        //   }
        //   i+=temp.size()-1;
        //   stringstream ss;
          int index;
        //   ss<< temp;
        //   ss>> index; 
          int value;
        //   stringstream se;
        //   se<< st.top();
        //   se>> value;
            index=stoi(temp);
            value=stoi(st.top());
            a[index] = value;
            st.push(temp);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
/* 

15
1(2(3))
(4(5))
(6(7))
(8(9))
(10(11))
(12(13))
(14(15))

 */
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