#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);


int main() {
    InTheNameOfAllah
    test {
        ll n, c1;
        cin >> n >> c1;
        ll s[n];
        ll h2 = 0, h = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            h2 += (s[i] * s[i]);
            h += s[i];
        }
        long double a = 4 * n;
        long double b = 4 * h;
        long double c = h2 - c1;
        long double d = sqrt(b * b - 4 * a * c);
        ll w = (d - b) / (2 * a);
        cout << (ll) round(w) << endl;

    }
    return 0;
}