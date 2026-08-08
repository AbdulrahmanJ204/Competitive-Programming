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
        int n;cin>>n;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        ll ans=0,sum=0;
        for (int i = 0; i < n; ++i) {
            sum+=abs(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            if(a[i]<0) {
                ans++;
                while (a[i] <= 0)
                {
                    i++;
                }
                i--;
            }
        }
        cout<<sum<<' '<<ans<<endl;

    }
    return 0;
}