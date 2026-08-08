#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"
#define cno cout<<"NO"
#define cin(v) for(ll i=0;i<v.size();i++)cin>>v[i];
#define cin1(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define cin2(v,n,m) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) cin>>v[i][j];
#define tryAndCry(v) for(auto x : v){cout<<x<<" ";}cout<<"\n";
#define cout1(v,n) for(ll i=0;i<n;i++)cout<<v[i]<<' '; cendl;
#define cout2(v,n,m) for(ll i=0;i<n;i++,cendl) for (int j = 0; j < m; j++) cout<<v[i][j]<<' ';
#define assign1(v,n,value) for(ll i=0;i<n;i++)v[i]=value;
#define assign2(v,n,m,value) for(ll i=0;i<n;i++) for (int j = 0; j < m; j++) v[i][j]=value;
#define unq(v) v.resize(distance(v.begin(),unique(all(v))));
#define oo  LLONG_MAX
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
// Function to compute the Euler's Totient function for all integers up to n
const int z = 1e7;
int phi[z+1];
computeTotients(int n) {
    for (int i = 1; i <= n; ++i) {
        phi[i] = i; // Initialize phi[i] to i
    }

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) { // i is a prime
            for (int j = i; j <= n; j += i) {
                phi[j] *= (i - 1);
                phi[j] /= i;
            }
        }
    }
    
}

// Function to count coprime pairs (i, j) where 1 <= i < j <= n
long long countCoprimePairs(int l , int r) {
    long long totalPairs = 0;

    // Sum up the totient values from 1 to n
    for (int i = l+1; i <= r; ++i) {
        totalPairs += phi[i];
    }

    return totalPairs;
}
void solve()
{
    ll n;
    cin>>n;
    int cnt =0;
    for (int i = 2; i < 5; i++)
    {
      for (int j = i+1; j < 5; j++)
      {
        if(__gcd(i,j)==1) cnt++;
      }
      
    }
    cout<<cnt<<endl;
    cout<<countCoprimePairs(2 , 4);

  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    computeTotients(1e7);
    
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}