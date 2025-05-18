#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
#define int ll

void solve()
{
    ll n,k,pb,ps;
    cin>>n>>k>>pb>>ps;
    int p[n], a[n];
    for (int i = 0; i < n; i++)
      cin>>p[i];
    for (int i = 0; i < n; i++)
      cin>>a[i];
    ll bScore=0 , tempB = 0 , sScore = 0, tempS = 0;
    for (int i = 0; i < n; i++)
      p[i]--;
    pb--,ps--;
    for(int i = 1 ; i<= min(n,k); i++) {
      tempB += a[pb];
      int tempCur= tempB + (k-i) * a[pb];
      bScore=max(bScore,tempCur);
      pb=p[pb];
    }
    for(int i = 1 ; i<= min(n,k); i++) {
      tempS += a[ps];
      int tempCur= tempS + (k-i) * a[ps];
      sScore=max(sScore,tempCur);
      ps=p[ps];
    }
    if(bScore>sScore) cout<<"Bodya";
    else if(bScore==sScore) cout<<"Draw";
    else cout<<"Sasha";        

  return;
}

int32_t main() {
    InTheNameOfAllah
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}