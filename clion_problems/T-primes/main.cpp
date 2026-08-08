#include <bits/stdc++.h>
using namespace std;
#define ll long long
//lecture

void solve()
{   ll x;
    cin>>x;
    ll m=sqrt(x);
    if(x==1)
    {
        cout<<"NO";
        return;
    }
    if(x != m * m)
    {
        cout << "NO";
        return ;
    }

    for (int i = 2; i*i <=m ; ++i)
    {
        if(m % i==0)
        {
            cout << "NO" ;
            return;
        }
    }
    cout<<"YES";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   ll t=1;
   cin>>t;
    while(t--)
    {

        solve();
        cout<<'\n';
    }


    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n)
{
    ll x=sqrt(n);
    if(n==1||n==0)
    {cout<<"NO"<<endl;
        return;}
    if(x*x!=n) {
        cout << "NO" << endl;
    return ;
    }
    for (int i = 2; i*i <=x ; ++i) {
        if(x%i==0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   ll n;
   cin>>n;
    while(n--)
    {
        ll x;
        cin>>x;
        solve(x);
    }


    return 0;
}
*/
/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maxnn=1000100;
vector<bool> prime(maxnn+1,true);
void seive_ofai(ll n)
{   prime[0]=0;
    prime[1]=0;

    for (ll i = 2; i <=n ; ++i) {
        if(prime[i])
            for (ll j = i*i; j <=n ; j+=i) {
                prime[j]=false;
            }
    }
}
int main() {
   ll n;
   cin>>n;

   seive_ofai(maxnn);

    for (int i = 0; i < n; ++i) {
        ll a;
        cin>>a;

        ll x=sqrt(a);

        if(a==1||a==0)
            cout<<"NO"<<endl;
        else if(prime[x]&&x*x==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }
    return 0;
}
*/