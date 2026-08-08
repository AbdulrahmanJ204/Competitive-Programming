#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {

    int t;
    cin>>t;
    int ans=0;
    int a,b;
   int cap=0;
    for (int i = 0; i < t; ++i) {
        cin>>a>>b;
        cap=cap-a+b;
        ans=max(ans,cap);
    }
    cout<<ans;

    return 0;
}
