#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void solve() {
    int zero, one, q = 0;
    cin >> zero >> one;
    vector<int> v;
    string s;
    cin >> s;
    int n = s.size();
    if(n%2==1){
        if(s[n/2]=='1'){
            one--;
        }
        if(s[n/2]=='0'){
            zero--;
        }
        if(s[n/2]=='?')
        {
            if(one%2==1) {
                one--;
                s[n/2]='1';
            }
            if(zero%2==1){
                zero--;
                s[n/2]='0';
            }
        }
    }

    for (int i = 0; i < n / 2; i++) {
        int index = n - i - 1;

        if (s[i] == '0' && s[index] == '0')
            zero -= 2;
        if (s[i] == '1' && s[index] == '1')
            one -= 2;
        if (s[i] == '?' && s[index] == '?') {
            q += 2;
            v.push_back(i);
        }

        if (s[i] == '1' && s[index] == '?') {
            one -= 2;
            s[index] = '1';
        }
        if (s[i] == '?' && s[index] == '1') {
            one -= 2;
            s[i]='1';
        }
        if (s[i] == '0' && s[index] == '?') {
            zero -= 2;
            s[index] = '0';
        }
        if (s[i] == '?' && s[index] == '0') {
            zero -= 2;
            s[i]='0';
        }

        if ((s[i] == '0' && s[index] == '1') || (s[i] == '1' && s[index] == '0')) {
            cout << -1;
            return;
        }
    }
        int i=0;
        int size=v.size();
        while(zero>0&&i<size){
            int index=n-v[i]-1;
            s[v[i]]='0';
            s[index]='0';
            zero-=2;
            i++;
        }
        while(one>0&&i<size){
            int index=n-v[i]-1;
            s[v[i]]='1';
            s[index]='1';
            i++;
            one-=2;
        }
        
    if (zero != 0 || one != 0)
        {
            cout<<-1;
            return;
        }

        cout<<s;



        return;
}

int main() {
    InTheNameOfAllah
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}