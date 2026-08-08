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
    set<char> st;
    for (int i = 0; i < s.size(); i++)
    {
      st.insert(s[i]);
    }
    if(st.size()==1) cout<<"NO";
    else {
      cout<<"YES\n";
      for (int i = 0; i < s.size()-1; i++)
      {
        if(s[i]!=s[i+1]) {swap(s[i],s[i+1]);
        break;}
      }
      cout<<s;
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