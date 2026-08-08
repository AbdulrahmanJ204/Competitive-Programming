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
    int n,r;
    cin>>n>>r;
    int a[n];
    int sum=1500;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==r)
            cout<<"Correct"<<endl;
        else
            cout<<"Bug"<<endl;
    }
    return 0;
}