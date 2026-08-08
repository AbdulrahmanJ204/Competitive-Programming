#include <iostream>
#include <string>
using namespace std;
int main() {
    string name;
    cin >> name;
    int sameNumber = 0;
    int size = name.size();
    char found[100];
    found[0] = name[0];
    bool f1 = false;
    int difNumbers=0;
    for (int i = size - 1; i >= 0; --i) {

        for (int j = 0; j < i; ++j) {
            if (name[i] == name[j])
                f1 = true;
        }
        if (f1) {
            f1 = false;
            continue;
        }
        else {
            found[i] = name[i];
            difNumbers++;
        }
    }
    if(difNumbers%2==0)
        cout<<"CHAT WITH HER!"<<endl;
        else
            cout<<"IGNORE HIM!"<<endl;
    return 0;
}
