#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mx_dig(string &a,int n)
{  int mx=-1;
    for (int i = 0; i < n; ++i) {
        mx=max(mx,a[i]-'0');
    }
    return mx;
}
int mn_dig(string &a,int n)
{  int mn=11;
    for (int i = 0; i < n; ++i) {
        mn=min(mn,a[i]-'0');
    }
    return mn;
}
int dif(string& a,int sa)
{
    int dif=mx_dig(a,sa)-mn_dig(a,sa);
    return dif;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        if (a.size() != b.size()) {
            for (int i = 0; i < a.size(); ++i) {
                cout << 9;
            }
            cout << endl;
            continue;
        }
        if (a == b) {
            cout << a << endl;
            continue;
        }
        int first = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                first = i;
                break;
            }
        }
        string ans=a;
          int ans_dif=dif(a,a.size());
        if (ans_dif > dif(b, b.size()))
            ans = b;

        for (int i = first + 1; i < a.size(); ++i) {
            for (int j = a[i] - '0' + 1; j < 10; ++j) {
                int curmn = min(mn_dig(a, i), j);
                int curmx = max(mx_dig(a, i), j);
                ans_dif=dif(ans,ans.size());
                if (ans_dif > curmx - curmn) {
                   ans=a;
                   ans_dif-curmx-curmn;
                    for (int k = i; k < ans.size(); ++k) {
                        ans[k] = j + '0';
                    }
                }
            }
        }
        for (int i = first + 1; i < b.size(); ++i) {
            for (int j = b[i] - '0' + 1; j < b[i] - '0'; ++j) {
                int curmn = min(mn_dig(b, i), j);
                int curmx = max(mx_dig(b, i), j);
                ans_dif=dif(ans,ans.size());
                if (ans_dif > curmx - curmn) {
                    ans=b;
                    ans_dif=curmx-curmn;
                    for (int k = i; k < ans.size(); ++k) {
                        ans[k] = j + '0';
                    }
                }
            }
        }
        for (int j = a[first] - '0' + 1; j < b[first] - '0'; ++j) {
            int curmn = min(mn_dig(b, first), j);
            int curmx = max(mx_dig(b, first), j);
            if (dif(ans, ans.size()) > curmx - curmn) {
                ans=a;
                for (int k = first; k < ans.size(); ++k) {
                    ans[k] = j + '0';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mod = 998244353;
const int inf = 2e18;

struct my_hash {
    size_t operator()(const pair<int, int>& a) const {
        return a.first * 11 + a.second;
    }
};

int mx_dig(string& a, int len) {
    int mx = -1;
    for (int i = 0; i < len; i++) {
        mx = max(mx, int(a[i] - '0'));
    }
    return mx;
}

int mn_dig(string& a, int len) {
    int mn = 10;
    for (int i = 0; i < len; i++) {
        mn = min(mn, int(a[i] - '0'));
    }
    return mn;}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int l, r;
        cin >> l >> r;
        string a = to_string(l);
        string b = to_string(r);
        if (a.size() != b.size()) {
            for (int i = 0; i < a.size(); i++) {
                cout << '9';
            }
            cout << '\n';
            continue;
        }
        int n = a.size();
        int first_dif = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                first_dif = i;
                break;
            }
        }
        if (first_dif == -1) {
            cout << a << '\n';
            continue;
        }
        int ans_dif = mx_dig(a, n) - mn_dig(a, n);
        string ans = a;
        if (ans_dif > mx_dig(b, n) - mn_dig(b, n)) {
            ans_dif = mx_dig(b, n) - mn_dig(b, n);
            ans = b;
        }
        for (int i = first_dif + 1; i < n; i++) {
            for (int d = a[i] - '0' + 1; d < 10; d++) {
                int cur_mn = min(mn_dig(a, i), d);
                int cur_mx = max(mx_dig(a, i), d);
                if (ans_dif > cur_mx - cur_mn) {
                    ans_dif = cur_mx - cur_mn;
                    ans = a;
                    for (int j = i; j < n; j++) {
                        ans[j] = d + '0';
                    }
                }
            }
        }
        for (int i = first_dif + 1; i < n; i++) {
            for (int d = 0; d < b[i] - '0'; d++) {
                int cur_mn = min(mn_dig(b, i), d);
                int cur_mx = max(mx_dig(b, i), d);
                if (ans_dif > cur_mx - cur_mn) {
                    ans_dif = cur_mx - cur_mn;
                    ans = b;
                    for (int j = i; j < n; j++) {
                        ans[j] = d + '0';
                    }
                }
            }
        }
        for (int d = a[first_dif] - '0' + 1; d < b[first_dif] - '0'; d++) {
            int cur_mn = min(mn_dig(a, first_dif), d);
            int cur_mx = max(mx_dig(a, first_dif), d);
            if (ans_dif > cur_mx - cur_mn) {
                ans_dif = cur_mx - cur_mn;
                ans = a;
                for (int j = first_dif; j < n; j++) {
                    ans[j] = d + '0';
                }
            }
        }
        cout << ans << '\n';
    }
}*/