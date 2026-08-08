#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        ll a[n];
        vector<pair<int,int>>sortedA;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            sortedA.push_back( make_pair(a[i],i));
        }
        sort(sortedA.begin(),sortedA.end());
        for (int j = 0; j < n; ++j) {
            int xor1=(a[j]^1);
            int xor2=(a[j]^2);
            int xor3=(a[j]^3);
            int idx1=j,idx2=j,idx3=j;
            int tidx1=lower_bound(sortedA.begin(),sortedA.end(),xor1)-sortedA.begin();
            if(tidx1<sortedA.size())
                idx1=(*lower_bound(sortedA.begin(),sortedA.end(),xor1)).second;
            // if(lower_bound(sortedA.begin(),sortedA.end(),xor2)!=sortedA.end())
                // idx2=(*lower_bound(sortedA.begin(),sortedA.end(),xor2)).second;
            // if(lower_bound(sortedA.begin(),sortedA.end(),xor3)!=sortedA.end())
                // idx3=(*lower_bound(sortedA.begin(),sortedA.end(),xor3)).second;

            // pair<long long,ll> XOR[]= {{xor1, idx1},
            //                             {xor2, idx2},
            //                             {xor3, idx3}};
            //   sort(XOR,XOR+3);
            //   if(XOR[0].first<a[j] && XOR[0].second>j)
            //       swap(a[j],a[XOR[0].second]);
            //   else if(XOR[1].first<a[j] && XOR[1].second>j)
            //           swap(a[j],a[XOR[1].second]);
            //   else if(XOR[2].first<a[j] && XOR[2].second>j)
            //       swap(a[j],a[XOR[2].second]);

        }
        for (int k = 0; k < n; ++k) {   
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
