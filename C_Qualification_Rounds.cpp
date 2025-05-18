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
    int n,k;cin>>n>>k;
    int a[n][k];
    set <int> se;
    for (int i = 0; i < n; i++)
    {
      string temp="";
      for (int j = 0; j < k; j++)
      {
        cin>>a[i][j];
        temp+=to_string(a[i][j]);
      }
            se.insert(stoi(temp));
    }
    vector<int> v;
        for(auto x: se){
          v.push_back(x);
        }
    n=v.size();
    for (int i = 0; i < n; i++)
    { 
      if(v[i]==0) {
        cout<<"YES";
        return;
      }
      for (int j = i+1; j < n; j++)
      {
        bool exist=true;
        string temp=to_string((v[i]+v[j]));
        int size=temp.size();
        for (int l = 0; l < size; l++)  
        {
          if(temp[l]=='2') exist=false;
        }
          if(exist) {
            cout<<"YES";
            return;
          }
      }
    }
    cout<<"NO";
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