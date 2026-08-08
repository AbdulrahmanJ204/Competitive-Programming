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
ll a[100000];
bool check(ll len,ll index)
{
    ll last=max(index-len+1,(ll)0);
    ll i=lower_bound(a,a+n,len)-a;
    return i <= last ;
}

int main() {
    InTheNameOfAllah
    test {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> v;
        v.push_back(1);
        for (int j = 1; j < n; ++j) {
            if (a[j] == 1) {
                v.push_back(1);
                continue;
            }
            ll l = 0, r = j + 1, ans = 1;
            while (l <= r) {
                ll len = (l + r) / 2;
                bool x = check(len, j);
                if (x) {
                    ans = max(len, ans);
                    l = len + 1;
                } else r = len - 1;
            }
            v.push_back(ans);
        }
        for (auto x:v) cout << x << ' ';
        cendl;
    }
    return 0;
}