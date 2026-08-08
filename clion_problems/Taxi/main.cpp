#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 4) {
            ans++;
            continue;
        }
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int i = 0, j = v.size() - 1;
    while (i <= j) {
        if (i == j) {
            ans++;
            break;
        }
        if (v[i] + v[j] == 4) {
            ans++;
            i++;
            j--;
        } else if (v[i] + v[j] > 4) {
            j--;
            ans++;
        } else {
            v[j] += v[i];
            i++;
        }


    }
    cout << ans;
    return 0;
}
