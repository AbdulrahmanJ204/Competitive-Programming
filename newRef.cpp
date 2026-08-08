// unique
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define InTheNameOfAllah ios_base::sync_with_stdio(0);cin.tie(0);

freopen("text.in", "r", stdin);
freopen("text.out", "w", stdout);

// Graph Theory
// dfs
vector<int> graph[z];
bool visited[z];
void dfs(int node) {
    visited[node] = true;
    for (auto child : graph[node])
        if (!visited[child])
            dfs(child);
    // we can use timeIn[N] , and a global timer to check for cycles
}
// it might be useful to also compute the entry and exit times and vertex color.
vector<int> color;
vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v)
{
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

// find tree diameter (longest path)
// just reset first and mx , and make dfs from "first".
int mx = 0, first = -1, last = -1;
bool vis[z];
void dfs(int i, int cnt) {
    vis[i] = true;
    for (auto child : adj[i])
        if (!vis[child.first])
            dfs(child.first, cnt + child.second);

    if (cnt > mx)
        first = i, mx = cnt;
}

void bfs(int src) {
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto child : graph[node])
            if (!visited[child]) {
                visited[child] = true;
                parent[child] = node; // save path;
                q.push(node);
            }
    }
}
// Print Path
if (!visited[u]) {
    cout << "No path!";
} else {
    vector<int> path;
    for (int v = u; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}

void bfs01() {
    // 01-BFS
    int n;
    vector<pair<int, int>> graph[n]; // pair <node, weight>
    vector<int> dist(n, INF);        // could be <pair<int,int> if we have some constrains
    dist[s] = 0;
    deque<int> q; // could be pair
    q.push_front(s);
    while (!q.empty()) {
        int parent = q.front();
        q.pop_front();
        for (auto child : graph[parent]) {
            int u = child.first;
            int w = child.second;
            if (dist[parent] + w < dist[u]) {
                dist[u] = dist[parent] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}

// topo sort with BFS
vector<int> topo(int N, vector<int> adj[]) {
    queue<int> q;
    vector<int> inDegree(N, 0);
    for (int i = 0; i < N; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return topo;
}

// topo sort dfs
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

// Dijkstra:
const int INF = 1000000000;
vector<vector<pair<int, int>>> graph;

void dijkstra(int s, vector<int> &d, vector<int> &p) {
    int n = graph.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == INF)
            break;
        u[v] = true;
        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
vector<int> restore_path(int s, int t, vector<int> const &p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

// dijkstra
void dijkstra(int s)
{
    d[s] = 0;
    priority_queue<pll> q;
    q.push({-0, s});
    while (!q.empty())
    {
        pair<int ,int> v = q.top();
        q.pop();
        v.first *= -1;
        if (d[v.second] < v.first)
            continue;
        for (int i = 0; i < g[v.second].size(); i++)
        {
            ll to = g[v.second][i].first;
            ll len = g[v.second][i].second;
            if (d[to] > d[v.second] + len)
            {
                d[to] = d[v.second] + len;
                p[to] = v.second;
                q.push({-d[to], to});
            }
        }
    }
}
// ford warshale algorithm
// to know all shortest paths with positive wights
for (int k = 0; k < n; ++k)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
// find K-th Ancestor using binary lifting
void dfs(int u, int p = 0, int d = 0)
{
    depth[u] = d;
    up[0][u] = p;
    for (int i = 0; i < g[u].size(); i++)
        if (g[u][i] != p)
            dfs(g[u][i], u, d + 1);
}
void Buildup(int root)
{
    dfs(root);
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];
}
int FindKthAncestor(int u, int k)
{
    if (depth[u] < k || k < 0)
        return -1;
    for (int i = 19; i >= 0; i--)
        if (k & (1 << i))
            u = up[i][u];
    return u;
}

// LCA
int Lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    u = FindKthAncestor(u, depth[u] - depth[v]);
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
        if (up[i][u] != up[i][v])
        {
            u = up[i][u];
            v = up[i][v];
        }
    return up[0][u];
}

// Euler tour
int tin[N], tout[N], timer;
void dfs(int u = 1, int p = 0)
{
    tin[u] = ++timer;
    for (int i = 0; i < g[u].size(); i++)
        if (g[u][i] != p)
            dfs(g[u][i], u);
    tout[u] = timer; // or tout[u]=++timer;
}

// check if u ancestor of v using euler tour
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// Lca using euler tour
void dfs(int u = 1, int p = 1)
{
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < 20; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int i = 0; i < g[u].size(); i++)
        if (g[u][i] != p)
            dfs(g[u][i], u);
    tout[u] = ++timer;
}
int Lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = 19; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

// Calculate length from node to another
int Length(int u, int v)
{
    int lca = Lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}


// Count the number of paths that pass through a node in a tree

vector<vector<ll>>tree(1e5+10);
vector<ll> vis(1e5+10);
vector<ll> porduct(1e6+10);
int dfs(int node);
vector<ll> nodes(1e6+10);
vector<ll> ans(1e6+10);
vector<ll> num_of_pathes(1e6+10);
int n;
int main(){
    cin>>n;
    forn(int i=0;i<n-1;i++){
        ll u,v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1);

    int t;
    cin>>t;
    forn(int i=0;i<t;i++){
        ll node; cin>>node;
        cout<<"number of pathes through "<<node<<endl;
        cout<<ans[node]+n-1<<endl;
    }
}
int dfs(int node){
    if(vis[node]) return 0 ;
    vis[node]=1;
    ll prod=0;
    ll sum=0;
    for(auto l:tree[node]){
        ll tmp=dfs(l);

        if(tmp!=0){
            prod+=sum*tmp;
        }
        sum+=tmp;
    }
    porduct[node]=prod;
    nodes[node]=sum;
    ans[node]=porduct[node]+(n-1-nodes[node])*nodes[node];
    num_of_pathes[node]=ans[node]+n-1;
    return 1+sum;

}

// dsu on trees
map<int, int> *cnt[maxn];
void dfs(int v, int p){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p){
           dfs(u, v);
           if(sz[u] > mx)
               mx = sz[u], bigChild = u;
       }
    if(bigChild != -1)
        cnt[v] = cnt[bigChild];
    else
        cnt[v] = new map<int, int> ();
    (*cnt[v])[ col[v] ] ++;
    for(auto u : g[v])
       if(u != p && u != bigChild){
           for(auto x : *cnt[u])
               (*cnt[v])[x.first] += x.second;
       }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

}


struct DSU {
    int cnt;
    vector<int> p, sz;

    DSU(int n) : cnt(n), sz(n + 1, 1), p(n + 1) {
        for (int i = 0; i <= n; i++)
            p[i] = i;
    }

    int find(int a) {
        return (p[a] == a ? a : find(p[a]));
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            cnt--;
            if (sz[a] > sz[b])
                swap(a, b);
            sz[b] += sz[a];
            sz[a] = 0;
            p[a] = p[b];
        }
    }
};

// Math & number Theory
// extended gcd
ExtendedGcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ExtendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// GCD and LCM
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }
//------------------------------------------------------------//
// ax+by=c , one solutoin
pair<int, int> extendedEuclidean(int a, int b) {
    if (b == 0) {
        return make_pair(1, 0);
    }
    int x, y;
    tie(x, y) = extendedEuclidean(b, a % b);
    return make_pair(y, x - (a / b) * y);
}
pair<int, int> solveLinearDiophantine(int a, int b, int c) {
    int gcd = abs(__gcd(a, b));
    if (c % gcd != 0) {
        return make_pair(INT_MIN, INT_MIN);
    }
    int x0, y0;
    tie(x0, y0) = extendedEuclidean(a, b);
    int x = x0 * (c / gcd);
    int y = y0 * (c / gcd);
    return make_pair(x, y);
}

