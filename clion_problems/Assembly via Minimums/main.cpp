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
        int n;
        cin >> n;
        ll N = n * (n - 1) / 2;
        ll b[N];
        map<ll, ll> m;
        for (int i = 0; i < N; ++i) {
            cin >> b[i];
            m[b[i]]++;
        }
        sort(b, b + N);
        ll mx = 0;
        int c = n - 1;
        for (auto x:m) {
            cout << x.first << ' ';
            x.second -= c;
            c--;
            mx = max(mx, x.first);
            while (x.second > 0) {

                cout << x.first << ' ';
                x.second -= c;
                c--;
            }
        }


        cout << mx << ' ';


        cendl;
    }
    return 0;
}