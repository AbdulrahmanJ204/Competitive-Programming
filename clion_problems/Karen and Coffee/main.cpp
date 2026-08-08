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
    int n,k,q;
    cin>>n>>k>>q;
    int temp=q;
    int recL[n+1], recR[n+1];
    int pre[200001];
    int preK[200001];
    for (int j = 0; j <= 200000; ++j) {
        pre[j]=0;
        preK[j]=0;
    }
    for (int i = 1; i <= n; ++i) {
        cin>>recL[i]>>recR[i];
        pre[recL[i]]++;
        pre[recR[i]+1]--;
    }
    for (int i = 1; i <=200000; ++i) {
        pre[i]+=pre[i-1];
        if(pre[i]>=k) preK[i]=preK[i-1]+1;
        else preK[i]=preK[i-1];
    }

    while(q--) {
        int l,r;
        cin>>l>>r;
        cout<<preK[r]-preK[l-1]<<endl;

    }
    return 0;
}