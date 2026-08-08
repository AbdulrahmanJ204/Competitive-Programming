#include <iostream>
using namespace std;
int main() {
    long long n,counter=0;
    cin>>n;

    while(n>0){
        if(n%10==4 || n%10==7) {
            counter++;
        }

        n =n/10;
        }
    if(counter==7 || counter==4 )
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
