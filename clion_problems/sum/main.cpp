#include <iostream>
using namespace std;
int main() {
    cout<<"please enter a number :"<<endl;
    int n=5;
    cin>>n;
    int i=1;
    int sumO=0,sumE=0;
    while (i<=n)
    {
        if (i%2==0)
            sumE +=i;
        else
            sumO +=i;
    i++;
    }
    cout<<"odd sum equals: "<<sumO<<endl;
    cout<<"even sum equals: "<<sumE<<endl;
    return 0;
}