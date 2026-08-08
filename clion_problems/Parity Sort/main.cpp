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
        int a[n];
        bool b[n];
        for (int j = 0; j < n; ++j) {
            b[j]=0;
        }
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            b[i]=a[i]%2;
        }
        bool exist=true;
        sort(a,a+n);
        for (int i = 0; i < n; ++i) {
            if(a[i]%2!=b[i])
                exist=false;
        }
        if(exist)  cyes;
        else cno;


    }

    /*
    test {
    int n;
    cin>>n;
    int a[n];
    vector<int>v;
    bool odd,even,exist=true;
    cin>>a[0];
    v.push_back(a[0]);
    if(a[0]%2==0)
        even=true;
    else odd=true;
    for (int i = 1; i < n; ++i) {
            cin>>a[i];
            v.push_back(a[i]);

        }
    if(!exist) {
        cno;
        continue;
    }
    sort(v.begin(),v.end());
        for (int i = 0; i < n; ++i) {
            if(v[i]%2!=a[i]%2)
                exist=false;
        }
        if (exist) cyes;
        else cno;

    }
*/
    return 0;
}