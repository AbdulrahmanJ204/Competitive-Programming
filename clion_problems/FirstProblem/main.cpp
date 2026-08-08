//First Problem Solution
#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int n = 5, m = 5;
int x;

int third[n][m], dp[n][m]; // dp[i][j]=-1 for each i<n , j<m
int dP(int i, int j) {
    if (i == n || j == m) return 1e9; //1
    if (third[i][j] == -1) return 1e9;
    if (third[i][j] == 0) return dp[i][j] = 0; //1
    if (dp[i][j] != -1) return dp[i][j];
    int down, right;
    down = 1 + dP(i + 1, j);
    right = 1 + dP(i, j + 1);
    return dp[i][j] = min(down, right); // 1
}
/*
 *  int third2[n][m] = {
            {6,  5,  4,  3,  -1},
            {5,  4,  3,  2,  -1},
            {4,  3,  2,  1,  -1},
            {3,  2,  1,  0,  -1},
            {-1, -1, -1, -1, -1}
    };
 */


int first[n][m];

bool iterative(int x) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (first[i][j] == x) return true;
    return false;
}

bool solve(int i, int j) {
    if (i == n || j == m) return false; //1
    if (first[i][j] == x) return true; //1
    bool x1, x2;
    x1 = solve(i + 1, j);
    x2 = solve(i, j + 1);
    return x1 || x2; // 1
}


int second[n][m];

bool iterative2() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (second[i][j] == 0) return true;
            else if (second[i][j] == -1) break;
    return false;
}


bool solve2(int i, int j) {
    if (i == n || j == m) return false; //1
    if (second[i][j] == -1) return false;
    if (second[i][j] == 0) return true; //1
    bool x1, x2;
    x1 = solve2(i + 1, j);
    x2 = solve2(i, j + 1);
    return x1 || x2; // 1
}

void solve3(int I, int J) {
    for (int i = 0; i <= I; ++i)
        for (int j = 0; j <= J; ++j)
            second[i][j] = (I - i) + (J - j);
    for (int i = 0; i <= I; ++i) {
        for (int j = 0; j <= J; ++j)
            cout << second[i][j] << ' ';
        cout << endl;
    }

}

int main() {

    int a[n][m]
            = {
                    {1,   2,   3,   4,   5},
                    {7,   8,   9,   10,  11},
                    {111, 22,  33,  44,  55},
                    {123, 234, 345, 456, 567},
                    {15,  12,  32,  46,  485}
            };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            first[i][j] = a[i][j];
        }
    }
    x = 2133;
    // First Question

    //iterative O(n^2);
    cout << iterative(x) << endl;
    //Recursion O(2^m*n);
    cout << solve(0, 0) << endl;

    cout << endl;
    //----------------------------------------

    // Second Question
    int second2[n][m] = {
            {6,  5,  4,  3,  -1},
            {5,  4,  3,  2,  -1},
            {4,  3,  2,  1,  -1},
            {3,  2,  1,  0,  -1},
            {-1, -1, -1, -1, -1}
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            second[i][j] = second2[i][j];
        }
    }
    //iterative O(n^2);
    cout << iterative2() << endl;

    //Recursion O(2^m*n);
    cout << solve2(0, 0) << endl;

    cout << endl;

    //------------------------------------------

    // Third Question
    int third2[n][m] = {
            {6,  5,  4,  3,  -1},
            {5,  4,  3,  2,  -1},
            {4,  3,  2,  1,  -1},
            {3,  2,  1,  0,  -1},
            {-1, -1, -1, -1, -1}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            third[i][j] = third2[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = -1;
        }
    }

    // O(n*m)
    dP(0, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;

    // case we know indeces of item , O(I*J)
    // I = row , J= Column
    int I = 3, J = 3;
    solve3(I, J);


    return 0;
}
