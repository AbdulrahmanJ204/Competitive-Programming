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
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1)
                a[i]++;
        }
        for (int i = 1; i < n; ++i)
            if (a[i] % a[i - 1] == 0)
                a[i]++;
        for (int j = 0; j < n; ++j)
            cout << a[j] << ' ';
        cendl;
    }
    return 0;
}