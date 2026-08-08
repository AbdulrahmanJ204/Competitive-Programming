    #include <iostream>
    using namespace std;
    int main() {
       int n,h;
       cin>>n>>h;
       int p[1000];
       int width=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>p[i];
            if(p[i]>h)
                width+=2;
            else
                width++;
        }
        cout<<width<<endl;
        return 0;
    }
