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
ll n;
double k;
const int N = 1e5 + 10;
ll a[N];

bool check(double mid) {
   ll temp = 0;
    if (mid == 0) return 0;
    for (ll i = 0; i < n; ++i) {
        temp += a[i] / mid;
    }
    return temp >= k;
}

int main() {
    InTheNameOfAllah

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double l = 0, r = 10000000;
    double ans = 0;
    int x=100;
    while(x--)
    {
        double mid = (l + r) / 2;

        if (check(mid)) {
            ans = max(ans, mid);
            l = mid;
        } else r = mid;
    }

    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}