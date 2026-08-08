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

void solve() {
    ll n;
    cin >> n;
    int a[n];
    map<int,vector<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    vector<int> v1, v2;
    bool turn = true;
    int x = 0, y = 0;
    
    for (int i = 0; i < n; i++) {
        if (x == a[i]) {
            v2.push_back(a[i]);
            y = a[i];
        } else if (y == a[i]) {
            v1.push_back(a[i]);
            x = a[i];
        } else {
            int i1,i2;
            i1=lower_bound(m[x].begin(),m[x].end(),i)-m[x].begin();
            i2=lower_bound(m[y].begin(),m[y].end(),i)-m[y].begin();
            if(i1<m[x].size()&&i2<m[y].size()){
                if(m[x][i1]<m[y][i2]){
                    v1.push_back(a[i]);
                    x=a[i];
                }
                else {
                    v2.push_back(a[i]);
                    y=a[i];
                }
            }
            else if(i1<m[x].size()){
                v1.push_back(a[i]);
                x=a[i];
            }
            else {
                v2.push_back(a[i]);
                y=a[i];
            }

            
        }
    }
    
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}