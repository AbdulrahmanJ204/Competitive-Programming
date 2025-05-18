#include <bits/stdc++.h>
using namespace std;

int main() {
    //     InTheNameOfAllah
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int mod, step;

    while (cin >> step >> mod) {
        int a[mod];
        for (int i = 0; i < mod; i++) {
            a[i] = -1;
        }
        int i = step;
        while (true) {
            i %= mod;
            if (a[i] != -1)
                break;
            a[i] = i;
            i += step;
        }
        bool ok = true;
        for (int i = 0; i < mod; i++) {
            if (a[i] == -1)
                ok = false;
        }
        cout << setw(10) << step << setw(10) << mod << "    ";

        ok ? cout << "Good Choice\n\n" : cout << "Bad Choice\n\n";
    }
    return 0;
}