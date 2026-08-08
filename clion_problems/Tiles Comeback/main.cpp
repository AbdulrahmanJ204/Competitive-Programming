#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
bool solve() {
    int n, k;
    cin >> n >> k;
    int c[n];
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    if (c[n - 1] == c[0]) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (c[i] == c[0])
                cnt++;
        }
        return cnt >= k;
    } else {
        int cntl = 0, cntr = 0;
        int lastr_index, lastl_index;
        for (int i = 0; i < n; ++i) {
            if (c[i] == c[0])
                cntl++;
            if (cntl == k) {
                lastl_index = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (c[i] == c[n - 1])
                cntr++;
            if (cntr == k) {
                lastr_index = i;
                break;
            }
        }
        return cntr >= k && cntl >= k && lastr_index > lastl_index;
    }


}

int main() {
    InTheNameOfAllah
    test {
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}