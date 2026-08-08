/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int max_weight=10,max_size=16;
const int N=10;
int dp[N][max_weight+1][max_size+1];
ll ans=0;
int w[N]={1,2,3,4,5},s[N]={5,6,7,8,9},p[N]={10,20,30,43,51};
ll solve(int i, ll weight,ll size){
    if(i>=N) return 0;
    if(size==0|| weight==0) return 0;
    if(size<0|| weight<0) return -1e9;
    if(dp[i][weight][size]!=-1) return dp[i][weight][size];
    ll c1=-1,c2;
    if(weight-w[i]>=0&&size-s[i]>=0)
    c1=p[i]+solve(i+1, weight-w[i],size-s[i]);
    c2=solve(i+1,weight,size);
    dp[i][weight][size]= max(c1,c2);
    return dp[i][weight][size];
}
vector<ll> q;
ll ans2=0;
ll solve2(int i, ll weight,ll size,ll price){
    if(i>=N) return 0;
    if(size==0|| weight==0) {
        if (price == ans)
            ans2 = max(ans2, weight);
        return 0;
    }
    if(size<0|| weight<0) return -1e9;
    if(price==ans)
        ans2=max(ans2,weight);
    if(weight-w[i]>=0&&size-s[i]>=0)
    solve2(i+1,weight-w[i],size-s[i],price+p[i]);
    solve2(i+1,weight,size,price);
    return 0;
}
int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= max_weight; ++j) {
            for (int k = 0; k <=     max_size; ++k) {
                dp[i][j][k]=-1;
            }
        }
    }
    ans=solve(0,max_weight,max_size);
    cout<<ans<<endl;
    solve2(0,max_weight,max_size,0);
    cout<<ans2<<endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < max_weight; ++j) {
            for (int k = 0; k < max_size; ++k) {
                cout<<dp[i][j][k]<<' ';
            }cout<<endl;
        }cout<<endl;
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int max_weight=15,max_size=20;
const int N=5;
ll dp[N][max_weight+1][max_size+1];
ll ans;
int w[N]={1,2,3,4,5},s[N]={5,6,7,8,9},p[N]={10,20,31,43,51};
ll solve(int i, ll weight,ll size){
    if(size>max_size|| weight>max_weight) return -1e9;
    if(i==N ||weight==0||size==0) return 0;
//    if(dp[i][weight][size]!=-1) return dp[i][weight][size];
    ll c1,c2;
    if(w[i]<=max_weight&&s[i]<max_size)
    c1=p[i]+solve(i+1, weight+w[i],size+s[i]);
    c2=solve(i+1,weight,size);
    return dp[i][weight][size]= max(c1,c2);
    return max(c1,c2);
}


/*pair<ll,ll> solve(int i, int weight,int size , int rw){
    if(i==N) return {0,0};
    if(size>max_size|| weight>max_weight) return {-1e9, -1e9};
//    if(dp[i][weight][size]!=-1) return {dp[i][weight][size],dp2[i][weight][size]=max(weight,dp2[i][weight][size])};
    pair<ll,ll> c1={0,0},c2;
    if(weight-w[i]>=0&&size-s[i]>=0) {
        c1 = solve(i + 1, weight + w[i], size + s[i]);
        c1.first+=p[i];
        c1.second+=w[i];
    }
    c2=solve(i+1,weight,size);
    cout<<c1.first<<' '<<c1.second<<' '<<c2.first<<' '<<c2.second<<endl;
    dp[i][weight][size]= max(c1.first,c2.first);
    dp2[i][weight][size] = max(c1.second,c2.second);
    return {dp[i][weight][size],dp2[i][weight][size]};
}*/
//vector<ll> q;
//ll ans2=0;
//ll solve2(int i, ll weight,ll size,ll price){
//    if(i>=N) return 0;
//    if(size>max_size|| weight>max_weight) return -1e9;
//    if(price==ans)
//        ans2=max(ans2,weight);
//
//    solve2(i+1, weight+w[i],size+s[i],price+p[i]);
//    solve2(i+1,weight,size,price);
//    return 0;
//}
int main() {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= max_weight; ++j) {
            for (int k = 0; k <= max_size; ++k) {
                dp[i][j][k]=-1;

            }
        }
    }
     ans=solve(0,max_weight,max_size);
     cout<<ans<<endl;
//    cout<<ans.first<<' '<<ans.second<<endl;
  //  solve2(0,0,0,0);
//    cout<<ans2<<endl;
    int x=5,y=2; float z;
    z= (float)x/y;
    cout<<z<<endl;
    return 0;
}
