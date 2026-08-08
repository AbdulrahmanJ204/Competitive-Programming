#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        string s;
        cin >> s;
        string c = "codeforces";
        int ans = 0;
        for (int i = 0; i < c.size(); ++i) {
            if (s[i] != c[i])
                ans++;
        }
        cout << ans << endl;
    }return 0;
}