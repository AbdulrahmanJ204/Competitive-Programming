#include <iostream>
using namespace std;
#include <cstring>
int main() {
    string a;
    cin>>a;
    putchar(toupper(a[0]));
    cout<<a.substr(1,a.size())<<endl;
    return 0;
}
