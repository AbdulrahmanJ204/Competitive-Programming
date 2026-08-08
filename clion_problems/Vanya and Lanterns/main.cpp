#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
   // ios_base::sync_with_stdio(0);
  //  cin.tie(0);
   int n;
   ll l;
   cin>>n>>l;
   double a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n);
    double ans=0;
    for (int i = 0; i < n-1; ++i) {
        ans=max(ans,a[i+1]-a[i]);
    }ans/=2;
    ans=max(ans,max(a[0],l-a[n-1]));
    cout<<fixed<<setprecision(10)<<ans<<endl;


    return 0;
}