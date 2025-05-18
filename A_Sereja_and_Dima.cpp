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
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin>>a[i];
    }
    bool x=true;
    int s=0,d=0;
    int i=0,j=n-1;
    while(i<=j){
      if(x){
        if(a[i]>a[j]) s+=a[i++];
        else s+=a[j--];
      }
      else {
        if(a[i]>a[j]) d+=a[i++];
        else d+=a[j--];
      }
      x=!x;
    }
    cout<<s<<' '<<d;
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