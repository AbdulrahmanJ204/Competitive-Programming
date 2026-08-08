#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int counter=0;
    while(a<=b)
    { counter++;
        a *=3;
        b*=2;
    }
    cout<<counter<<endl;

    return 0;
}
