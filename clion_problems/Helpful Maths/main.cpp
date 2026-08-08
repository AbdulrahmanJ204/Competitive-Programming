#include <iostream>
#include <string>


using namespace std;
int main() {
    string a;
    cin>>a;
    int size = a.size();
    for (int j = 0; j < size; ++j) {

    for (int i = 0; i <size-2 ; i=i+2) {
        if(a[i]>a[i+2])
            swap(a[i],a[i+2]);
    }}
    cout<<a<<endl;
    return 0;
}