// Divisors And Factorization
vector<vector<int>>
divisorSieve(int N) {
    vector<vector<int>> divisors(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }

    return divisors;
}
//------------------------------------------------------------//
vector<vector<int>> sieveFactorization(int N) {
    vector<vector<int>> factors(N + 1);
    for (int i = 2; i <= N; ++i) {
        if (factors[i].empty()) { // If i is prime
            for (int j = i; j <= N; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    // O N*logN
    return factors;
}
//------------------------------------------------------------//

vector<long long> primeFactors(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

//------------------------------------------------------------//

int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

//------------------------------------------------------------//
const ll maxn = 1e6;
vector<bool> primes(maxn + 1, true);
void sieve(ll n) {
    primes[0] = primes[1] = 0;
    for (ll p = 2; p <= n; p++)
        if (primes[p])
            for (ll i = p * p; i <= n; i += p)
                primes[i] = 0;
}

bool isprime(ll x) {
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

vector<ll> divisor(ll x) {
    vector<ll> v;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x / i)
                v.push_back(x / i);
        }
    }
    return v;
}
// Sieve: Number of prime factors
for (ll i = 0; i < M; i++) {
    sieve[i] = 0;
}
for (ll i = 2; i < M; i++) {
    if (!sieve[i]) {
        for (ll j = i; j < M; j += i) {
            sieve[j]++;
        }
    }
}

// check number if prime in log n
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter = 5)
{ // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

//   Sum, Evens, Odds, power, Mod
int EvenSum_1_to_n(int n) {
    if (n % 2 == 1)
        n--;
    return (n * (n + 2) / 4);
}
int OddSum_1_to_n(int n) {
    if (n % 2 == 0)
        n--;
    return ((n + 1) * (n + 1) / 4);
}
int sum_in_range(int lower, int upper) {
    return (upper - lower + 1) * (lower + upper) / 2;
}
int OddSum_in_range(int left, int right) {
    if (left % 2 == 0)
        left++;
    if (right % 2 == 0)
        right--;
    return ((right + 1) / 2) * ((right + 1) / 2) - ((left + 1) / 2) * ((left + 1) / 2) + left;
}
int EvenSum_in_range(int left, int right) {
    if (left % 2 == 1)
        left++;
    if (right % 2 == 1)
        right--;
    return right / 2 * (right / 2 + 1) - ((left - 1) / 2) * (((left - 1) / 2) + 1);
}
// Sum of the squares of the first n natural numbers
long long sum_of_squares(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}
int sum_1_to_n(int n) {
    return (n * (n + 1) / 2);
}
int sum_in_range(int lower, int upper) {
    return (upper - lower + 1) * (lower + upper) / 2;
}
// Compute the number of digits in a number
int number_of_digits(long long n) {
    return n > 0 ? (int)log10(n) + 1 : 1;
}
//_____________MOD_______________

// divison mod
long long fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}
int mod = 1e9 + 7;
ll sum(ll x, ll y) { return (x % mod + y % mod) % mod; }

ll sub(ll x, ll y) { return (x % mod - y % mod + mod) % mod; }

ll mul(ll x, ll y) { return (x % mod * y % mod) % mod; }

long long fastPower(ll base, ll exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = mul(result, base) % mod;
        }
        base = mul(base, base) % mod;
        exponent /= 2;
    }
    return result % mod;
}

