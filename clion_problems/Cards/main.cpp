#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    pair<int,int> a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for (int i = 0; i < n / 2; ++i) {
        cout<<a[i].second<<' '<<a[n-i-1].second<<endl;
    }


    return 0;
}
