/*
            .------.____
         .-'       \ ___)
      .-'         \\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\
        \ /    /__v__\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|
                      (
                        )     (
                 ___...(-------)-....___
             .-""       )    (          ""-.
       .-'``'|-._             )         _.-|
      /  .--.|   `""---...........---""`   |
     /  /    |                             |
     |  |    |                             |
      \  \   |                             |
       `\ `\ |                             |
         `\ `|                             |
         _/ /\                             /
        (__/  \                           /
     _..---""` \                         /`""---.._
  .-'           \                       /          '-.
 :               `-.__             __.-'              :
 :                  ) ""---...---"" (                 :
  '._               `"--...___...--"`              _.'
    \""--..__                              __..--""/
     '._     """----.....______.....----"""     _.'
        `""--..,,_____            _____,,..--""`
                      `"""----"""`
 * */
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
    ll n, q;
    cin >> n >> q;
    ll a[n + 1], k[q + 1], pre[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = a[i];
    }
    pre[0] = 0;
    a[0] = 0;
    k[0] = 0;
    for (int j = 1; j <= q; ++j) {
        cin >> k[j];
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }

    ll last_index = 0;
    ll x=0;
    for (int i = 1; i <= q; ++i) {
        x+=k[i];
        ll c = lower_bound(pre, pre + n + 1, x) - pre;
        if (c > n) {
            cout << n << endl;
            x=0;
        }
        else if (n==c) {
            if(pre[c] == x) {
                cout << n << endl;
                x = 0;
            }
            else cout<<n-c+1<<endl;
        }
        else {
            if(pre[c]==x)
                cout<<n-c<<endl;
            else
            cout << n - c+1 << endl;
        }

    }

    return 0;
}