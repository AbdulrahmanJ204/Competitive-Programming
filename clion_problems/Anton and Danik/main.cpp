#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin>>n;
    string battles;
    cin>>battles;
    int a=0,d=0;
    for (int i = 0; i <n ; ++i) {
        if(battles[i]=='A')
        a++;
        else
            d++;
    }
    if(a>d)
        cout<<"Anton"<<endl;
    else if(a<d)
        cout<<"Danik"<<endl;
    else
        cout<<"Friendship"<<endl;
    return 0;
}
