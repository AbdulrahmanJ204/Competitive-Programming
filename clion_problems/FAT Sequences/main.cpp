#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {
    int n;
    cin>>n;
    ll even,odd;
    ll md=1e9+7;
    ll ans=0;
        for (int i = n; i >=0 ; i-=2) {
            ans+=i;
            ans%=md;
        }
        cout<<ans<<endl;

    }

    return 0;
}

