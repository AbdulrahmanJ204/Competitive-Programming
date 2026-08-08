#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    cin>>n;
    bool div=false;
    for (int i = 0; i < 14; ++i) {
        if(n%a[i]==0)
            div=true;
    }
    if(div)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}
