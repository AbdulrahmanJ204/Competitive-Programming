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
    string a,b;
    cin>>a>>b;
    int i;
    int ans=0;
    for (i = 0; i < n-1; i++)
    {
      if(a[i]!=b[i]&&a[i+1]!=b[i+1]&&a[i]!=a[i+1]) 
      {ans++; i++;}
      else if(a[i]!=b[i]) ans++;
    }
    if(i==n-1) if(a[i]!=b[i]) ans++;
    cout<<ans;

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