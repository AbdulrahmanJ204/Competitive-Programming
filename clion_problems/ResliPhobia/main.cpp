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
    int n,k;
    cin>>n>>k;
    int a[n+10];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        ll ans=0;
        priority_queue<int> q;
        for (int i = 0; i < n ; ++i) {

          if(a[i]%2==0) {
              while (a[i] % 2 == 0) {
                  q.push(a[i]);
                  i++;
              }
              i--;
              if(q.size()<=k)
                  while(!q.empty()) {
                      ans += q.top();
                      q.pop();
                  }
                  else {
                  int temp = k;
                  while (temp--&&!q.empty()) {
                      ans+=q.top();
                      q.pop();
                  }
                  while(!q.empty())
                      q.pop();
              }
          }
         else if(a[i]%2==1) {
              while (a[i] % 2 == 1) {
                  q.push(a[i]);
                  i++;
              }
              i--;
              if(q.size()<=k)
                  while(!q.empty()) {
                      ans += q.top();
                      q.pop();
                  }
                  else {
                  int temp = k;
                  while (temp--&&!q.empty()) {
                      ans+=q.top();
                      q.pop();
                      while(!q.empty())
                          q.pop();
                  }
              }
          }
        }

        cout<<ans<<endl;

    }
    return 0;
}