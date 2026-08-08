
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
 ll mod=32768;
vector <int> v;

//ll dp[mod+1];
ll solve(ll i){
    if(i%mod==0) return 0;
//    if(dp[i]!=-1) return dp[i];
    if(i>pow(2,15)) return 0;
//    if(dp[i]!=-1) return dp[i];
    ll c1,c2;
    c2 = 1 + solve((i *2));
    c1 = 1 + solve((i + 1));
    return min(c1, c2);
//  return  dp[i]= min(c1, c2);
}
ll solve2(ll n){
    int ans=1e9;
    for (int i = 0; i <= 15; ++i) {
        ll temp=n+i;
        for (int j = 0; j <= 15; ++j) {
            if((temp* (ll)floor(pow(2,j))  )%mod==0) ans = min(ans, i+j);
        }
    }

return ans;
}
int main() {
    InTheNameOfAllah
//    for (int j = 0; j < mod + 1; ++j) {
//        dp[j]=-1;
//    }

    ll temp=pow(2,15);
    for (int i = 2; i <= 100; ++i) {
        v.push_back(temp * i);
    }
    while(temp>0) {
        v.push_back(temp);
        temp/=2;
    }
    sort(v.begin(), v.end());
//    for(auto x: v) cout << x << ' ';
//    cendl;
//    cout<<solve2(19,v);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << solve2(a[i]) << ' ';
    }
    return 0;
}