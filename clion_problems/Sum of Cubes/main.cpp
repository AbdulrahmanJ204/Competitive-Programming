#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        ll a[10000];
    for (ll i = 0; i < 10000; ++i) {
        a[i] = (i + 1) * (i + 1) * (i + 1);
    }
    test {
        ll x;
        cin >> x;
        bool exist = false;
        for (ll i = 0; i < 10000; ++i) {
            ll l = 0, r = 9999;
            while (l < r) {
                ll mid = (l + r) / 2;
                if (a[i] + a[mid] == x) {
                    exist = true;
                    break;
                }
                if (a[i] + a[mid] < x)
                    l = mid + 1;
                else
                    r = mid;
            }
            if (exist)
                break;
        }
        if (!exist)
            cno;
        else
            cyes;
    }
    return 0;
}