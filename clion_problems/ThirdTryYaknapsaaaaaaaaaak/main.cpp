
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define cendl cout<<endl

//const int N = 5;
//const int mxw = 10, mxs = 16;
//int w[N] = {3, 3, 5, 5, 11}, s[N] = {5, 6, 7, 3, 9}, p[N] = {41, 41, 30, 41, 52};

const int N = 3;
const int mxw = 3, mxs = 16;
int w[N] = {4,5,6}, s[N] = {5,5,5}, p[N] = {1,2,3};


int dpOfProfit[N][mxw + 1][mxs + 1];
int dpOfWeight[N][mxw + 1][mxs + 1];

pair<int, int> solve(int i, int we, int se) {
    if (we > mxw || se > mxs) return {-1e9, -1e9};
    if (i >= N) return {0, 0};
    if (dpOfProfit[i][we][se] != -1 && dpOfWeight[i][we][se]) return {dpOfProfit[i][we][se], dpOfWeight[i][we][se]};
    pair<int, int> take = {0, 0}, leave;
    if (w[i] <= mxw && s[i]<=mxs) {
        take = solve(i + 1, we + w[i], se + s[i]);
    take.first += p[i];
    take.second += w[i];
    }
    leave = solve(i + 1, we, se);
    if (take.first > leave.first) {
        dpOfProfit[i][we][se] = take.first;
        dpOfWeight[i][we][se] = take.second;
    } else if (take.first < leave.first) {
        dpOfProfit[i][we][se] = leave.first;
        dpOfWeight[i][we][se] = leave.second;
    } else {
        dpOfProfit[i][we][se] = max(take.first, leave.first);
        dpOfWeight[i][we][se] = max(take.second, leave.second);
    }
    return {dpOfProfit[i][we][se], dpOfWeight[i][we][se]};
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < mxw + 1; ++j) {
            for (int k = 0; k < mxs + 1; ++k) {
                dpOfProfit[i][j][k] = -1;
                dpOfWeight[i][j][k] = -1;
            }
        }
    }
    pair<int, int> ans = solve(0, 0, 0);
    cout << ans.first << ' ' << ans.second;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cendl cout<<endl
const int N=5;
const int mxw=15, mxs=20;
int w[N]={1,2,3,4,5},s[N]={5,6,7,8,9},p[N]={10,20,30,40,50};
int dpOfProfit[N][mxw+1][mxs+1];
int solve(int i,int we, int se)
{
    if(we>mxw || se > mxs)  return -1e9;
    if(i>=N) return 0;
    if(dpOfProfit[i][we][se]!=-1) return dpOfProfit[i][we][se];
    int c1=0,c2;
    if(w[i]<=mxw) c1= p[i] + solve(i+1, we+w[i],se +s[i]);
    c2= solve(i+1,we,se);
    return dpOfProfit[i][we][se]= max(c1,c2);
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < mxw + 1; ++j) {
            for (int k = 0; k < mxs + 1; ++k) {
                dpOfProfit[i][j][k]=-1;
            }
        }
    }
    cout<<solve(0,0,0);
    return 0;
}*/