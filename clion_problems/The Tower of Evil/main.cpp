#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    freopen("evil.in" , "r" , stdin) ;
    test {
        ll h,d,w;
        cin>>h>>w>>d;
        if(h==w)
        {
            if(d==w)
                cout << "Yes" << endl;
            else cout<<"No"<<endl;
            continue;
        }
        else if(h<w)
        {
            if(d==h%w)
                cout << "Yes" << endl;
            else cout<<"No"<<endl;
            continue;
        }
        else
        {
            ll dirc=h/w;
            ll position=(h-1)%(w-1);
            if(dirc%2==0)
            {
                if(d==position+1)
                    cout << "Yes" << endl;
                else cout<<"No"<<endl;
            } else
            {
                if(d==(w-position))
                    cout << "Yes" << endl;
                else cout<<"No"<<endl;
            }







        }




    }
    return 0;
}