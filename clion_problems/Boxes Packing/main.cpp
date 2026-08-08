#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin>>n;
    int n1;
    map<ll,int> cnt;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        cin>>n1;
        cnt[n1]++;
        ans=max(cnt[n1],ans);
    }
    cout<<ans<<endl;
    return 0;
}
