#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int px, py, u = 0, d = 0, l = 0, r = 0;
        cin >> px >> py;
        cin >> s;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R') {

                r++;
            } else if (s[i] == 'L') {

                l--;
            } else if (s[i] == 'U') {

                u++;
            } else if (s[i] == 'D') {

                d--;
            }

        }

        if (px > 0) {
            if (py > 0) {
                if (r >= px && u >= py)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            } else {
                if (r >= px && d <= py)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        } else {
            if (py > 0) {
                if (l <= px && u >= py)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            } else {
                if (l <= px && d <= py)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}
