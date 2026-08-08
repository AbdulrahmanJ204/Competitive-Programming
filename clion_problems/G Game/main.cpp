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
     int n,p,q;
     cin>>n>>p>>q;
     int a[n];
    vector<int> v;
     ll ans=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        v.push_back(a[i]);
        }

        sort(v.begin(),v.end());
        ll sa=0,sb=0;
        int i=n-1,j=0;
        while(p--&&v[i]>0) {
            sa += v[i];
            i--;
        }
        while(q--&&v[j]<0)
        {
            sb+=v[j];
            j++;

        }

            cout<<sa-sb <<endl;
           // cendl;
    }
    return 0;
}
