#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    // بسم اللَّه الرحمن الرحيم
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    map<ll,ll> m;
    bool exist=false;
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
            m[v[i]]++;
            if(m[v[i]]>=k)
                exist=true;
        }
        if(!exist) {
            cout << -1 << endl;
            continue;
        }
        vector<ll> v1;
        for(auto x:m)
        {
            if(x.second>=k)
                v1.push_back(x.first);
        }
        sort(v1.begin(),v1.end());
        ll l=1e9,r=0;
        pair<ll,ll> ans={v1[0],v1[0]};

        for (int i = 0; i < v1.size()-1; ++i) {
            if(v1[i+1]>v1[i]+1)
            {
                l=1e9;r=0;
            }
            else
            {
                r=v1[i+1];
                l=min(l,v1[i]);
                if(r-l>=ans.second-ans.first) {
                    ans.first = l;
                    ans.second = r;
                }
            }
        }
        cout<<ans.first<<' '<<ans.second<<' '<<endl;


    }
    return 0;
}