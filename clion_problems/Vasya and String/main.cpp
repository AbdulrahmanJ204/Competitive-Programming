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
int const N=1e5+10;
int a=0,b=0,n,k;
string s;
ll pre[N];
ll pre2[N];
bool check(ll len)
{
    for (int i = 1; i <= n-len+1 ; ++i) {
        if(pre[i+len-1]-pre[i-1]<=k)
            return true;
      //  cout<<i<<endl;
      //  cout<<pre[i+len-1]-pre[i-1]<<' '<<pre[i+len-1]<<' '<<pre[i-1]<<endl;
    }

    return false;
}
bool check2(ll len)
{
    for (int i = 1; i <= n-len+1 ; ++i) {
        if(pre2[i+len-1]-pre2[i-1]<=k)
            return true;
      //  cout<<i<<endl;
      //  cout<<pre[i+len-1]-pre[i-1]<<' '<<pre[i+len-1]<<' '<<pre[i-1]<<endl;
    }

    return false;
}


int main() {
    InTheNameOfAllah


    cin>>n>>k;
    cin>>s;
    s=" "+s;
    for (int i = 0; i <= n; ++i) {
            pre[i]=0;
    }
    bool b1=true,a1=true;
    for (int i = 1; i <= n ; ++i) {
        if(s[i]=='a') {
            a++;
            b1=false;
        }
        else {
            b++;
            a1=false;
        }
    }
    if(a<=k||b<=k||k==n||a1||b1) {

        cout << n << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if(a>b)
        {
            if(s[i]=='b')
                pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        }else if(a<b)
        {
            if(s[i]=='a')
                pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        } else
        {
            if(s[i]=='b')
                pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
            if(s[i]=='a')
                pre2[i]=pre2[i-1]+1;
            else pre2[i]=pre2[i-1];
        }

    }

    ll l=1,r=n;
    ll ans=0;
    while(l<=r)
    {
        ll len=(l+r)/2;
        bool x=check(len);
        if(x)
        {
            ans=max(len,ans);
            l=len+1;
        }
        else
        {
            r=len-1;
        }
    }
    if(a==b)
    {
        l=1;
        r=n;
        while(l<=r)
        {
            ll len=(l+r)/2;
            bool x=check2(len);
            if(x)
            {
                ans=max(len,ans);
                l=len+1;
            }
            else
            {
                r=len-1;
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}