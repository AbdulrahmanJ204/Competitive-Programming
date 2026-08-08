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
//    InTheNameOfAllah
    test {
    int n;
    cin>>n;
    n*=2;
    int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a,a+n);
        int ans=0;
        for (int i = 0; i < n/2 -1 ; ++i) {
            ans+=abs(a[i]-a[i+1]);
        }
        for (int i = n/2; i < n-1; ++i) {
            ans+=abs(a[i]-a[i+1]);
        }
        vector<pair<int,int>> v;
        for (int j = 0; j < n/2 ; ++j) {
            v.push_back(make_pair(a[j],a[n-j-1]));
        }
        cout<<ans<<endl;
        for(auto x:v)
            cout<<x.first<<' '<<x.second<<endl;
    }
    return 0;
}