  #include <bits/stdc++.h>
  #define ll long long
  using namespace std;
  const int A = 2e2;
  int n, m;
  int p[A];
  set<int> v[A];
  pair<int, pair<int, int>> check(ll len) {
      ll ans = 1e9, cnt = 0, sum = 0, first = -1, last = -1;
      map<int, int> mp;
      for (int i = 0; i < len; i++) {
          sum += p[i];
          set<int>::iterator it = v[i].begin();
          while (it != v[i].end()) {
              int x = (int)(*it);
              if (mp[x] != 0)
                  cnt++;
              mp[x]++;
              it++;
          }
      }
      if (cnt == m) {
          ans = sum;
          first = 0;
          last = len - 1;
      }
      ll l = 0, r = len;
      while (r < n) {
          sum -= p[l];
          sum += p[r];
          set<int>::iterator it1 = v[l].begin();
          set<int>::iterator it2 = v[r].begin();

          while (it1 != v[l].end()) {
              int x = (int)(*it1);
              mp[x]--;
              if (!mp[x])
                  cnt--;
              it1++;
          }

          while (it2 != v[r].end()) {
              int x = (int)(*it2);
              if (!mp[x])
                  cnt++;
              mp[x]++;
              it2++;
          }

          if (cnt == m) {
              if (sum <= ans) {
                  ans = sum;
                  first = l + 1;
                  last = r;
              }
          }
          l++;
          r++;
      }
      return make_pair(ans, make_pair(first, last));
  }
  int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t = 1;
      // cin>>t;
      while (t--) {

          cin >> n >> m;
          set<int> total;
          for (int i = 0; i < n; i++) {
              int k;
              cin >> k;
              cin >> p[i];
              v[i].clear();
              while (k--) {
                  int f;
                  cin >> f;
                  v[i].insert(f);
                  total.insert(f);
              }
          }
          if (total.size() != m) {
              cout << -1;
              continue;
          }

          ll l = 0, r = n , ans = 1e9;
          pair<int, int> z;
          while (l <= r) {
              ll mid = (l + r) / 2;
              pair<int, pair<int, int>> x = check(mid);
              if (x.first <= ans) {
                  ans = x.first;
                  z = x.second;
                  r = mid - 1;
              } else
                  l = mid + 1;
          }
          cout << ans << '\n';
          cout << z.first << ' ' << z.second << '\n';
      }

      return 0;
  }
