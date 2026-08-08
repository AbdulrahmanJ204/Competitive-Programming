#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        int n;
        cin>>n;
        ll a[n];
        ll gc=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            gc=__gcd(a[i],gc);
        }
        if(gc>n) {
            cno;
            continue;
        }
        ll mintwogc=10e9;
        for (int j = 0; j <n ; ++j) {
            for (int i = j+1; i <n ; ++i) {
                mintwogc=min(mintwogc,__gcd(a[j],a[i]));
            }
        }
        if(mintwogc<=2)
            cyes;
        else
            cno;

    }
    return 0;
}




//#include <bits/stdc++.h>
//using namespace std;
//#define test  int t;cin>>t;while(t--)
//#define ll long long
//#define endl '\n'
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    test {
//        int n;
//        cin >> n;
//        ll a[n];
//        bool done = false;
//        map<ll,bool> b;
//        ll gc = 0;
//        ll mn_gc=0;
//        for (int i = 0; i < n; ++i) {
//            cin >> a[i];
//            b[i]=0;
//            if (a[i] == 1)
//                done = true;
//        }
//        if (done) {
//            cout << "YES" << endl;
//            continue;
//        }
//        for (int i = 0; i < n-1; ++i) {
//            for (int j = i+1; j < n; ++j) {
//                b[__gcd(a[i],a[j])]=true;
//            }
//        }
//
////        for (int i = 0; i < b.size(); ++i) {
////            cout<<b[i]<<' '<<i<<endl;
////        }
//        if(b[1]== true) {
//            cout << "YES" << endl;
//            continue;
//        }
//        if(b[2]==false) {
//            cout << "NO" << endl;
//            continue;
//        }
//        for (int i = 3; i < n; ++i) {
//            if(b[i]== true)
//                done=true;
//        }
//        if(!done)
//            cout<<"NO"<<endl;
//        else
//            cout<<"YES"<<endl;
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//    }
//    return 0;
//
//}