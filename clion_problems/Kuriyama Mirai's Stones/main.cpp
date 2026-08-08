#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin>>n;
    vector<ll> a;
    int x;
    a.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin>>x;
        a.push_back(x);
    }
    ll pre[n+10];
    for (int i = 0; i < n + 10; ++i) {
        pre[i]=0;
    }

    for (int i = 1; i <= n; ++i) {
        pre[i]=pre[i-1]+a[i];
    }

    ll spre[n+10];
    spre[0]=0;
    sort(a.begin(),a.end());

    for (int i = 1; i < n+1; ++i) {
        spre[i]=spre[i-1]+a[i];
    }
   
    int t;
    cin>>t;
    while(t--)
    {   int type,l,r;
    cin>>type>>l>>r;
    if(type==1)
        cout<<pre[r]-pre[l-1]<<endl;

    else
    {
        cout<<spre[r]-spre[l-1]<<endl;
     }

//        for (int i = 0; i < n + 1; ++i) {
//            cout<<a[i]<<'\t';
//        } cout<<endl;
//        for (int i = 0; i < n + 1; ++i) {
//            cout<<pre[i]<<'\t';
//        }
//        cout<<endl;
//        for (int i = 0; i < n + 1; ++i) {
//            cout<<spre[i]<<'\t';
//        }cout<<endl;
//        cout<<"end "<<endl;
  }
    return 0;
}
