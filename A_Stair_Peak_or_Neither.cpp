#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        a < b ? b<c ? cout << "STAIR\n" : b> c ? cout << "PEAK\n" : cout << "NONE\n" : cout << "NONE\n";
    }
}