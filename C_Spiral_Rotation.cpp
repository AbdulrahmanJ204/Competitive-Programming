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


void rotate90(vector<string>& s , int start ) {
        int n = s.size();
    
        int end =  n - start ;
        int cnt=0;
        map<pair<int,int> ,int> mp;
        for (int i = start; i < end -1; i++)
        mp[{start , i}]= cnt++;        

        for (int i = start; i < end -1; i++)
        mp[{i,end-1}]=cnt++;

        for (int i = end - 1; i > start; i--)
        mp[{end-1 , i}]=cnt++;
        
        
        for (int i = end - 1; i > start; i--)
          mp[{i,start}]=cnt++;
          
        
        char temp[cnt];
        for(auto &x :mp)
        temp[x.second]=s[x.first.first][x.first.second];
       
        int rota = (start +1 ) * (cnt/4);
        for(auto &x :mp)
          x.second+=rota ,x.second%=cnt ,temp[x.second] = s[x.first.first][x.first.second] ;
       
         cnt=0;
        for (int i = start; i < end -1; i++)
        s[start][i]= temp[cnt++];        

        for (int i = start; i < end -1; i++)
        s[i][end-1]=temp[cnt++];

        for (int i = end - 1; i > start; i--)
        s[end-1][ i]=temp[cnt++];
        
        for (int i = end - 1; i > start; i--)
        s[i][start]=temp[cnt++];
        
       
    
}


void solve()
{
    ll n;
    cin>>n;
    vector<string> s(n);
    cin1(s,n);
        
    for (int i = 0; i < n/2; i++)
      rotate90(s , i);      
    
    for (int i = 0; i < n; i++)
      cout<<s[i]<<endl;

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}