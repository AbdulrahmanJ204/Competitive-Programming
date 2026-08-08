#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
ll fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = result * base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    ll len=n;
    ll pwr=0;
    while(len>0){
        ll temp=len-len/2;
        len/=2;
        if(k<=temp){
            cout<<fastPower(2,pwr)*(2*k-1);
            return;
        }
        k-=temp;
        pwr++;

    }

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
