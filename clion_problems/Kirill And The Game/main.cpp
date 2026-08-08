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
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    bool exist = false;
    for (int i = x; i <= y; ++i) {
        ll a = k * i;
        if (a >= l && a <= r) {
            exist = true;
            break;
        }
    }
    if (exist) cyes;
    else
        cno;
    return 0;
}