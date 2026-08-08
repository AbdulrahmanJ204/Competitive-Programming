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
const int N=2e5;
int a[N], b[N];
int n, k;
int main() {
    InTheNameOfAllah
    test {

        cin >> n >> k;
        ll pre[n+1];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pre[i+1]=a[i];
        }
        pre[0]=0;

        for (int i = 1; i < n + 1; ++i) {
            pre[i] += pre[i - 1];
        }
        ll preM[n+1];
        preM[0]=0;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            preM[i+1]=b[i];
        }
        for (int i = 1; i < n+1; ++i) {
            preM[i] = max(preM[i - 1], preM[i]);
        }
        ll ans=0;
        for (int i = 1; i <= min(k,n); ++i) {
            ans=max(pre[i]+(k-i)*preM[i],ans);
        }
        cout<<ans<<endl;

    }
    return 0;
}