    #include <bits/stdc++.h>
    using namespace std;
    #define test  int t;cin>>t;while(t--)
    #define ll long long
    #define endl '\n'
    #define cendl cout<<endl
    #define cyes cout<<"YES"<<endl
    #define cno cout<<"NO"<<endl
    vector<ll> v;
    vector<ll> super;
    void lucky(ll a) {
        if (a > 1e9) {
            v.push_back(a);
            return;
        }
        v.push_back(a);
        lucky(a * 10 + 4);
        lucky(a * 10 + 7);
    }
    void SuperLucky() {
        for (int i = 0; i < v.size(); ++i) {
            string s = to_string(v[i]);
            int four = 0, seven = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == '4')
                    four++;
                else seven++;
            }
            if (four == seven)
                super.push_back(v[i]);
        }

    }
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ll n;
        cin >> n;
        lucky(0);
        sort(v.begin(), v.end());
        SuperLucky();
        cout << *lower_bound(super.begin(), super.end(), n);
        return 0;
    }