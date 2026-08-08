#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> v;
    for (int i = 2; i*i <=n ; ++i) {
        while(n%i==0&&v.size()<k)
        {
            v.push_back(i);
        if(v.size()==k) {

            break;
        }
            n/=i;

        }

    }
    if(v.size()<k-1)
        cout<<-1;
    else if(n>1)
    {
        for (int i = 0; i < k-1; ++i) {
            cout<<v[i]<<' ';
        }
        cout<<n;
    } else cout<<-1;

    return 0;
}
