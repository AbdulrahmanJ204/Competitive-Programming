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
    int n;
    cin>>n;
    string a,b,c,s="";
    cin>>a>>b>>c;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]==b[i])
            s+=a[i];
        else if(a[i]==c[i])
            s+=a[i];
        else if(b[i]==c[i])
            s+=b[i];
        else s+=a[i];
    }
    cout<<s<<endl;





    return 0;
}