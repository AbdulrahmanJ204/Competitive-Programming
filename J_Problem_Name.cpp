#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    string s ;
    cin>>s;
    char k;
    cin>>k;
    cout<<s<<" "<<k<<endl;
    int n = s.size();
    // reverse(all(s)) ;
    if(k=='0'){
      int ind = -1;
      for (int i = 0; i < n; i++)
      {
          if(s[i]==k){
            ind = i ;
            break;
          }
      }
      if(~ind){
        string nw = "" , old = "";
        for (int i = ind; i < n; i++)
        {
          nw+="1" , old +=s[i];
        }
        cout<<nw<<" "<<old<<endl;
        int ans = stoi(nw) - stoi(old);
        // cout<<ans;
      }
      else cout<<0;
      
    }
    else if(k=='9'){
      bool nine= true;
      while(nine){
        nine = false;
        for (int i = 0; i < n; i++)
        {
          /* code */
        }
        
      }
    }
    else{
      int i = 0;
      string nw = "" , old=  "";
      for ( i = 0; i < n; i++)
      { 
        
        if(s[i]==k) break; 
      }
      int j = i;
      while(j<n) old+=s[j] , j++;
      s[i]++; 
      nw+=s[i];
      i++;
      
      while(i<n) s[i]='0', nw +=s[i] , i++;
      // cout<<stoi(nw) - stoi(old);
      cout<<"bbb "<<nw<<" "<<old<<endl;

    }

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}