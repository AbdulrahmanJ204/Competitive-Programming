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

ll sum(ll x, ll y, ll mod)
{
    return (x % mod + y % mod) % mod;
}
ll sub(ll x, ll y, ll mod)
{
    return (x % mod - y % mod + mod) % mod;
}
ll mul(ll x, ll y, ll mod)
{
    return (x % mod * y % mod) % mod;
}

ll mod=1e9+7;


long long fastPower(ll base, ll exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = mul(result, base, mod) % mod;
        }
        base = mul(base, base, mod) % mod;
        exponent /= 2;
    }
    return result % mod;
}



int main() {
    InTheNameOfAllah
    ll x,y;
    cin>>x>>y;
    ll n;
    cin>>n;
    ll a[6];
    a[0]=x;
    a[1]=y;

    for (int i = 2; i < 6; ++i) {
        a[i]= sub(a[i-1],a[i-2],mod);
//                a[i-1]-a[i-2] ;
    }
    a[1]%=mod;
//    for(int i=0 ; i<6; i++) cout<<a[i]<<' ';
//    cendl;
    for (int i = 0; i < 6; ++i) {
        if((n-1)%6==i) {
            if(a[i]<0)
                cout<<(a[i]+mod)%mod<<endl;
                else
            cout<<a[i]<<endl;break;
        }
    }

    return 0;
}