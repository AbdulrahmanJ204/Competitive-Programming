#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        int n;
        cin>>n;
       map<int,int> m;
       vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin>>x;
           v.push_back(x);
            m[x]++;
        }
        int ans=0;
        sort(v.begin(),v.end());
        ll sum=0;
            v.push_back(10000000);
        for (int j = 0; j < n; ++j) {

            int next=upper_bound(v.begin(),v.end(),v[j])-v.begin();
         //   cout<<" vj = "<<v[j]<<" vnext = "<<v[next]<<endl;
           // cout<<"ans = "<<ans<< " mj = "<<m[j]<< " mnext = "<<m[next]<<endl;
            if(v[next]-v[j]<=1)
            {
                ans=max(ans,m[v[j]]+m[v[next]]);
            }
            else
                ans=max(ans,m[v[j]]);


        }


        cout<<ans<<endl;



    }
    return 0;
}