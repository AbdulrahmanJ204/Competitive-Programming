#include <iostream>
using namespace std;

int main() {
    int a[5][5];
    int one;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin>>a[i][j];
        }
    }
    bool found=false;//initial value
    int i,j;
    for ( i = 1; i <= 5; ++i) {
        for ( j = 1; j <= 5; ++j)
        {
            if (a[i-1][j-1]==1)
            {i=abs(3-i);
            j=abs(3-j);
            found=true;
                break;

            }
        }if (found)
            break;
    }
    cout<<i+j<<endl;
    return 0;
}
