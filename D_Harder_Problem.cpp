  #include <bits/stdc++.h>
  using namespace std;

  #define ll long long
  #define int ll
  #define all(x) x.begin(), x.end()
  #define rall(x) x.rbegin(), x.rend()
  #define endl '\n'
  #define cendl cout << endl
  #define cyes cout << "YES"
  #define cno cout << "NO"
  #define cin(v)                        \
      for (ll i = 0; i < v.size(); i++) \
          cin >> v[i];
  #define cin1(v, n)             \
      for (ll i = 0; i < n; i++) \
          cin >> v[i];
  #define cin2(v, n, m)               \
      for (ll i = 0; i < n; i++)      \
          for (int j = 0; j < m; j++) \
              cin >> v[i][j];
  #define tryAndCry(v)      \
      for (auto x : v) {    \
          cout << x << " "; \
      }                     \
      cout << "\n";
  #define cout1(v, n)            \
      for (ll i = 0; i < n; i++) \
          cout << v[i] << ' ';   \
      cendl;
  #define cout2(v, n, m)                \
      for (ll i = 0; i < n; i++, cendl) \
          for (int j = 0; j < m; j++)   \
              cout << v[i][j] << ' ';
  #define assign1(v, n, value)   \
      for (ll i = 0; i < n; i++) \
          v[i] = value;
  #define assign2(v, n, m, value)     \
      for (ll i = 0; i < n; i++)      \
          for (int j = 0; j < m; j++) \
              v[i][j] = value;
  #define unq(v) v.resize(distance(v.begin(), unique(all(v))));
  #define oo LLONG_MAX
  #define InTheNameOfAllah          \
      ios_base::sync_with_stdio(0); \
      cin.tie(0);

  void solve() {
      ll n;
      cin >> n;
      ll a[n];
      cin1(a, n);
      map<int, int> mp;
      set<int> st;
      int b[n];
      b[0] = a[0];
      st.insert(b[0]);
      set<int> ind;
      
      for (int i = 1; i < n; i++) {
          if (st.count(a[i])) {
              ind.insert(i);
              continue;
          }
          b[i] = a[i];
          st.insert(b[i]);
      }
      int cnt = 1;
      while (cnt <= n && ind.size()) {
          if (st.count(cnt)) {
              cnt++;
              continue;
          }
          b[*ind.begin()] = cnt;
          ind.erase(ind.begin());
          st.insert(cnt);
          cnt++;
      }
      cout1(b, n);

      return;
  }

  int32_t main() {
      InTheNameOfAllah
          // freopen("input.txt", "r", stdin);
          // freopen("output.txt", "w", stdout);
          ll t = 1;
      cin >> t;
      while (t--) {
          solve();
          // cendl;
      }
      return 0;
  }