#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    map<int,int> m1,m2;
    ll ans=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            m1[a[i]]++;
            m2[a[i]]=0;
        }
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
            m2[b[i]]++;
        }

        for(auto x:m1)
        {  // cout<<x.first<< "   "<<x.second<<endl;
               // cout<<"\t"<<m2[x.first]<<endl;
            if(m2[x.first]>0)
                ans+=min(x.second,m2[x.first]);
        } //cendl;
        cout<<ans<<endl;
    }
    return 0;
}