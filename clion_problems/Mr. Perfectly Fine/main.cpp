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
    ll n;
    cin>>n;
    ll m[n];
    string s[n];
    bool first= false,second=false;
    ll ans=0,f,s1;
    ll minutes=0;
    ll fi=10e9,se=10e9,both=10e9;
        for (int i = 0; i < n; ++i) {
            cin>>m[i];
            cin>>s[i];
            if(s[i][0]=='1'&&s[i][1]=='1') {
                both = min(both, m[i]);
                first = true;
                second = true;
            }
            else if(s[i][0]=='1') {
                fi = min(fi, m[i]);
                first = true;
            }            else if(s[i][1]=='1') {
                se = min(se, m[i]);
                second = true;
            }        }
        ans=min(both,fi+se);
        if(!first||!second)
            cout<<-1<<endl;
        else
        cout<<ans<<endl;







    }
    return 0;
}