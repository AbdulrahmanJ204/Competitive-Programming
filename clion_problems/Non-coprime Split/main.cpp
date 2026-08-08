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
   const int size=1e7+1;
   vector<bool>prime(size+1,true) ;
    prime[0]=0;
    prime[1]=0;
    for (ll i = 2; i < size; ++i) {
        if(prime[i])
            for (ll j = i*i; j <= size; j+=i ) {
                prime[j]=false;
            }
    }

    test {
    ll l,r;
    cin>>l>>r;
    if(r<=3) {
        cout << -1 << endl;
        continue;
    }
    if(l==r) {
        if (prime[l]) cout << -1 << endl;
        else
            for (ll i = 2; i * i <= l; ++i) {
                if (l % i == 0) {
                    cout << l - i << ' ' << i << endl;
                    break;
                }
            }
    }
    else {
        bool x=false;
        for (int i = l; i <= r; ++i) {
            if(i%2==0&&i>3) {
                x=true;
                cout << 2 << ' ' << i - 2 << endl;
                break;
            }
        }
        if(!x) cout<<-1<<endl;
    }
    }

    return 0;
}