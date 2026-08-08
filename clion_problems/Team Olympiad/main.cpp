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
    vector<int> v1,v2,v3;
    int c[4] = {100000, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[a[i]]++;
        if(a[i]==1) v1.push_back(i+1);
        else if(a[i]==2) v2.push_back(i+1);
        else v3.push_back(i+1);
    }
    int mn=1e9;
    for (int i = 1; i < 4; ++i) {
        mn=min(c[i],mn);
    }
    cout<<mn<<endl;
    for (int i = 0; i < mn; ++i) {
        cout<<v1[i]<<' '<<v2[i]<<' '<<v3[i]<<endl;
    }
    return 0;
}