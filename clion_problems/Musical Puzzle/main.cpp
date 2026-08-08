#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
   // ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    test {
    string s;
        int n;
        cin>>n>>s;

    map<string,ll>m;
//    string a[]={"a","b","c","d","e","f"};
//
//        for (int i = 0; i < 6; ++i) {
//            for (int j = 0; j < 6; ++j) {
//                string sub=a[i]+a[j];
//
//            }
//        }
        for (int i = 0; i < n - 1; ++i) {
            string sub=s.substr(i,2);
          //  cout<<sub<<' ';
            m[sub]++;
        }//cendl;
        ll ans=0;
        for(auto x: m)
        {  // cout<<x.first<<' '<<x.second<<endl;
            if(x.second>0)
                ans++;
        }
    cout<<ans<<endl;
   // cendl;cendl;




    }
    return 0;
}