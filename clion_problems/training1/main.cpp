#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int x,n;
    cin>>x;
    int y =x,i;
    for ( i = 1; i <=100; ++i) {
        y /=10;
        if (y==0)
          break;  }
    cout<<i<<endl;
    int r=0;
    n=i;
    for (int j = 0; j <n ; ++j) {
        i--;
        y= x/pow(10,i);
        x= fmod(x,pow(10,i));


        r =r+ (y*pow(10, j));

    }cout<<r;


    return 0;
}
