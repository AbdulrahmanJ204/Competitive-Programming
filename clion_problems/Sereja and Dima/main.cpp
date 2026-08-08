#include <iostream>
using namespace std;
int main() {
    int n,a[1000];
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int first=0,last=n-1;
    bool sereja=true;
    int sereja_score=0,dima_score=0;
    for (int j = 0; j < n; ++j) {
        int temp_max;
        if(a[first]>a[last])
        {
            temp_max=a[first];
            first++;
        }
        else {
            temp_max=a[last];
            last--;
        }
        if(sereja)
        {
            sereja_score+=temp_max;
            sereja=false;
        }
        else
        {
            dima_score+=temp_max;
            sereja=true;
        }

    }
    cout<<sereja_score<<" "<<dima_score<<endl;
    return 0;
}
