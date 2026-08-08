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
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    int sum = 0, mx = 0;
    for (auto x : m) {
        mx=max(mx,x.second);
    }
    /* 
    considering we have 2 elements , one repeated more than the other we rearrange the array:     
    mx - other - mx - other - mx - other .....
    
    difference should be 1 or less (note to future me :  if dif is -ve it works , use ur mind to know why , idk how to explain it)
    edit : sum is n :)
    dif is mx - ( sum - mx ) -> mx -sum + mx -> 2mx-sum.


    another solution is if one element is repeated more than the half size of array , 
    size= n/2 + n%2;
    if x.second > size cno; return;
    cyes;
     */
    if(2*mx-n<=1) cout<<"YES";
    else cout<<"NO";

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