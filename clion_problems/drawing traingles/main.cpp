#include <iostream>
using namespace std;
int main() {
    for (int i = 1; i <= 10; i+=2) //1
    {   for (int k = 9; k > i ; k-=2) {
            cout<<" ";

        }

        for (int j = 1; j <=i ; j++)  //j=
        {
            cout<<"*";

        }
        cout<<endl;
    }
    for (int i = 8; i >= 1; i-=2) //1
    {   for (int k = 9; k > i ; k-=2) {
            cout<<" ";

        }

        for (int j = 1; j <i ; j++)  //j=
        {
            cout<<"*";

        }
        cout<<endl;
    }
    return 0;
}
