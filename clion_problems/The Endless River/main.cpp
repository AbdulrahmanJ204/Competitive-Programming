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
    ll n,d,r;
    cin>>n>>d>>r;
    ll ans;
    ll fir=0,sec=0;
    vector<pair<bool,bool>> v(n,{0,0});
        for (int i = 0; i < n; ++i) {
            fir+=r;
            fir%=n;
            sec+=d;
            sec%=n;
            v[fir].first=1;
            v[sec].second=1;
            if(v[fir].first==true&&v[fir].second==true) {
                ans = i;
                break;
            }
            else if(v[sec].first==true&&v[sec].second==true) {
                ans = i;
                break;
            }
        }
    cout<<ans+1<<endl;
    }
    return 0;
}