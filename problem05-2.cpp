#include <iostream>
#include <string> 
using namespace std;
#define ll long long
int readPositiveInt(string message) {
    cout << message << endl;
    int n = 0;
    do {
        cin >> n;
    } while (n <= 0); return n;
} 
void printReversedNumber(int n){
  // string s= to_string(n);
  // for (int i = s.size() - 1; i >= 0; i--)
    // cout<<s[i]<<'\n';
  while(n>0){
    cout<<n%10<<'\n';
    n/=10;
  }


}
int main() {
    // InTheNameOfAllah
      printReversedNumber(readPositiveInt("Enter a positive Number : "));
    return 0;
}