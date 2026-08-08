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
    ll b[n];
    ll mx=0;
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
            mx=max(b[i],mx) ;
        }
        bool same=true;
        vector<ll> v;
        v.push_back(b[0]);

       int m=1;
        for (int i = 1; i < n; ++i) {
            if(b[i-1]<=b[i]) {
                v.push_back(b[i]);
            m++;
            }
            else{
                same=false;
                m+=2;
                v.push_back(b[i]);
                v.push_back(b[i]);
            }
        }
        if(same)
        {   cout<<n<<endl;
            for(auto x:v)
                cout<<x<<' ';
            cendl;
        }
        else
        {
            cout<<m<<endl;
            for(auto x:v)
                cout<<x<<' ';
            cendl;
        }
    }
    return 0;
}