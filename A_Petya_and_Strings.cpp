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
    string a,b;
    cin>>a>>b;
    int n=a.size();
    for (int i = 0; i < n; i++)
    {
      a[i]=tolower(a[i]);
      b[i]=tolower(b[i]);
    }
    
    if(a<b) cout<<-1;
    else if(a==b) cout<<0;
    else cout<<1;

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}