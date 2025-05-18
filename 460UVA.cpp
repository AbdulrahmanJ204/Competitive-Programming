#include <bits/stdc++.h>
using namespace std;

int main() {
    // InTheNameOfAllah
    int t = 1;
    cin >> t;
    while (t--) {
        int xl1, yl1, xr1, yr1,
            xl2, yl2, xr2, yr2;
        cin >> xl1 >> yl1 >> xr1 >> yr1;
        cin >> xl2 >> yl2 >> xr2 >> yr2;
        if (i > 0)
            cout << "\n";
        if (xl1 >= xr2 || xl2 >= xr1 || yl1 >= yr2 || yl2 >= yr1) {
            cout << "No Overlap\n";
        } else {
            vector<int> x({xl1, xr1, xl2, xr2}), y({yl1, yr1, yl2, yr2});
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            cout << x[1] << ' ' << y[1] << ' ' << x[2] << ' ' << y[2] << endl;
        }
    }
    return 0;
}