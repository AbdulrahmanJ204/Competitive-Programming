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

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return;
    }
    if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
        cout << -1;
        return;
    }
    int ans = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
            ans++;
        } else if (n % 3 == 0) {
            n = n * 2 / 3;
            ans++;
        } else if (n % 5 == 0) {
            n = n * 4 / 5;
            ans++;
        }
        else break;
    }
    if(n==1) cout<<ans;
    else cout<<-1;
}

int main() {
    InTheNameOfAllah
    test {
        solve();
        cendl;
    }
    return 0;
}