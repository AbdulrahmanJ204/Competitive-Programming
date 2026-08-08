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
    cin>>n;
    ll a[n];
        for (int i = 0; i < n-1; ++i) {
            cin>>a[i];
        }
        vector<ll>v;
        for (int i = 1; i < n - 1; ++i) {
            v.push_back(a[i]-a[i-1]);
        }
        for(auto x:v)
            cout<<x<<' ';
    cendl;
    }
    return 0;
}