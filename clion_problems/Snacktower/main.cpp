    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    int main() {
        int t;
        cin >> t;
        int a[t];
        int mx=0;

        priority_queue<int> q;
        for (int i = 0; i < t; ++i) {
            cin>>a[i];
            mx=max(mx,a[i]);

        }
        int suf[t+10];
        for (int i = 0; i < t + 10; ++i) {
            suf[i]=0;
        }
        suf[t-1]=a[t-1];
        for (int i = t-1; i >=0 ; --i) {

            suf[i]=max(suf[i+1],a[i]);
        }
//        for (int i = 0; i < t; ++i) {
//            cout<<suf[i]<<' ';
//        }cout<<endl;


        for (int i = 0; i < t; ++i) {
            if(a[i]<suf[i]) {
                cout << endl;
                q.push(a[i]);
            } else { q.push(a[i]);

                while (!q.empty()) {
                    cout << q.top() << ' ';
                    mx=q.top();
                    q.pop();
                    if(q.top()!=mx-1)
                        break;
                }

                cout<<endl;
            }
        }


        return 0;
    }
