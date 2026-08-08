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
    string s1,s2;
    cin>>s1>>s2;
    map<char,int> m;
    for (int i = 0; i < 2; i++)
    {
      m[s1[i]]++;
      m[s2[i]]++;
    }
    int mx=0;
    cout<<m.size()-1;
    
    
    
    

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