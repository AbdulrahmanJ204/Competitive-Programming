#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
 int t;
 cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     priority_queue<ll> a1;
     ll x;
     ll a[n];
     ll sum=0;
     for (int i = 0; i < n; ++i) {

         cin>>a[i];
        a1.push(a[i]);
         if(a[i]==0) {
             sum += a1.top();
             a1.pop();
         }
     }


     cout<<sum<<endl;
 }
    return 0;
}
