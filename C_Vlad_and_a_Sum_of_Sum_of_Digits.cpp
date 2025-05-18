#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
const int N=200010;
ll pre[N];
void solve()
{
    ll n;
    cin>>n;
    cout<<pre[n];

  return;
}

int main() {
    InTheNameOfAllah
    ll t=1;
    for (int i = 0; i < N; i++)
    {
      pre[i]=0;
    }
    for (int i = 1; i < N; i++)
    {
      int sum=0;
      string s=to_string(i);
      for (int j = 0; j < s.size(); j++)
      {
        sum+=s[j]-'0';
      }


      pre[i]=pre[i-1]+sum;
    }
    
    
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}