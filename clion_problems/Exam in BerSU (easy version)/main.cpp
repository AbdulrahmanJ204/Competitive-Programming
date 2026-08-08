#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int m,n;
    cin>>n>>m;
    multiset<int> a1;

    ll sum=0;

    for (int j = 0; j < n; ++j) {
        int x;
        cin>>x;
        sum+=x;
        int ans=0;
        auto it = a1.rbegin();
        ll temp = sum;
        while(temp >m&& it!=a1.rend())
        {
            temp-=*it;
            it++;
            ans++;
        }

        a1.insert(x);



        cout<<ans<<' ';
    }


    return 0;
}
