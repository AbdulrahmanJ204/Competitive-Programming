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
#define oo  LLONG_MAX;
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int lengthOfLIS(vector<int>& nums)
{

    // Binary search approach
    int n = nums.size();
    vector<int> ans;

    // Initialize the answer vector with the
    // first element of nums
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {

            // If the current number is greater
            // than the last element of the answer
            // vector, it means we have found a
            // longer increasing subsequence.
            // Hence, we append the current number
            // to the answer vector.
            ans.push_back(nums[i]);
        }
        else {

            // If the current number is not
            // greater than the last element of
            // the answer vector, we perform
            // a binary search to find the smallest
            // element in the answer vector that
            // is greater than or equal to the
            // current number.

            // The lower_bound function returns
            // an iterator pointing to the first
            // element that is not less than
            // the current number.
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();

            // We update the element at the
            // found position with the current number.
            // By doing this, we are maintaining
            // a sorted order in the answer vector.
            ans[low] = nums[i];
        }
    }

    // The length of the answer vector
    // represents the length of the
    // longest increasing subsequence.
    return ans.size();
}

void fun(ll &a, ll &b) {
 
    if (a * b < 0) {
        a = -abs(a);
        b = abs(b);
    } else if (a * b > 0) {
        a = abs(a);
        b = abs(b);
    } else {
      if(b) b=1e6;
      if(a) a=1e6;
    }
    ll gc = __gcd(abs(a), abs(b));
    if (gc)
        a /= gc, b /= gc;
}
void solve()
{
    ll x1 , y1 ;
    cin>>x1>>y1;
    ll n; 
    cin>>n;
    pair<pair<int, int>,int> a[n];
    for (int i = 0; i < n; i++)
    {
      int x, y, h;
      cin>>x>>y>>h;
      a[i]={{x,y},h};
    }
    sort(a, a+n);
    map<pair<int,int> , vector<int>> lines1 , lines2;
     for (ll j = 0; j < n; j++) {
            ll curX = a[j].first.first, curY = a[j].first.second;
            ll dx = curX - x1, dy = curY - y1;
            ll h= a[j].second;
            fun(dx, dy); 
            if (dx && dy) // not horizontal and not vertical y= 
            curX < x1 ?   lines1[make_pair(dx, dy)].push_back(h) :lines2[make_pair(dx, dy)].push_back(h);
            else if(!dx) // vertical , x=x1
            curY < y1  ? lines1[make_pair(dx, 1e8)].push_back(h) : lines2[make_pair(dx, 1e8)].push_back(h);
            else if(!dy) // horizontal y=y1 
            curX < x1 ?  lines1[make_pair(1e8, dy)].push_back(h) :lines2[make_pair(1e8, dy)].push_back(h); 
        }
        ll ans=0;

        for(auto &line: lines1){
          reverse(all(line.second));
          ans+=lengthOfLIS(line.second);
        }    

        for(auto &line: lines2){
          ans+=lengthOfLIS(line.second);
        }    
        cout<<ans;
  return;
}

int32_t main() {
    InTheNameOfAllah
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t=1;
    //cin>>t;
    while(t--){
      solve();
      cendl;
    }
    return 0;
}