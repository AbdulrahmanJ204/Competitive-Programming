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

ll n,h;
ll a[101];
bool check(ll len) {
    ll temp = len;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] + len < a[i + 1])
            temp += len;
        else
            temp += abs(a[i + 1] - a[i]);
    return temp >= h;
}
int main() {
    InTheNameOfAllah
    test {
        ll ans = 1e18;
        cin >> n >> h;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n >= h) {
            cout << 1 << endl;
            continue;
        }
        ll l = 1, r = h;
        while (l <= r) {
            ll len = (l + r) / 2;
            if (check(len)) {
                ans = min(len, ans);
                r = len - 1;
            } else {
                l = len + 1;
            }
        }
        cout << ans << endl;

    }
    return 0;
}