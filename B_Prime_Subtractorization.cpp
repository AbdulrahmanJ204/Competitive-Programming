#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES" : "NO")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second
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
using namespace std;
const ll maxn = 1e7+10;
vector<bool> primes(maxn + 1, true);
void sieve(ll n) {
    primes[0] = primes[1] = 0;
    for (ll p = 2; p <= n; p++)
        if (primes[p])
            for (ll i = p * p; i <= n; i += p)
                primes[i] = 0;
}

map<int,int> mp;
void solve()
{
 // --InTheNameOfAllah--
  ll n;
  cin>>n;
  if(n<=4){
    cout<<0;
    return;
  }
  cout<<mp[n];
}


















void main_() 
{
    go; 
//    freopen("/Users/first-thread/Desktop/input.txt", "r", stdin);
//    freopen("/Users/first-thread/Desktop/output.txt", "w", stdout);

    // freopen("prime_subtractorization_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    sieve(1e7+10);
    mp[0]=0;
    mp[1]=0;
    ll ans=1;
    for (int i = 5; i < 1e7+1; i++)
    {
      if(primes[i]&&primes[i-2]) mp[i]=++ans;
      else mp[i]=ans;
    }

   
    int t; cin >> t; 
    for(int i=1 ;i <=t;i ++)
    {
        cout << "Case #" << i << ": "; 
        solve(); 
        if(i != t) 
            cout << '\n'; 
    }
}

static void run_with_stack_size(void (*func)(void), size_t 
stsize) {

    char *stack, *send;

    stack = (char *)malloc(stsize);

    send = stack + stsize - 16;

    send = (char *)((uintptr_t)send / 16 * 16);

    asm volatile(

        "mov %%rsp, (%0)\n"

        "mov %0, %%rsp\n"

        :

        : "r"(send));

    func();

    asm volatile("mov (%0), %%rsp\n" : : "r"(send));

    free(stack);

}

int main() {

    run_with_stack_size(main_, 1024 * 1024 * 1024); 

    return 0;

}
