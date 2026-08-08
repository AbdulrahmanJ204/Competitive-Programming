#include <iostream>
using namespace std;
int main() {
   bool a;
    for (int i = 2; i < 101; ++i) {
        a=true;
        for (int n = 2; n <i ; ++n) {
            if(i%n==0)
            {
                a=false;
                break;

            }

        }
        if (a==true)
            cout<<i<<endl;
    }
    return 0;
}
