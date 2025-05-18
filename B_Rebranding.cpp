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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int keys[26];
    
    vector<int> indices[26];
    for (int i = 0; i < n; i++)
    {
      indices[s[i]-'a'].push_back(i);
      
    }
    for (int i = 0; i < 26; i++)
    {
      if(indices[i].size()==0) keys[i]=-1;
      else keys[i]=i;
    }
    
    char x,y;
    for (int i = 0; i < m; i++)
    {
      cin>>x>>y;
      int temp=keys[x-'a'];
      keys[x-'a']=keys[y-'a'];
      keys[y-'a']=temp;
      
    }
    string ans=s;
    
    
    for (int i = 0; i < 26; i++)    
    {
      int index=keys[i];
      char c=i+'a';
      if(index==-1) continue;
      for (int j = 0; j < indices[index].size(); j++)
      {
        int x=indices[index][j];
        s[x]=c;
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