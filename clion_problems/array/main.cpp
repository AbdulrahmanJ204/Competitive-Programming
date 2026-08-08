#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"please enter elements number :"<<endl;
    cin>>n;
    int arr[100];
    cout<<"please enter element:"<<endl;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<"your elements:\n";
    for (int j = 0; j < n; ++j) {
        cout<<arr[j]<<endl;
    }
    int  b=arr[0];
    for (int k=0; k < n ; ++k) {
        if(b<arr[k])
            b=arr[k];
    }
    cout<<"the biggest number is :"<<b<<endl;
    int a;
    cout<<"search for number :"<<endl;
    cin>>a;
    for (int l = 0; l <n ; ++l) {
        if (a == arr[l]) {
            cout << "found : " << l << endl;
        } else if ((a != arr[l]) && (l == n - 1))
            cout << "not found" << endl;
    }   // واجب اضافة وحذف عنصر
        int ad;

        do{
     cout<<"\n1. add element.\n2. delete element\n0. exit.\n";
    cin>>ad;
    switch(ad) {
        case 0:
            cout << "thanks. " << endl;
            break;
        case 1:
            int address;
            cout<<"please choose enter the address: "<<endl;
            cin>>address;
            for (int i = n; i >= address; --i)
            { arr[i+1]=arr[i];
            if (i==address)
            {cout<<"please add a number : "<<endl;
                cin>>arr[i];
                cout<<"your elements:\n";
                for (int j = 0; j < n; ++j) {
                    cout<<arr[j]<<endl;
                }}}
            break;
                case 2:
                    int add;
                    cout <<"please enter the address:"<<endl;
                cin>>add;
                for (int i = add; i <= n; ++i) {
                    arr[i] = arr[i + 1];
                    if (i == add) {
                        cout << "your elements:\n";
                        for (int j = 0; j < n; ++j)
                            cout << arr[j] << endl;
                    }
                }






    }}while(ad!=0);
    return 0;
}
