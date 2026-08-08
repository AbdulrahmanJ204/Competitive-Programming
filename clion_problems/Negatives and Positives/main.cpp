
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
    test{
        int n;
        cin >> n;
        ll sum = 0;
        int mx = 2e9;
        int a[n];
        int e=0,o=0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = min(abs(a[i]), mx);
            if(a[i]>0) e++;
            else if(a[i]<0) o++;
            sum+=abs(a[i]);
        }
        if(o%2==0)
            cout<<sum<<endl;
        else cout<<sum-2*mx<<endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
void solve()
{   long long n, ans=0;
    cin>>n;
    long long a[n];;
    bool positive=true;
    int nc=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        ans+=abs(a[i]);

        if(a[i]<0)
            nc++;

    }


    if(nc%2==1)
        positive = false;
    else
        positive=true;

    long long mina=abs(a[0])  ;

    for (int i = 0; i < n   ; ++i)
        mina=min(mina,abs(a[i])) ;


         if(positive)
            cout<<ans<<endl;
        else
            cout<<ans-2*mina<<endl;


}
int main() {
    int t;
    cin >> t;

    while (t--)
    {
    solve();

    }
    return 0;
}
*/
