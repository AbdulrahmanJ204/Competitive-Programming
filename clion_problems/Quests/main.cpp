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
ll n,c,d;
ll a[200000];
bool check (ll mid)
{
    //cout<<"MID = "<<mid<<endl;
    ll s=a[n-1];
    ll i=n-2;
    ll x=mid;
    while(x&&i>=0)
    {
        s+=a[i];
        x--;
        i--;
    }
    ll sum=0;
    ll count=d/(mid+1);
    ll mod=d%(mid+1);
  //  cout<<count<<' '<<mod<<' '<<s<<endl;
    sum+=count*s;
    i=n-1;
    while(mod&&i>=0)
    {
        sum+=a[i];
        i--;
        mod--;
    }

    return sum>=c;

}

int main() {
    InTheNameOfAllah
    test {

    cin>>n>>c>>d;

        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }

        sort(a,a+n);
        if(a[n-1]*d<c) {
            cout << "Impossible" << endl;
            continue;
        }
        else if(a[n-1]>=c)
        {
            cout<<"Infinity"<<endl;
            continue;
        }
        else
        {
            ll l=0,r=d-1,ans=0;
            while(l<=r) {
                ll mid = (l + r) / 2;
                bool x = check(mid);
                if (x)
                {
                    ans=max(ans,mid);
                    l=mid+1;
                }
                else r=mid-1;
            }
          if(ans==d-1) cout<<"Infinity"<<endl;
            else  cout<<ans<<endl;
        }


    }
    return 0;
}