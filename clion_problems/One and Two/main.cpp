#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    ll a[n];
    int counter=0;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if(a[i]==2)
            counter++;
    }
    bool notexist=true;
    int sc=0;
    if(counter==0) {
        cout << "1" << endl;
        return ;
    }
    for (int i = 0; i < n; ++i) {
        if(a[i]==2)
        {
            sc++;
            if(counter-sc==sc) {
                notexist=false;
                cout << i + 1 << endl;
                break;
            }
        }
    }
  if(notexist)
        cout<<"-1"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

