
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
    int n;
    cin>>n;
    int a[n] ;
    int odd=0,even=0;
    bool exist =false;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(a[i]%2==0) even++;
            else odd++;
        }
        if(odd %2==0) cyes;
        else cno;
    }
    return 0;
}