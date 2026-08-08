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
    test {
    int n;
    cin>>n;
    int a[n+1];
    int gc=0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            gc=__gcd(gc,abs(a[i]-i));
        }
        cout<<gc<<endl;

    }
    return 0;
}