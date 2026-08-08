#include <iostream>
#include <string>

using namespace std;
int main() {
  long long value[4];
    for (int i = 0; i < 4; ++i) {
        cin>>value[i];
    }
    string squares;
    cin>>squares;
    int sum=0;
    for (int j = 0; j < squares.size(); ++j) {
        for (int i = 0; i < 4; ++i) {
            int temp = squares[j]-48;
            if (i+1==temp)
              sum+=value[i];

        }

    }
    cout<<sum<<endl;
    return 0;
}
