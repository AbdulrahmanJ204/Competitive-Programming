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
    int n;
    cin >> n;
    int a[n];
    bool allzero=true;
    ll sum=0;
    for (int i = 0; i <n; ++i) {
        cin>>a[i];
        sum+=a[i];
        if(a[i]!=0) allzero=false;
    }
    if(allzero) cno;
    else {
        if(sum!=0)
        {
            cyes;
            cout<<1<<endl;
            cout<<1<<' '<<n<<endl;
        }
        else {
            int e1;
            for (int i = 0; i < n; ++i) {
                sum-=a[i];
                if(sum!=0) {
                    e1 = i + 1;
                    break;
                }
            }
            cyes;
            cout<<2<<endl;
            cout<<1<<' '<<e1++<<endl;
            cout<<e1<<' '<<n<<endl;
        }



    }


    return 0;
}