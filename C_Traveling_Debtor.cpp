#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    vector<bool>mp(n+1,0);
    vector<int> graph[n + 1];
    vector<pair<int, int>> distDept(n + 1, {1e9, 1e9});
    deque<pair<pair<int, int>, int>> q; // dept , dist , child
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        mp[x]=1;
    }
    
    while (m--) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    
   
    distDept[1] = {mp[1], 0};
    q.push_front(make_pair(make_pair(mp[1], 0), 1));
    while (!q.empty()) {
        auto z=q.front();
        q.pop_front();
        pair<int,int> cur= z.first;
        int node=z.second;
        if(cur>distDept[node]) continue;
        for ( int child : graph[node]) {
            pair<int,int> next ={cur.first+mp[child],cur.second+1};
            if (next< distDept[child]) {
                distDept[child]=next;
                
              mp[child]?  q.push_back({next, child}):
                q.push_front({next, child});
            }
        }
    }

    cout << distDept[n].first << ' ' << distDept[n].second;

    return 0;
}
