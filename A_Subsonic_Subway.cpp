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

const int Z = 1e6+10; 

 double a[Z] , b[Z];
 int n;

int check(double mid){
    
  for (int i = 1; i < n; i++)
  {
    if((i+1)*mid < a[i]) return 1;
    else if( (i+1)*mid > b[i]) return 2;
  }
  return 0;
}
void solve()
{
 // --InTheNameOfAllah--
 cin>>n;
 for (int i = 0; i < n; i++)
 {
  cin>>a[i]>>b[i];
 }
 double l = a[0] , r = b[0] ; 
 bool can = false;
 double ans = LLONG_MAX;
 for (int i = 0; i < 200; i++)
 {
  double mid = (l+r)*0.5;
  int res=check(mid);
  if(!res) can = true,  l= mid;
  else if(res == 2) r= mid;
  else if(res == 1) l = mid;
 }
 cout<<fixed<<setprecision(6);
 if(can) 
 cout<<  1/l;
 else cout<<-1;

}


















void main_() 
{
    go; 
//    freopen("/Users/first-thread/Desktop/input.txt", "r", stdin);
//    freopen("/Users/first-thread/Desktop/output.txt", "w", stdout);

    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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
