#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
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
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

ll cnt[34][10][10];
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[10];
    assign1(a,10,0);
    for (int i = 0; i < m; i++)
    {
      int x;
      cin>>x;
      a[x]++;
    }
    
    

    //  (int card = 1; card < 10; card++){
    //   ll sum=0;
    //   cout<<"Card : "<<card<<endl;
    // for (int i = 1; i < 10; i++)
    // {
    //   cout<<cnt[n][card][i]<<' ';
    //   sum+=cnt[n][card][i];
    // }
    // cout<<"\n Sum = "<<sum<<endl;
    // cendl;
    // }

    for (ll card1 = 1; card1 < 10; card1++)
    for (ll card2 = 1; card2 < 10; card2++)
    for (ll card3 = 1; card3 < 10; card3++)
    {
      // cout<<card1<<' '<<card2<<' '<<card3<<endl;
      ll dif=-1;
      for (int i = 1; i < 10; i++)
      {
        ll cur = cnt[n][card1][i]+cnt[n][card2][i]+cnt[n][card3][i];
        if(cur-a[i]<0||cur-a[i]>=2) {dif=-1;
        break;} 
        if(cur-a[i]==1 && dif!=-1){
          dif=-1;
        break;
        } 
        if(cur-a[i]==1) dif=i;

      }
      if(dif!=-1){
        cout<<dif;
        return;
      }
    }
    

  return;
}

int main() {
    InTheNameOfAllah
    
    for (int card = 1; card < 9; card++)
    {
      vector<int> v;
      v.push_back(card);
      
      for (int n = 1; n <= 33; n++)
      {
        vector<int> temp;
        for(int &x : v) {
          string s= to_string(x*3);
          for (int j = 0; j < s.size(); j++)
            temp.push_back(s[j]-'0');
        }
        swap(temp,v);
      for (int i = 0; i < v.size(); i++)
      {
        cnt[n][card][v[i]]++;
        if(card==8)
        cnt[n][card+1][v[i]]++;
      }
      }
      
    }
    ll t=1;
    cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}