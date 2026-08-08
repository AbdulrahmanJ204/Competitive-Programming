#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,m;
    cin>>n>>m;
    ll a[n+10];
    a[0]=0;
    for (int i = 1; i < n+1; ++i) {
        cin>>a[i];
    }
    ll pre[n+10],suf[n+10];
    for (int j = 0; j < n + 10; ++j) {
        pre[j]=0;
        suf[j]=0;
    }
    for (int i = 1; i < n+1; ++i) {
       if(a[i-1]>a[i])
        pre[i]=pre[i-1]+a[i-1]-a[i];
       else
           pre[i]=pre[i-1];
    //   cout<<pre[i]<<' ';
    }
 //   cout<<endl;
    for (int i = n; i >=1  ; --i) {
        if(a[i-1]<a[i])
        suf[i-1]=suf[i]+a[i]-a[i-1];
        else
            suf[i-1]=suf[i];
     //   cout<<suf[i]<<' ';
    }
  //  cout<<endl;
    while(m--)
    {
        int s,t;
        ll ans=0;
        cin>>s>>t;
        if(s>t)
            cout<<suf[t]-suf[s]<<endl;
        else if(s<t)
           cout<<pre[t]-pre[s]<<endl;

    }
    return 0;
}
