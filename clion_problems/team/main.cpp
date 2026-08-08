#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[1000][3];
    int counter=0,solved=0;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            cin>>a[i][j];
        }
        for (int k = 0; k <3 ; ++k) {
            if (a[i][k]==1)
                counter++;
        }
        if (counter>=2)
            solved++;
        counter=0;
    }
    cout<<solved<<endl;

    return 0;
}
