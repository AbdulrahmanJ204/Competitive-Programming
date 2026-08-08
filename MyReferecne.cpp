#include <bits/stdc++.h>
#define ll long long
using namespace std;
// unique
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));

// Graph Theory
// TODO : add LIS and how to store lines using  m and c (y= mx + c) (L_Longue Lizard problem and another one in a gym name is Power Transmisson i guess )
// TODO : add LCS code.
const int z = 0; // number of vertices (nodes)
vector<int> graph[z];
bool visited[z];
void dfs(int node) {
    visited[node] = true;
    for (auto child : graph[node])
        if (!visited[child])
            dfs(child);
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

class dfsWithTime {
    // Another DFS with Time.
    vector<vector<int>> graph; // adjacency list representation
    int n;                     // number of vertices

    vector<int> color;
    // 0-> not visited
    // 1-> visited
    // 2-> exit
    vector<int> time_in, time_out;
    int dfs_timer = 0;

    void dfs(int v) {
        time_in[v] = dfs_timer++;
        color[v] = 1;
        for (int u : graph[v])
            if (color[u] == 0)
                dfs(u);
        color[v] = 2;
        time_out[v] = dfs_timer++;
    }
} int parent[z];
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

void bfs2() {
    // BFS
    vector<vector<int>> graph; // adjacency list representation
    int n;                     // number of nodes
    int s;                     // source vertex
    queue<int> q;
    vector<bool> visited(n, -1);
    vector<int> d(n, 0), p(n, -1);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    // Print Path
    if (!visited[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
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

class DSU {

private:
    vector<int> p, size;
    bool pathCompress;

public:
    DSU(int n, bool pathCompress = true) {
        p.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            size[i] = 1;
        }
        this->pathCompress = pathCompress;
    }

    int find(int x) {
        if (x == p[x])
            return x;
        int y = find(p[x]);
        if (this->pathCompress)
            p[x] = y;
        return y;
    }

    void merge(int a, int b) {

        a = find(a);
        b = find(b);
        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        p[b] = a;
        size[a] += size[b];
        size[b] = 0;
    }

    int Size(int u) {
        return size[find(u)];
    }
};

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


template<typename T, T (*op)(T, T)>
struct SparseTable {
    vector<vector<T>> ST;
    int n;
    SparseTable(const vector<T>& a) {
        n = a.size();
        int maxLog = 32 - __builtin_clz(n);
        ST.resize(n, vector<T>(maxLog));
        for (int i = 0; i < n; i++) ST[i][0] = a[i];
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

int op(int a, int b){
    return min(a, b);
}
SparseTable<int, op> s(v);


// Math & number Theory
int gcd(int a, int b) {
    if (!b)
        return a;
    return (b, a % b);
}
// GCD and LCM
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }
//------------------------------------------------------------//
// functions to get the gcd and lcm for whole numbers in the array
int lcm(vector<int> &numbers) {
    return accumulate(numbers.begin(), numbers.end(), 1,
                      [](int x, int y) { return (x * y) / gcd(x, y); });
}

int gcd(vector<int> &numbers) {
    return accumulate(numbers.begin(), numbers.end(), 0,
                      [](int x, int y) { return gcd(x, y); });
}
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

//------------------------------------------------------------//
ll fastPower_base2(ll x) {
    return (ll)1 << x;
}
//------------------------------------------------------------//
ll countDivisions(ll n, ll d) {
    ll count = 0;
    while (n > 1 && n % d == 0) {
        n = n / d;
        count++;
    }
    return count;
}
//------------------------------------------------------------//
int fib(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}
void generateSubsets(int n) {
    for (int mask = 0; mask < (1 << n); ++mask)
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) {
                // Element i is in the subset
            }
}

//------------------------------------------------------------//
void decToBinary(int n) {
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
//------------------------------------------------------------//
// Function to multiply two matrices
vector<vector<ll>> multiplyMatrices(vector<vector<ll>> &A,
                                    vector<vector<ll>> &B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)

            for (int k = 0; k < n; k++)
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;

    return C;
}
vector<vector<ll>> matrixExponentiation(vector<vector<ll>> &A, ll n) {
    int size = A.size();
    vector<vector<ll>> result(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++)
        result[i][i] = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiplyMatrices(result, A);
        }
        A = multiplyMatrices(A, A);
        n /= 2;
    }
    return result;
}
ll fibonacciModulo(ll n) {
    if (n == 0)
        return 0;
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = matrixExponentiation(A, n - 1);
    return result[0][0];
}
// function to find th n fibonacci number with mod for n<=18

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

//------------Orderd Set Headers-----------------
#include <ext/pb_ds/assoc_container.hpp>
// Header files, namespaces,
// macros as defined above
using namespace __gnu_pbds;
// less to set and less_equal to multiset
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
// declare : ordered_set st ; st.insert(y);

// Code
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e6 + 10, MOD = (ll)1e9 + 7, OO = (ll)1e17 + 10;

void solve() {

    o_set<int> se;
    se.insert(1);
    se.insert(2);
    cout << *se.find_by_order(0) << endl; /// k th element
    cout << se.order_of_key(2) << endl;   /// number of elements less than k
    s.erase(s.find_by_order(s.order_of_key(a[i])));
}

// --------text input ------------
// freopen("text.in", "r", stdin);
// freopen("text.out", "w", stdout);

int main() {
    return 0;
}
// ____________Links________________
// https://oeis.org/A000045  // can use to find facts about series of number , Mostafa Saad.
// geoGebra for 2d represintation.
// https://csacademy.com/app/graph_editor/  // graph editor.

// AtCoder Library: https://codeforces.com/blog/entry/82400
//  cp-algorithms: https://cp-algorithms.com/
//  kactl: https://github.com/kth-competitive-pr...
//  Benq's library: https://github.com/bqi343/USACO
//  Colin Galen library: https://github.com/galencolin/cp-temp...
//  A cool online judge to test library code: https://judge.yosupo.jp/