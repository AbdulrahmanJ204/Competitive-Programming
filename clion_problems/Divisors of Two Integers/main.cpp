#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int n;
    cin>>n;
    multiset<int> v;
    if(n==2)
    {
        int x,y;
        cin>>x>>y;
        cout<<x<<" "<<y;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        v.insert(x);
    }
    auto x=v.rbegin();
    if(*x==*(--x)) {
        cout << *x << ' ' << *x << endl;
    return 0;
    }

   int first = *v.rbegin();
    int second;
    for (int i = 1; i*i <= first; ++i) {
        if(i*i==first)
        {
            v.erase(v.find(i));
        }
        else if(first%i==0)
        {
            v.erase(v.find(i));
            v.erase(v.find(first/i));
        }

    }
    second=*v.rbegin();
    cout<<first<<' '<<second<<'\n';
    return 0;
}