int inv_mod(int a) {
    return fastpower(a, mod - 2, mod);
}

ll div(ll a, ll b) { return a * inv_mod(b) % mod; }

// ------------------Counting principals--------------------

int MOD = 1e9 + 7;
int Z = 1e5;
ll pow(ll x, ll n, ll mod) {
    x %= mod;
    ll res = 1;
    while (n) {
        if (n % 2) {
            res = res * x % mod;
        }
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

ll inverse_mod(ll x, ll mod) {
    x %= mod;
    return pow(x, mod - 2, mod);
}

ll fact[Z], inv[Z];
void pre() {
    fact[0] = 1;
    inv[0] = inverse_mod(fact[0], MOD);
    for (ll i = 1; i < Z; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = inverse_mod(fact[i], MOD);
    }
}

ll nCr(ll n, ll r) {
    if (n < r)
        return 0;
    return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}

ll nPr(ll n, ll r) {
    if (n < r)
        return 0;
    return fact[n] * inv[n - r] % MOD;
}

// All subsets Of vector :

vector<vector<int>> v;
vector<int> temp;
void fun(int index) {
    for (int i = index; i < n; i++) {
        temp.push_back(a[i]);
        fun(i + 1);
    }
    v.push_back(temp);
    temp.pop_back();
}

vector<int> combination;
int n = 20, m = 4, cnt = 0;
void get_combination(int i = 0, int last_val = 0) {
    if (i == m) {
        cnt++;
        // can print comb here
        return;
    }
    for (int j = last_val + 1; j <= n; j++) {
        combination.push_back(j);
        // Think: dynamically create one more loop
        get_combination(i + 1, j);
        combination.pop_back();
    }
}

void inclusion_exclusion(int k) {
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        ll cur = 0, cnt = 0;
        // ll mnX = n + 1, mnY = m + 1, mxX = 0, mxY = 0;
        for (int bit = 0; bit < k; bit++) {
            if (!(mask & (1 << bit)))
                continue;
            cnt++;
            // do something (maybe change value of cur)
        }
        // cur= something;
        ll sign = cnt % 2 ? 1 : -1;
        ans += sign * cur;
    }
}

// i dont know what should i name this :-)

// previous greater element , to return indices , check second version.
// TODO : add complexity to functions.

void prevGreater(int arr[], int n) {
    stack<int> s;
    s.push(arr[0]);
    cout << "-1, ";
    for (int i = 1; i < n; i++) {

        while (s.empty() == false && s.top() < arr[i])
            s.pop();
        s.empty() ? cout << "-1, " : cout << s.top() << ", ";

        s.push(arr[i]);
    }
}
vector<int> prevGreater2(int arr[], int n) {
    // Create a stack and push index of first element
    // to it
    stack<pair<int, int>> s;
    s.push({arr[0], 1});

    vector<int> v;
    // Previous greater for first element is always -1.
    v.push_back(0);

    // Traverse remaining elements
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top().first < arr[i])
            s.pop();
        s.empty() ? v.push_back(0) : v.push_back(s.top().second);
        s.push({arr[i], i + 1});
    }
    return v;
}

