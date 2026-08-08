#include <iostream>
#include <math.h>
using namespace std;
int main() {int a;
    do
    {cout <<"\nplease choose a number : \n1. percentage area \n2. print:\"hello world\" \n3. squre root\n0. exit "<<endl;
    int b;
    float l,w;
    cin>>a;
        switch (a) {
            case 1 :
                cout << "please enter length:";
                cin>>l;
                cout << "please enter wide :";
                cin >>w;
                cout << "the percentage area = "<<l<<'*'<<w<<'='<<l*w<<endl;
                break;
            case 2 :
                cout<< "hello word"<<endl;
                break;

            case 3 :
                cout << "please enter a positive integer:";
                cin>> b;
                if (b<0)
                    cout << "there is no square root for negative numbers."<<endl;
                else
                    cout << "the square root of "<<b<<" is :"<<sqrt(b)<<endl;
                break;

            case 0 : cout<< "exit"<<endl;
        }


    } while (a!=0);

    return 0;
}
