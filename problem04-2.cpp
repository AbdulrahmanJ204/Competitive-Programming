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

int readPositiveInt(string message) {
    cout << message << endl;
    int n = 0;
    do {
        cin >> n;
    } while (n <= 0); return n;
}
bool isPerfect(int n) {
  int sum = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            sum += i;
    return sum == n;
}
void printPerfectFrom1ToN(int n){
    for (int i = 1; i <=n; i++)
      if(isPerfect(i)) cout<<i<<endl;
}
int main() {
    // InTheNameOfAllah
    printPerfectFrom1ToN(readPositiveInt("Enter a positive int : "));
    return 0;
}