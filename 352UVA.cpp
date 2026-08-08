#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
ll n;
const int N = 25;
char s[N][N];
bool visited[N][N];
bool valid(int i, int j) {
    return i < n && i >= 0 && j >= 0 && j < n;
}
void dfs(int i, int j) {
    if (!valid(i, j) || s[i][j] != '1' || visited[i][j])
        return;
    visited[i][j] = true;

    int a[3]{-1, 0, 1};
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            dfs(i + a[x], j + a[y]);
        }
    }

    return;
}
int main() {
    // InTheNameOfAllah

        int cnt = 0;
    while (scanf("%d", &n) != EOF) {
        cnt++;
        for (int i = 0; i < n; i++) 
            scanf("%s", s[i]);
        

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                visited[i][j] = false;
            
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && s[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", cnt, ans);
    }
    return 0;
}