#include <bits/stdc++.h>
#include<fstream>
using namespace std;


#define ll long long
#define int long long

const ll maxn = 1e7;
int cnt =0;
vector<bool> primes(maxn + 1, true);
void sieve(ll n) {
    primes[0] = primes[1] = 0;
    for (ll p = 2; p <= n; p++)
        if (primes[p]) {
            cnt++;
            for (ll i = p * p; i <= n; i += p)
                primes[i] = 0;
        }
}
void solve() {    
    // printf("%lld ",x);
    // fstream file;
    // file.open("H.txt", ios:: out);
    // ll n= 1e3 , m=1e3;
    // file << 1 << "\n";
    // file << n<< " " << m << "\n";
    // for (int i = 0; i < n; i++)
    // for (int j = 0; j < m; j++)
    //     file<<0<<endl;
    // file.close();
    sieve(1e7);
    cout<<cnt<<endl;
}

int32_t main() {
    solve();
    return 0;
}
