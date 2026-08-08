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
    test {
        int n;
        double d, h;
        cin >> n >> d >> h;
        double y[n];
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }

        double space = d * h / 2;
        double total_space = space;

        for (int i = 1; i < n; ++i) {
            if (y[i - 1] + h > y[i]) {
                double height = y[i - 1] - y[i] + h;
                double anything = h / height;
                double base = d / anything;
                double deleted_space = (base * height / (2));
                total_space += (space - deleted_space);
            } else total_space += space;
        }
        cout << fixed << setprecision(7) << total_space << endl;
    }
    return 0;
}