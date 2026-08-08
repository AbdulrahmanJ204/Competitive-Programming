#include <iostream>
#include <string>
using namespace std;
int main() {
    string p;
    cin>>p;
    bool danger=false;
    for (int i = 0; i <p.size() ; ++i) {
        for (int j = 1; j <7 ; ++j) {
            if(p[i]==p[i+j])
            danger=true;
            else
            {danger=false;
            break;}
        }
        if(danger)
            break;
    }
    if(danger)
    cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
