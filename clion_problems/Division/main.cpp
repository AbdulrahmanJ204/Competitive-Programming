#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        int n;
        cin >> n;
        if (n <= 1399)
            cout << "Division 4" << endl;
        else if (n <= 1599)cout << "Division 3" << endl;
        else if (n <= 1899)cout << "Division 2" << endl;
        else if (n >= 1900)cout << "Division 1" << endl;
    }
    return 0;
}