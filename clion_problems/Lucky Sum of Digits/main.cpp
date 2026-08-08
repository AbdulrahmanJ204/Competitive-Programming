#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main() {

    ll n,n1;
    cin>>n;
    n1=n; cout<<endl<<endl<<endl;
    ll sum=0;
    string ans="";
    ll four=0,seven=0;
    if(n==7 ||n==4) {
        cout << n;
        return 0;
    }
    if(n%7==0)
    {
        for (int i = 0; i < n / 7; ++i) {
            cout<<7;
        }
        return 0;
    }
    while(n%7!=0)
    {   four++;
        n-=4;
        if(n%7==0) {
            seven = n / 7;
            n = 0;
        }
        if(n<0) {
            cout << -1;
            return 0;
        }
    }
    sum=(4*four)+(seven*7);
    if(sum==n1)
    {
        for (int i = 0; i < four; ++i) {
            cout<<4;
        }
        for (int j = 0; j < seven; ++j) {
            cout<<7;
        }
    }
    else
        cout<<-1;

    return 0;
}
