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
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
      if(isdigit(s[i]))
        v.push_back(s[i]-'0');
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size()-1; i++)
      cout<<v[i]<<"+";
    cout<<v[v.size()-1];
    
    
    

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