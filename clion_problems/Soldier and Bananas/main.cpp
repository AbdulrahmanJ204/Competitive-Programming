#include <iostream>
using namespace std;
int main() {
    int k,n,w;
    cin>>k>>n>>w;
    int price=0,final;
    for (int i = 1; i <= w; ++i) {
        price += k*i;
    }
    final=price-n;
    if (final<=0)
        cout<<"0"<<endl;
    else
        cout<<final<<endl;
        return 0;
}
