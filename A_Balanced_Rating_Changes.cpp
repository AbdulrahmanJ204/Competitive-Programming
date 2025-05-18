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
    int sign=-1;
    for (int i = 0; i < n; i++)
    {
      int x; cin>>x;
      if(x%2){
        cout<<(x+sign)/2<<endl;
        sign*=-1;
      }
      else cout<<x/2<<endl;
    }
    
    // double a[n]; ll b[n];
    // bool x=true;
    // for (int i = 0; i < n; i++)
    // {
    //   cin>>a[i] ;
    //   if(abs((ll)a[i])%2){
    //     if(x) b[i]=ceil(a[i]/2);
    //     else b[i]=floor(a[i]/2);
    //     x=!x;
    //   }
    //   else b[i]=a[i]/2;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //   cout<<b[i]<<endl;
    // }
    


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