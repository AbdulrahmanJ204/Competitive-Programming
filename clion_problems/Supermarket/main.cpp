#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int markets[5000][2];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin>>markets[i][j];
        }
    }
   long double a=markets[0][0],b=markets[0][1];
    long double price=m*a/b,min=price;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a=markets[i][0];
            b=markets[i][1];
            price=m*a/b;
            if(min>price && price>0.000001)
                min=price;
        }
    }

    cout<<setprecision(8)<<min<<endl;



    return 0;
}

 /* dont try to write less for loops , let it do 1 thing and write another one for the other thing;
  * try to declare variables after input */