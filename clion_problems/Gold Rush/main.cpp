#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
ll m;
bool ok(ll n)
{
    ll first=n/3;
    ll second=n*2/3;
  //  cout<<first<<' '<<second<<endl;
    if(first+second!=n)
        return 0;
    if(first==m||second==m)
        return 1;
    return ok(first)||ok(second);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        ll n;
        cin>>n>>m;  if(n==m) {
            cyes;
            continue;
        }
        if(n<m||n*2/3<m) {
            cno;
            continue;
        }

        if(ok(n)) cyes;
        else cno;

    }
    return 0;
}