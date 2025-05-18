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
    string s;
    cin>>s;
    int n=s.size();
    for (int i = 0; i < n; i++)
    {
      if(9-s[i]<s[i]){
        if(s[i]=='9'&&i==0) continue;
        else {
          s[i]='9'-s[i]+'0';
        }


      }
    }
    cout<<s;

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