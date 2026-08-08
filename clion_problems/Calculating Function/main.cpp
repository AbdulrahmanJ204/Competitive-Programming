#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll odd,even;
    if(n%2==0) {
        even = n * (n + 2) / 4;
        odd = n * (n + 1) / 2 - even;
    }
     else {
        even = (n - 1) * (n - 1 + 2) / 4;
        odd = n * (n + 1) / 2 - even;
    }
    cout<<even-odd<<endl;


    return 0;
}
