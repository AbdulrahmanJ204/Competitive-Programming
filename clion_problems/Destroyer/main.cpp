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
        int c=0;
        bool exist=true;
        map <int,int>m;
        for (int j = 0; j < 110; ++j) {
            m[j]=0;
        }
        int mx=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            mx=max(a[i],mx);
        m[a[i]]++;
        }
        sort(a,a+n);
        if(a[0]!=0)
            exist=false;
        for (int i = 1; i <= mx; ++i) {
           // cout<<m[a[i]]<<' ';
            if(m[i-1]<m[i])
                exist=false;
        }
        if(exist)cyes;
        else cno;
    }
    return 0;
}