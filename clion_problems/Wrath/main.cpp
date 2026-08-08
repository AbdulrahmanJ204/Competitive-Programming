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
    int n;
    cin >> n;
    int a[n];
    int b[n], mn[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = i - a[i] + 1;
        mn[i] = 2e9;
    }
    mn[n] = 2e9;
    for (int i = n - 2; i >= 0; --i)
        mn[i] = min(b[i + 1], mn[i + 1]);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (mn[i] > i + 1)
            ans++;

    cout << ans << endl;


    return 0;
}