#include <iostream>
using namespace std;
int main() {
    int x;
    cout << "please enter a number: "<<endl;
    cin>>x;
    if (x==1)
        cout<<"non-prime number.";
    for (int i = 2; i <=x ; ++i) {
        if((x%i==0)&&(x!=i)) {
            cout << "non-prime number. " << endl;
          break;
        }
        else if(i==x)
                cout << "prime number." << endl;
    }
    return 0;
}
