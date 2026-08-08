#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);

void solve()
{
    ll x;
    cin>>x;
    string s;
    cin>>s;
    int w=0,se=0,e=0,N=0;
    for (int i = 0; i < x; i++)
    {
      if(s[i]=='S')se++;
      if(s[i]=='N')N++;
      if(s[i]=='E')e++;
      if(s[i]=='W')w++;
    }
    // cout<<e<<' '<<w<<' '<<N<<' '<<se<<endl;
    
    int h[4], r[4];
    h[0]=se/2; r[0]=se/2;
    se%=2;
    h[1]=N/2; r[1]=N/2;
    N%=2;
    h[2]=w/2; r[2]=w/2;  
    w%=2;
    h[3]=e/2; r[3]=e/2;  
    e%=2;
    if(e!=w||se!=N){
      cout<<"NO";
      return;
    }
    // for (int i = 0; i < 4; i++)
    
    //   cout<<h[i]<<' ';
    // cendl;

    // for (int i = 0; i < 4; i++)
    
    //   cout<<r[i]<<' ';
    // cendl;
    // cout<<e<<' '<<w<<' '<<N<<' '<<se<<endl;
    // if(h[0]!=r[0]||h[1]!=r[1]||h[2]!=r[2]||h[3]!=r[3]){
    //   cout<<"NO";
    //   return;
    // }
    h[0]+=se;
    h[1]+=N;
    r[2]+=w;
    r[3]+=e;

    bool can=false;
    for (int i = 0; i < 4; i++)
    {
      if(h[i]) can=true;
    }
    if(!can){
      cout<<"NO";
      return;
    }
    can=false;
    for (int i = 0; i < 4; i++)
    {
      if(r[i]) can=true;
    }
    if(!can){
      cout<<"NO";
      return;
    }
    
    
    for (int i = 0; i < x; i++)
    {
      if(s[i]=='S'){
        if(h[0]){
          h[0]--;
          s[i]='H';
        }
        else if(r[0]){
          r[0]--;
          s[i]='R';
        }
      }
      if(s[i]=='N'){
        if(h[1]){
          h[1]--;
          s[i]='H';
        }
        else if(r[1]){
          r[1]--;
          s[i]='R';
        }
      }
      if(s[i]=='W'){
         if(h[2]){
          h[2]--;
          s[i]='H';
        }
        else if(r[2]){
          r[2]--;
          s[i]='R';
        }
      }
      if(s[i]=='E'){
         if(h[3]){
          h[3]--;
          s[i]='H';
        }
        else if(r[3]){
          r[3]--;
          s[i]='R';
        }
      }
    }
    

    cout<<s;
    


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