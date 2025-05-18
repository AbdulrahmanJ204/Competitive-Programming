#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll n;
    cin>>n;
    if (n==1){
      cout<<1;
    }
    else if(n%2==1) 
    cout<<-1;
    else {
      cout<<n<<' '<<n-1<<' ';
      bool reversed=false;
      for (int i = 2; i < n-1; i+=2)
      {
        // if(reversed)
        // cout<<n-i-1<<' '<<i<<' ';
        // else 
        cout<<i<<' '<<n-1-i<<' ';

        // reversed=!reversed;
      }
    }
  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}