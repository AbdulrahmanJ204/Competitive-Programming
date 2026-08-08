#include <iostream>
using namespace std;
int main() {
            int a1,a;
            cout<<"please enter a normal number"<<endl;
            cin>>a1;
            a=a1;
    for (int i = a1-1; i >0; i--) {
        a *=i;

    }
    cout<<a1<<"!="<<a<<endl;
    return 0;
}
