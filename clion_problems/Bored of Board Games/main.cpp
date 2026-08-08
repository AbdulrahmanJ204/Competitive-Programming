#include <bits/stdc++.h>
using namespace std;
#define test  int t;cin>>t;while(t--)
#define ll long long
#define endl '\n'
#define cendl cout<<endl
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define InTheNameOfAllah  ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    InTheNameOfAllah
    test {

        int Cr = 0, Cc = 0;
        int N, M, sum = 0;
        int i, j;
        cin >> N >> M;
        int Ac[M], Ar[N];
        int arr[N][M];
        for (i = 0; i < N; i++) {
            sum = 0;
            for (j = 0; j < M; j++) {
                cin >> arr[i][j];
                sum += arr[i][j];
            }
            if (sum < 0) {
                for (j = 0; j < M; j++)
                    arr[i][j] *= -1;
                Cr++;
                Ar[i] = i+1;
            } else
                Ar[i] = 0;
        }
        for (j = 0; j < M; j++) {
            sum = 0;
            for (i = 0; i < N; i++) {
                sum += arr[i][j];
            }
            if (sum < 0) {
                for (j = 0; j < M; j++)
                    arr[i][j] *= -1;
                Cc++;
                Ac[j] = j+1;
            } else
                Ac[j] = 0;
        }
        bool exist = true;
        for (i = 0; i < N; i++) {
            sum = 0;
            for (j = 0; j < M; j++) {
                sum += arr[i][j];
            }
            if (sum < 0) {
                exist = false;
                break;
            }
        }
        if(!exist) {
            cno;
            cout << 0 << endl << endl << 0 << endl << endl;
        } else {
            cyes;
            cout<<Cr<<endl;
            for (int k = 0; k < N; ++k) {
                if(Ar[k]>0)
                    cout<<Ar[k]<<' ';
            }cendl;
            cout<<Cc<<endl;
            for (int k = 0; k < N; ++k) {
                if(Ac[k]>0)
                    cout<<Ac[k]<<' ';
            }cendl;

        }
    }
    return 0;
}
