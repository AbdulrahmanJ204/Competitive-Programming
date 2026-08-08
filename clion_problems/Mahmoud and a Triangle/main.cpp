#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    multiset<ll> sig;
    ll x;
    bool done=false;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        sig.insert(x);}
    auto it=++++sig.begin();

    while(it!=sig.end())
        {
            ll temp=*(--it) + *(--it);
            ++++it;
            if (*it < temp) {
                cout << "YES" << endl;
                done = true;
                break;
            }
             it++;
        }

    if(!done)
         cout<<"NO"<<endl;

    return 0;
}
