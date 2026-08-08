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
    test {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        a[0] = 0;
        string s;
        cin >> s;
        ll b[n];
        for (int i = 0; i < n; ++i) {
            b[i] = (s[i] == 'B') ? 1 : -1;
        }
        for (int i = n - 1; i >= 0; --i) {
            b[a[i]] += b[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {

            if (b[i] == 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}