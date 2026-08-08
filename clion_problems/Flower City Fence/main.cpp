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
    cin>>n;
    ll a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
       if(a[0]!=n)
       {
           cno;

       }
       else {
            vector<ll> v;
            v.push_back(a[0]);
            ll c = 1;
            for (int i = 0; i < n - 1; ++i) {
                ll x = a[i ] - a[i+1];
                for (int j = 0; j < x; ++j) {
                    v.push_back(c);
                }
                c++;
            }
          c=v.size();
            while(c<n)
          {
              v.push_back(n)
          ;c++;
          }
            sort(v.rbegin(), v.rend());
            bool exist=true;
           for (int i = 0; i < n; ++i) {
               if(a[i]!=v[i]) {
                   exist = false;
                   break;
               }
           }
           if(exist) cyes;
           else cno;

        }
    }
    return 0;
}