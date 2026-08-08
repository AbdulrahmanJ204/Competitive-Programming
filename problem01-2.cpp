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
/* void printSpaces(int x, int a) {
    int n = to_string(x).size();
    for (int i = 0; i < a - n; i++)
        cout << ' ';
}
void solve() {
    for (int i = 0; i < 10; i++)
        cout << "         " << i + 1;
    cout << "\n-------------------------------------------------------------------------------------------------------\n";
    for (int i = 1; i <= 10; i++) {
        cout << " " << i; printSpaces(i,5); cout << "|  ";
        for (int j = 1; j < 11; j++) {
            cout << i * j;
            printSpaces(i * j,10);
        }
        cendl;
    }

    return;
} */
void printHeader(){
  for (int i = 0; i < 10; i++)
  {
    cout<<"\t"<<i+1;
  }
  
}
void separator(int i){
  i < 10? cout<<"    | " : cout<<"   | ";
}
void solve(){

printHeader();
cout << "\n------------------------------------------------------------------------------------------------\n";
for (int i = 0; i < 10; i++)
{
  cout<<' '<<i+1;
  separator(i+1);
  for (int j = 0; j < 10; j++)
  {
    cout<<(i+1)*(j+1)<<'\t';
  }
  cendl;
}



}
int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}