// ______________Geometry_____________

// i think the name is Ecu.... distance
ll dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}

// Manhatan distance i think:

ll M_dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// rotate point given the angle
struct Point {
    double x, y;
};
void rotate(Point &p, double angle) {
    double x_new = p.x * cos(angle) - p.y * sin(angle);
    double y_new = p.x * sin(angle) + p.y * cos(angle);
    p.x = x_new;
    p.y = y_new;
}
// calculates the angle between line and X Axis
double calculateAngleWith_X_Axis(Point p1, Point p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}
double calculateAngleWith_Line(Point p1, Point p2, Point r1, Point r2) {
    double firstAngle = calculateAngleWith_X_Axis(p1, p2);
    double secondAngle = calculateAngleWith_X_Axis(r1, r2);
    return secondAngle - firstAngle;
}
// ______________IDK_____________

// could be array
string LCS(string &a, &string b) {

    int dp[3010][3010];
    int n = a.size(), m = b.size();
    assign2(dp, n + 1, m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string path = "";
    int i = n, j = m;
    while (i + j > 0) {
        if (i > 0 && dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            i--, j--;
            if (a[i] == b[j])
                path += a[i];
        }
    }
    reverse(all(path));
    return path;
}

int lengthOfLIS(vector<int> &nums) {
    // N * logN
    // Binary search approach
    int n = nums.size();
    vector<int> ans;

    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

//------------Orderd Set, Unorder_set , unorderd_map ,cHash-----------------
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
const double PI = acos(-1.0);

struct chash {
    const uint64_t C = uint64_t(2e18 * PI) + 71;
    const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    size_t operator()(uint64_t x) const {
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
// less to set and less_equal to multiset
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class A, class B> using cmap = unordered_map<A, B, chash>;
template <class A, class B> using cset = unordered_set<A, B, chash>;
template <class A, class B> using ht = gp_hash_table<A, B, chash>;

int main() {
    
    o_set<int>se;
    se.insert(1);
    se.insert(2);
    cout << *se.find_by_order(0) << endl; ///k th element
    cout << se.order_of_key(2) << endl; ///number of elements less than k
    s.erase(s.find_by_order(s.order_of_key(a[i])));
    
    o_map<int, int>mp;
    mp.insert({1, 10});
    mp.insert({2, 20});
    cout << mp.find_by_order(0)->second << endl; ///k th element
    cout << mp.order_of_key(2) << endl; ///number of first elements less than k

    cmap<int, int> mp;
    ht<int, int> t;

    return 0;
}
// some DS
template <typename T, T (*op)(T, T)>
struct SparseTable {
    vector<vector<T>> ST;
    int n;
    SparseTable(const vector<T> &a) {
        n = a.size();
        int maxLog = 32 - __builtin_clz(n);
        ST.resize(n, vector<T>(maxLog));
        for (int i = 0; i < n; i++)
            ST[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) - 1 < n; i++)
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    }

    T query(int l, int r) {
        int len = r - l + 1;
        int k = (31 ^ __builtin_clz(len));
        return op(ST[l][k], ST[r - (1 << k) + 1][k]);
    }
};

int op(int a, int b) {
    return min(a, b);
}
SparseTable<int, op> s(v);
// base index is 0
#define log(x) (31 ^ __builtin_clz(x))
template <typename T>
struct Sparse {
    int N, LOGN;
    vector<vector<T>> sp;
    Sparse(int n) {
        N = n;
        LOGN = 1 + log(n);
        sp.resize(LOGN);
        for (int i = 0; i < sp.size(); i++) {
            sp[i].resize(N);
        }
    }
    void build(vector<ll> &A) {
        for (int i = 0; i < N; i++)
            sp[0][i] = A[i];
        for (int j = 1; j < LOGN; j++) {
            for (int i = 0; i + (1 << j) - 1 < N; i++) {
                sp[j][i] = min(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int k = log(r - l + 1);
        return min(sp[k][l], sp[k][r - (1 << k) + 1]);
    }
};

#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx
ll seg_sz;
// base index is 1
template <typename T>
struct SEG {
    vector<T> tree;
    T neutral = 0;

    int size;
    SEG(int n) : size(1) {
        seg_sz = n;
        while (size <= n)
            size *= 2;
        tree.assign(2 * size, neutral);
    }

    T merge(T a, T b) {
        return a + b;
    }

    T build(vector<ll> &a, int x = 1, int lx = 1, int rx = seg_sz) {
        // put value in node
        if (lx == rx)
            return tree[x] = a[lx];
        return tree[x] = merge(build(a, lft), build(a, rt));
    }

    T set(int i, ll v, int x = 1, int lx = 1, int rx = seg_sz) {
        if (rx == lx) {
            // put value in node
            tree[x] = v;
            return tree[x];
        }
        int mid = (lx + rx) / 2;
        if (i <= mid)
            set(i, v, lft);
        else
            set(i, v, rt);

        return tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    T query(int l, int r, int x = 1, int lx = 1, int rx = seg_sz) {
        if (r < lx || rx < l)
            return neutral;
        if (l <= lx && rx <= r)
            return tree[x];
        return merge(query(l, r, lft), query(l, r, rt));
    }
};
#define lft 2 * x, lx, (lx + rx) / 2
#define rt 2 * x + 1, (lx + rx) / 2 + 1, rx
int seg_sz;
template <typename T>
struct SEG {
    vector<T> tree, lazy;
    T neutral = 0;

    int size;
    SEG(int n) : size(1) {
        seg_sz = n;
        while (size <= n)
            size *= 2;
        tree.assign(2 * size, neutral);
        lazy.assign(2 * size, neutral);
    }

    T merge(T a, T b) {
        return a + b;
    }

    T build(vector<ll> &a, int x = 1, int lx = 1, int rx = seg_sz) {
        if (lx == rx)
            return tree[x] = a[lx];
        return tree[x] = merge(build(a, lft), build(a, rt));
    }

    void push(int x, int lx, int rx) {
        if (lazy[x] == 0 || lx == rx)
            return;
        int mid = (lx + rx) / 2;
        tree[2 * x] = (mid - lx + 1) * lazy[x];
        tree[2 * x + 1] = (rx - (mid + 1) + 1) * lazy[x];
        lazy[2 * x] += lazy[x];
        lazy[2 * x + 1] += lazy[x];
        lazy[x] = 0;
    }

    T upd(int l, int r, ll val, int x = 1, int lx = 1, int rx = seg_sz) {
        if (r < lx || rx < l)
            return tree[x];
        if (l <= lx && rx <= r) {
            tree[x] += val * (rx - lx + 1);
            lazy[x] += val;
            return tree[x];
        }
        push(x, lx, rx);
        return tree[x] = merge(upd(l, r, val, lft), upd(l, r, val, rt));
    }

    T set(int i, int v, int x = 1, int lx = 1, int rx = seg_sz) {
        if (rx == lx) {
            tree[x] = v;
            return tree[x];
        }
        int mid = (lx + rx) / 2;
        if (i <= mid)
            set(i, v, lft);
        else
            set(i, v, rt);

        return tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    T query(int l, int r, int x = 1, int lx = 1, int rx = seg_sz) {
        if (r < lx || rx < l)
            return neutral;
        if (l <= lx && rx <= r)
            return tree[x];
        push(x, lx, rx);
        return merge(query(l, r, lft), query(l, r, rt));
    }
};
// Minimum spanning tree (MST)

const int N = 1e5; // max value to number of nodes

vector<pair<int, int>> MST[N];
vector<pair<pair<int, int>, int>> Edges;
int n, m;
ll cost;

void Kruskal()
{
    DSU dsu(n);
    vector<pair<pair<int, int>, int>> edges;

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> u >> v >> w;
        edges.push_back({{w, u}, v});
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        w = edges[i].first.first;
        u = edges[i].first.second;
        v = edges[i].second;
        if (dsu.getParent(u) != dsu.getParent(v))
        {
            Edges.push_back({{u, v}, w});
            MST[u].push_back({v, w});
            MST[v].push_back({u, w});
            cost += 1ll * w;
            dsu.union_(u, v);
        }
    }
}

//================================================================================================

// ternary search

double ternary_search(double l, double r)
{
    for (int i = 0; i < 1000; i++)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); // evaluates the function at m1
        double f2 = f(m2); // evaluates the function at m2
        if (f1 < f2)       //(f1 > f2) if i want min
            l = m1;
        else
            r = m2;
    }
    return f(l); // return the maximum of f(x) in [l, r]
}

