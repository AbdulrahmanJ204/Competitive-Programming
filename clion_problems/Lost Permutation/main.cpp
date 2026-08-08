#include <bits/stdc++.h>
using namespace std;
#define test  ll t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    test {
        ll m, s;
        cin >> m >> s;
        ll a[m];
        ll sum=0,finalsum=0;
        bool exist=true;
        for (ll i = 0; i < m; ++i) {
            cin>>a[i];
            finalsum+=a[i];
        }
        finalsum+=s;
        sort(a,a+m);
        sum=(a[0]-1)*(a[0])/2;
        for (int j = 0; j < m; ++j) {
             if(j<m-1) {
                 if(a[j]==a[j+1]) {
                     exist = false;
                     break;
                 }
                sum+=a[j];
                if(sum>=finalsum) {
                    exist = false;
                }
                while (a[j] + 1 < a[j + 1]) {
                    a[j]++;
                    sum += a[j];

                    if (sum >= finalsum)
                        exist = false;
                }
            }
            else if(j==m-1) {
                sum += a[j];
                a[j]++;

                if (sum == finalsum) {
                    exist = true;
                    break;
                } else if(sum>finalsum) {
                    exist = false;
                }
                else
                    while (sum < finalsum) {

                    sum+=a[j];
                    a[j]++;
                    if (sum == finalsum)
                        exist = true;
                    else if(sum>finalsum) {
                        exist = false;
                        break;
                    }
                }
            }
        }
        if(exist)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;}
