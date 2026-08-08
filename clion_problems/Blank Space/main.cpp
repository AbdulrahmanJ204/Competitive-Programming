#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
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
        int a[n]; int c=0,ans=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(a[i]==0) {
                c++;
                ans = max(c, ans);
            }
            else c=0;
        }


        cout<<ans<<endl;
    }
    return 0;
}