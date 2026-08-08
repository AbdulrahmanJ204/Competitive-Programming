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
    int b,d;
    cin>>b>>d;
    int a[n];
    for (int i = 0; i < n; i++)
      cin>>a[i];
    
    ll temp=0,ans=0;
    for (int i = 0; i < n; i++)
    {   if(a[i]<=b)
       temp+=a[i];
      if(temp>d) {
        temp=0;
        ans++;
      }
    }
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