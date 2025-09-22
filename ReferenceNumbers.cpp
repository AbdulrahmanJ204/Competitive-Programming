
// ============================================================================
//                               CONSTANTS
// ============================================================================

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const double PI = acos(-1.0);
const int INF = 1000000000;

// ============================================================================
//                            MODULAR ARITHMETIC
// ============================================================================

ll sum(ll x, ll y) { return (x % MOD + y % MOD) % MOD; }
ll sub(ll x, ll y) { return (x % MOD - y % MOD + MOD) % MOD; }
ll mul(ll x, ll y) { return (x % MOD * y % MOD) % MOD; }

// Time: O(log exponent)
ll fastPower(ll base, ll exponent, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = mul(result, base);
        }
        base = mul(base, base);
        exponent /= 2;
    }
    return result;
}
// Time: O(log MOD)
ll inv_mod(ll a, ll mod = MOD) {
    return fastPower(a, mod - 2, mod);
}
ll div_mod(ll a, ll b) { return mul(a, inv_mod(b)); }

// ============================================================================
//                          COMBINATORICS & FACTORIALS
// ============================================================================

// Purpose: Precompute factorials and their modular inverses
// Time: O(MAXN) preprocessing, O(1) query

ll fact[MAXN], inv[MAXN];

void precomputeFactorials() {
    fact[0] = 1;
    inv[0] = inv_mod(fact[0]);
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = inv_mod(fact[i]);
    }
}

ll nCr(ll n, ll r) {
    if (n < r || r < 0)
        return 0;
    return mul(fact[n], mul(inv[n - r], inv[r]));
}

ll nPr(ll n, ll r) {
    if (n < r || r < 0)
        return 0;
    return mul(fact[n], inv[n - r]);
}

// ============================================================================
//                              NUMBER THEORY
// ============================================================================

// Time: O(log(min(a,b)))
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// Time: O(log(min(a,b)))
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Purpose: Extended Euclidean Algorithm - finds x,y such that ax + by = gcd(a,b)
// Time: O(log(min(a,b)))
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Purpose: Solve Linear Diophantine Equation ax + by = c
// Time: O(log(min(a,b)))
pair<ll, ll> solveLinearDiophantine(ll a, ll b, ll c) {
    ll g = abs(gcd(a, b));
    if (c % g != 0) {
        return make_pair(LLONG_MIN, LLONG_MIN);
    }
    ll x, y;
    extgcd(a, b, x, y);
    x *= (c / g);
    y *= (c / g);
    return make_pair(x, y);
}

// Purpose: Sieve of Eratosthenes - find all primes up to MAXN
// Time: O(n log log n)
vector<bool> is_prime(MAXN, true);
vector<ll> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Purpose: Segmented Sieve for large ranges - count primes up to n
// Time: O(n log log sqrt(n))
ll count_primes(ll n) {
    const ll S = 10000;

    vector<ll> primes;
    ll nsqrt = sqrt(n);
    vector<bool> is_prime(nsqrt + 2, true);
    for (ll i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    ll result = 0;
    vector<bool> block(S);
    for (ll k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        ll start = k * S;
        for (ll p : primes) {
            ll start_idx = (start + p - 1) / p;
            ll j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (ll i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

// Purpose: Prime factorization of a number
// Time: O(sqrt(n))
vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (ll d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Purpose: Sieve for factorization - precompute smallest prime factor for each number
// Time: O(n log log n) preprocessing
vector<vector<ll>> sieveFactorization(ll N) {
    vector<vector<ll>> factors(N + 1);
    for (ll i = 2; i <= N; ++i) {
        if (factors[i].empty()) {
            for (ll j = i; j <= N; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return factors;
}

// Purpose: Find all divisors of a number
// Time: O(sqrt(n))
vector<ll> getDivisors(ll n) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

// Purpose: Sieve to find all divisors for numbers 1 to N
// Time: O(n log n)
vector<vector<ll>> divisorSieve(ll N) {
    vector<vector<ll>> divisors(N + 1);
    for (ll i = 1; i <= N; ++i) {
        for (ll j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

// Purpose: Miller-Rabin Primality Test - probabilistic primality test
// Time: O(k log³ n) where k is number of iterations
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n, int iter = 5) {
    if (n < 4)
        return n == 2 || n == 3;
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

// Purpose: Euler's Totient Function - count numbers ≤ n that are coprime to n
// Time: O(sqrt(n))
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// DIVISIBILITY RULES & PROPERTIES:

// Sum of divisors formula: σ(n) where n = p1^a1 * p2^a2 * ... * pk^ak
// σ(n) = (p1^(a1+1) - 1)/(p1-1) * (p2^(a2+1) - 1)/(p2-1) * ... * (pk^(ak+1) - 1)/(pk-1)

ll sumOfDivisors(ll n) {
    ll result = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            result *= (fastPower(i, count + 1) - 1) / (i - 1);
        }
    }
    if (n > 1) {
        result *= (n + 1);
    }
    return result;
}

// Number of divisors: τ(n) where n = p1^a1 * p2^a2 * ... * pk^ak
// τ(n) = (a1+1) * (a2+1) * ... * (ak+1)

ll countDivisors(ll n) {
    ll result = 1;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            result *= (count + 1);
        }
    }
    if (n > 1) {
        result *= 2;
    }
    return result;
}

// Pick's Theorem: Area = Interior + Boundary/2 - 1
ll picksInterior(ll area, ll boundary) {
    return area - boundary / 2 + 1;
}

// Purpose: Count digits in a number
// Time: O(log n)
int countDigits(ll n) {
    return n > 0 ? (int)log10(n) + 1 : 1;
}

// Purpose: Sum of arithmetic sequence from l to r
// Time: O(1)
ll sumRange(ll l, ll r) {
    return (r - l + 1) * (l + r) / 2;
}

// Purpose: Sum of squares 1² + 2² + ... + n²
// Time: O(1)
ll sumSquares(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

// Purpose: Sum of even numbers from 1 to n
// Time: O(1)
ll evenSum1ToN(ll n) {
    if (n % 2 == 1)
        n--;
    return (n * (n + 2)) / 4;
}

// Purpose: Sum of odd numbers from 1 to n
// Time: O(1)
ll oddSum1ToN(ll n) {
    if (n % 2 == 0)
        n--;
    return ((n + 1) * (n + 1)) / 4;
}

ll evenSumInRange(ll left, ll right) {
    if (left % 2 == 1)
        left++;
    if (right % 2 == 1)
        right--;
    if (left > right)
        return 0;
    return (right / 2) * (right / 2 + 1) - ((left - 1) / 2) * (((left - 1) / 2) + 1);
}

ll oddSumInRange(ll left, ll right) {
    if (left % 2 == 0)
        left++;
    if (right % 2 == 0)
        right--;
    if (left > right)
        return 0;
    return ((right + 1) / 2) * ((right + 1) / 2) - ((left - 1) / 2) * ((left - 1) / 2);
}

// Purpose: Count how many times n is divisible by d
// Time: O(log n)
ll countDivisions(ll n, ll d) {
    ll count = 0;
    while (n > 1 && n % d == 0) {
        n /= d;
        count++;
    }
    return count;
}

// COUNTING THEOREMS:

// Stirling numbers of the second kind S(n,k): number of ways to partition n objects into k non-empty subsets
vector<vector<ll>> stirlingSecond(int n, int k) {
    vector<vector<ll>> S(n + 1, vector<ll>(k + 1, 0));
    S[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
        }
    }
    return S;
}

// Bell numbers: B(n) = sum of S(n,k) for k=0 to n
vector<ll> bellNumbers(int n) {
    vector<ll> bell(n + 1, 0);
    bell[0] = 1;

    for (int i = 1; i <= n; i++) {
        bell[i] = 0;
        for (int k = 0; k < i; k++) {
            bell[i] = (bell[i] + nCr(i - 1, k) * bell[k]) % MOD;
        }
    }
    return bell;
}

// Derangement numbers: number of permutations with no fixed points
ll derangement(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    ll d0 = 1, d1 = 0;
    for (int i = 2; i <= n; i++) {
        ll d2 = ((ll)(i - 1) * (d0 + d1)) % MOD;
        d0 = d1;
        d1 = d2;
    }
    return d1;
}

// ADVANCED DIVISIBILITY:

// Count numbers ≤ n that are divisible by at least one number in the set
ll inclusionExclusionDivisible(ll n, vector<ll> &divisors) {
    ll result = 0;
    int k = divisors.size();

    for (int mask = 1; mask < (1 << k); mask++) {
        ll lcm_val = 1;
        int bits = 0;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                lcm_val = lcm(lcm_val, divisors[i]);
                bits++;
                if (lcm_val > n)
                    break;
            }
        }

        if (lcm_val <= n) {
            ll count = n / lcm_val;
            if (bits % 2 == 1)
                result += count;
            else
                result -= count;
        }
    }

    return result;
}

// SEQUENCES & RECURRENCES:

// MULTIPLICATIVE FUNCTIONS:

// Möbius function: μ(n)
// μ(n) = 1 if n is square-free with even number of prime factors
// μ(n) = -1 if n is square-free with odd number of prime factors
// μ(n) = 0 if n is not square-free

vector<int> mobius;

void computeMobius(int n) {
    mobius.assign(n + 1, 1);
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i; j <= n; j += i) {
                isPrime[j] = false;
                mobius[j] *= -1;
            }
            // Mark multiples of i²
            for (ll j = (ll)i * i; j <= n; j += (ll)i * i) {
                mobius[j] = 0;
            }
        }
    }
}

// Euler's totient function using mobius
ll phiUsingMobius(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n; i++) {
        if (mobius[i] != 0) {
            result += mobius[i] * (n / i);
        }
    }
    return result;
}

// Count pairs (i,j) where 1 ≤ i ≤ n, 1 ≤ j ≤ m, gcd(i,j) = 1
ll countCoprimePairs(ll n, ll m) {
    ll result = 0;
    for (ll i = 1; i <= min(n, m); i++) {
        result += mobius[i] * (n / i) * (m / i);
    }
    return result;
}
// Purpose: Matrix Exponentiation - compute A^n efficiently
// Time: O(k³ log n) where k is matrix dimension
vector<vector<ll>> multiplyMatrices(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
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

// Purpose: Fibonacci with Matrix Exponentiation
// Time: O(log n)
ll fibonacciModulo(ll n) {
    if (n == 0)
        return 0;
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = matrixExponentiation(A, n - 1);
    return result[0][0];
}

// ============================================================================
//                               GEOMETRY
// ============================================================================

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double t) const { return Point(x * t, y * t); }
    double operator*(const Point &p) const { return x * p.x + y * p.y; } // dot product
    double operator^(const Point &p) const { return x * p.y - y * p.x; } // cross product
};

// Purpose: Euclidean distance between two points
// Time: O(1)
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// Count lattice points on line segment from (x1,y1) to (x2,y2)
ll latticePointsOnSegment(ll x1, ll y1, ll x2, ll y2) {
    return gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
}

// Purpose: Manhattan distance between two points
// Time: O(1)
double manhattanDist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

ll euclideanDist2(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

ll manhattanDist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Purpose: Rotate point by angle (in radians)
// Time: O(1)
void rotate(Point &p, double angle) {
    double x_new = p.x * cos(angle) - p.y * sin(angle);
    double y_new = p.x * sin(angle) + p.y * cos(angle);
    p.x = x_new;
    p.y = y_new;
}

double calculateAngleWith_X_Axis(Point p1, Point p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

// BASIC GEOMETRIC FORMULAS:

// Area of triangle using coordinates
double triangleArea(Point a, Point b, Point c) {
    return abs((b - a) ^ (c - a)) / 2.0;
}

// Check if three points are collinear
bool areCollinear(Point a, Point b, Point c) {
    return abs((b - a) ^ (c - a)) < 1e-9;
}

// Orientation test: returns positive if counterclockwise, negative if clockwise, 0 if collinear
double orientation(Point a, Point b, Point c) {
    return (b - a) ^ (c - a);
}

// Check if point lies on line segment
bool pointOnSegment(Point p, Point a, Point b) {
    return areCollinear(p, a, b) &&
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

// CIRCLE GEOMETRY:

struct Circle {
    Point center;
    double radius;
    Circle(Point c = Point(), double r = 0) : center(c), radius(r) {}
};

// Circle through three points
Circle circumcircle(Point a, Point b, Point c) {
    double d = 2 * ((b - a) ^ (c - a));
    if (abs(d) < 1e-9)
        return Circle(); // Points are collinear

    double ux = ((b - a) * (b - a)) * (c.y - a.y) - ((c - a) * (c - a)) * (b.y - a.y);
    double uy = ((c - a) * (c - a)) * (b.x - a.x) - ((b - a) * (b - a)) * (c.x - a.x);

    Point center = Point(a.x + ux / d, a.y + uy / d);
    double radius = dist(center, a);

    return Circle(center, radius);
}

// Check if point is inside circle
bool pointInCircle(Point p, Circle c) {
    return dist(p, c.center) <= c.radius + 1e-9;
}

// Circle-circle intersection
vector<Point> circleIntersection(Circle c1, Circle c2) {
    double d = dist(c1.center, c2.center);
    if (d > c1.radius + c2.radius || d < abs(c1.radius - c2.radius) || d == 0) {
        return {}; // No intersection or infinite intersections
    }

    double a = (c1.radius * c1.radius - c2.radius * c2.radius + d * d) / (2 * d);
    double h = sqrt(c1.radius * c1.radius - a * a);

    Point p = c1.center + (c2.center - c1.center) * (a / d);
    Point delta = Point(-(c2.center.y - c1.center.y), c2.center.x - c1.center.x) * (h / d);

    return {p + delta, p - delta};
}

// LINE GEOMETRY:

struct Line {
    double a, b, c; // ax + by + c = 0
    Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
    Line(Point p1, Point p2) {
        if (abs(p1.x - p2.x) < 1e-9) {
            a = 1;
            b = 0;
            c = -p1.x;
        } else {
            a = p2.y - p1.y;
            b = p1.x - p2.x;
            c = p2.x * p1.y - p1.x * p2.y;
        }
        double norm = sqrt(a * a + b * b);
        a /= norm;
        b /= norm;
        c /= norm;
    }
};

// Distance from point to line
double pointToLineDistance(Point p, Line l) {
    return abs(l.a * p.x + l.b * p.y + l.c);
}

// Line intersection
Point lineIntersection(Line l1, Line l2) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (abs(det) < 1e-9)
        return Point(1e9, 1e9); // Parallel lines

    double x = (l2.c * l1.b - l1.c * l2.b) / det;
    double y = (l1.c * l2.a - l2.c * l1.a) / det;
    return Point(x, y);
}

// Perpendicular line through point
Line perpendicular(Line l, Point p) {
    return Line(-l.b, l.a, l.b * p.x - l.a * p.y);
}

// Parallel line through point
Line parallel(Line l, Point p) {
    return Line(l.a, l.b, -l.a * p.x - l.b * p.y);
}

// POLYGON GEOMETRY:

// Area of simple polygon (positive if counterclockwise)
double polygonArea(vector<Point> &poly) {
    double area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        area += poly[i] ^ poly[(i + 1) % n];
    }
    return area / 2.0;
}

// Check if polygon is convex
bool isConvex(vector<Point> &poly) {
    int n = poly.size();
    if (n < 3)
        return false;

    bool positive = false, negative = false;
    for (int i = 0; i < n; i++) {
        double cross = orientation(poly[i], poly[(i + 1) % n], poly[(i + 2) % n]);
        if (cross > 1e-9)
            positive = true;
        if (cross < -1e-9)
            negative = true;
        if (positive && negative)
            return false;
    }
    return true;
}

// Point in polygon test (ray casting)
bool pointInPolygon(Point p, vector<Point> &poly) {
    int n = poly.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
            (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

// Convex hull (Graham scan)
vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n <= 1)
        return points;

    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    // Build lower hull
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Build upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove duplicate point
    return hull;
}

// ADVANCED TECHNIQUES:

// Rotating calipers - find diameter of convex polygon
double rotatingCalipers(vector<Point> &hull) {
    int n = hull.size();
    if (n <= 1)
        return 0;
    if (n == 2)
        return dist(hull[0], hull[1]);

    double maxDist = 0;
    int j = 1;

    for (int i = 0; i < n; i++) {
        Point edge = hull[(i + 1) % n] - hull[i];

        while (true) {
            Point toNext = hull[(j + 1) % n] - hull[j];
            if ((edge ^ toNext) <= 0)
                break;
            j = (j + 1) % n;
        }

        maxDist = max(maxDist, max(dist(hull[i], hull[j]),
                                   dist(hull[(i + 1) % n], hull[j])));
    }

    return maxDist;
}

// Closest pair of points (divide and conquer)
double closestPairRec(vector<Point> &px, vector<Point> &py) {
    int n = px.size();
    if (n <= 3) {
        double minDist = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                minDist = min(minDist, dist(px[i], px[j]));
            }
        }
        return minDist;
    }

    int mid = n / 2;
    Point midPoint = px[mid];

    vector<Point> pyl(mid), pyr(n - mid);
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
        if (py[i].x <= midPoint.x && li < mid)
            pyl[li++] = py[i];
        else
            pyr[ri++] = py[i];
    }

    vector<Point> pxl(px.begin(), px.begin() + mid);
    vector<Point> pxr(px.begin() + mid, px.end());

    double dl = closestPairRec(pxl, pyl);
    double dr = closestPairRec(pxr, pyr);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; i++) {
        if (abs(py[i].x - midPoint.x) < d) {
            strip.push_back(py[i]);
        }
    }

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

double closestPair(vector<Point> &points) {
    vector<Point> px = points, py = points;
    sort(px.begin(), px.end(), [](Point a, Point b) { return a.x < b.x; });
    sort(py.begin(), py.end(), [](Point a, Point b) { return a.y < b.y; });
    return closestPairRec(px, py);
}

// GEOMETRIC CONSTANTS & FORMULAS:

const double GOLDEN_RATIO = (1.0 + sqrt(5.0)) / 2.0;

// Regular polygon properties
double regularPolygonArea(int n, double sideLength) {
    return (n * sideLength * sideLength) / (4 * tan(PI / n));
}

double regularPolygonPerimeter(int n, double sideLength) {
    return n * sideLength;
}

double regularPolygonCircumradius(int n, double sideLength) {
    return sideLength / (2 * sin(PI / n));
}

double regularPolygonInradius(int n, double sideLength) {
    return sideLength / (2 * tan(PI / n));
}

// COORDINATE TRANSFORMATIONS:

// Translate point
Point translate(Point p, double dx, double dy) {
    return Point(p.x + dx, p.y + dy);
}

// Scale point from origin
Point scale(Point p, double sx, double sy) {
    return Point(p.x * sx, p.y * sy);
}

// Reflect point across line y = mx + b
Point reflect(Point p, double m, double b) {
    double a = -m, c = -b; // Line: ax + y + c = 0
    double norm = a * a + 1;
    double x = p.x - 2 * a * (a * p.x + p.y + c) / norm;
    double y = p.y - 2 * (a * p.x + p.y + c) / norm;
    return Point(x, y);
}

// SPECIAL TRIANGLES:

// Check if triangle is right-angled
bool isRightTriangle(Point a, Point b, Point c) {
    double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
    vector<double> sides = {ab, bc, ca};
    sort(sides.begin(), sides.end());
    return abs(sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2]) < 1e-9;
}

// Triangle centers
Point centroid(Point a, Point b, Point c) {
    return Point((a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3);
}

Point circumcenter(Point a, Point b, Point c) {
    return circumcircle(a, b, c).center;
}

Point orthocenter(Point a, Point b, Point c) {
    Line altA = perpendicular(Line(b, c), a);
    Line altB = perpendicular(Line(a, c), b);
    return lineIntersection(altA, altB);
}

// Normalize a direction vector (dx, dy)
// helpful to know points that are on same line.
void normalizeDirection(long long &dx, long long &dy) {
    // --- Step 1: Handle signs consistently ---
    if (dx * dy < 0) {
        // Opposite signs → make dx negative, dy positive
        dx = -abs(dx);
        dy = abs(dy);
    } else if (dx * dy > 0) {
        // Same signs → make both positive
        dx = abs(dx);
        dy = abs(dy);
    } else {
        // One of them is zero (pure horizontal or vertical)
        if (dy)
            dy = 1e6; // placeholder to represent "vertical"
        if (dx)
            dx = 1e6; // placeholder to represent "horizontal"
    }

    // --- Step 2: Reduce to simplest ratio ---
    long long g = std::gcd(abs(dx), abs(dy));
    if (g != 0) {
        dx /= g;
        dy /= g;
    }
}
// ============================================================================
// ADDITIONAL GEOMETRY FUNCTIONS FOR COMPETITIVE PROGRAMMING
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const long long INF = 1e18;

struct Point {
    long long x, y;
    int id;
    Point(long long x = 0, long long y = 0, int id = -1) : x(x), y(y), id(id) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator*(long long t) const { return Point(x * t, y * t); }
    long long cross(const Point &p) const { return x * p.y - y * p.x; }
    long long dot(const Point &p) const { return x * p.x + y * p.y; }
    long long dist2() const { return x * x + y * y; }
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

// Purpose: Check if point c lies on line segment ab
// Time: O(1)
bool pointOnSegment(Point a, Point b, Point c) {
    if ((b - a).cross(c - a) != 0) return false;
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

// Purpose: Check if two line segments ab and cd intersect
// Time: O(1)
bool segmentsIntersect(Point a, Point b, Point c, Point d) {
    long long d1 = (b - a).cross(c - a);
    long long d2 = (b - a).cross(d - a);
    long long d3 = (d - c).cross(a - c);
    long long d4 = (d - c).cross(b - c);
    
    // Proper intersection (segments cross each other)
    if (((d1 > 0) != (d2 > 0)) && ((d3 > 0) != (d4 > 0))) {
        return true;
    }
    
    // Collinear cases - check if endpoints lie on the other segment
    if (d1 == 0 && pointOnSegment(a, b, c)) return true;
    if (d2 == 0 && pointOnSegment(a, b, d)) return true;
    if (d3 == 0 && pointOnSegment(c, d, a)) return true;
    if (d4 == 0 && pointOnSegment(c, d, b)) return true;
    
    return false;
}

// Purpose: Check if two segments intersect at exactly one point (no overlap)
// Time: O(1)
bool segmentsIntersectStrict(Point a, Point b, Point c, Point d) {
    long long d1 = (b - a).cross(c - a);
    long long d2 = (b - a).cross(d - a);
    long long d3 = (d - c).cross(a - c);
    long long d4 = (d - c).cross(b - c);
    
    return ((d1 > 0) != (d2 > 0)) && ((d3 > 0) != (d4 > 0));
}

// Purpose: Find intersection point of two line segments (if exists)
// Time: O(1)
// Returns: intersection point or Point(INF, INF) if no intersection
Point segmentIntersectionPoint(Point a, Point b, Point c, Point d) {
    long long d1 = (b - a).cross(c - a);
    long long d2 = (b - a).cross(d - a);
    long long d3 = (d - c).cross(a - c);
    long long d4 = (d - c).cross(b - c);
    
    // Check if segments intersect
    if (!(((d1 > 0) != (d2 > 0)) && ((d3 > 0) != (d4 > 0)))) {
        // Check collinear cases
        if (d1 == 0 && pointOnSegment(a, b, c)) return c;
        if (d2 == 0 && pointOnSegment(a, b, d)) return d;
        if (d3 == 0 && pointOnSegment(c, d, a)) return a;
        if (d4 == 0 && pointOnSegment(c, d, b)) return b;
        return Point(INF, INF); // No intersection
    }
    
    // Calculate intersection point using cross products
    long long num_x = (a.x * (b.y - a.y) - a.y * (b.x - a.x)) * (d.x - c.x) - 
                      (c.x * (d.y - c.y) - c.y * (d.x - c.x)) * (b.x - a.x);
    long long num_y = (a.x * (b.y - a.y) - a.y * (b.x - a.x)) * (d.y - c.y) - 
                      (c.x * (d.y - c.y) - c.y * (d.x - c.x)) * (b.y - a.y);
    long long den = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    
    if (den == 0) return Point(INF, INF); // Parallel lines
    
    // Note: This returns integer coordinates only if intersection is at integer point
    return Point(num_x / den, num_y / den);
}

// Purpose: Distance from point to line segment
// Time: O(1)
double distancePointToSegment(Point p, Point a, Point b) {
    Point ab = b - a;
    Point ap = p - a;
    
    if (ab.dist2() == 0) return sqrt(ap.dist2()); // Segment is a point
    
    long long t_num = ap.dot(ab);
    long long t_den = ab.dist2();
    
    if (t_num <= 0) return sqrt(ap.dist2()); // Closest to point a
    if (t_num >= t_den) return sqrt((p - b).dist2()); // Closest to point b
    
    // Projection lies on segment
    double t = (double)t_num / t_den;
    Point projection = Point(a.x + t * ab.x, a.y + t * ab.y);
    return sqrt((p.x - projection.x) * (p.x - projection.x) + 
                (p.y - projection.y) * (p.y - projection.y));
}

// Purpose: Check visibility between two points in a polygon
// Time: O(n) where n is number of polygon vertices
bool isVisible(const vector<Point>& polygon, int from, int to) {
    if (from == to) return true;
    
    Point start = polygon[from];
    Point end = polygon[to];
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        
        // Skip edges that contain start or end points
        if (i == from || next == from || i == to || next == to) {
            continue;
        }
        
        if (segmentsIntersectStrict(start, end, polygon[i], polygon[next])) {
            return false;
        }
    }
    
    return true;
}

// Purpose: Check visibility from external point to polygon vertex
// Time: O(n)
bool isVisibleFromPoint(const vector<Point>& polygon, Point external, int vertexIndex) {
    Point vertex = polygon[vertexIndex];
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        
        // Skip edges that contain the target vertex
        if (i == vertexIndex || next == vertexIndex) {
            continue;
        }
        
        if (segmentsIntersect(external, vertex, polygon[i], polygon[next])) {
            return false;
        }
    }
    
    return true;
}

// Purpose: Check if point is strictly inside polygon (not on boundary)
// Time: O(n)
bool pointStrictlyInPolygon(Point p, const vector<Point>& polygon) {
    int n = polygon.size();
    bool inside = false;
    
    for (int i = 0, j = n - 1; i < n; j = i++) {
        // First check if point is on edge
        if (pointOnSegment(polygon[i], polygon[j], p)) {
            return false; // Point is on boundary, not strictly inside
        }
        
        // Ray casting algorithm
        if (((polygon[i].y > p.y) != (polygon[j].y > p.y)) &&
            (p.x < polygon[i].x + (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y))) {
            inside = !inside;
        }
    }
    
    return inside;
}

// Purpose: Find all polygon vertices visible from a given external point
// Time: O(n²) - can be optimized to O(n log n) with advanced techniques
vector<int> findVisibleVertices(const vector<Point>& polygon, Point external) {
    vector<int> visible;
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        if (isVisibleFromPoint(polygon, external, i)) {
            visible.push_back(i);
        }
    }
    
    return visible;
}

// Purpose: Calculate signed area of polygon (positive = counterclockwise)
// Time: O(n)
long long signedPolygonArea2(const vector<Point>& polygon) {
    long long area = 0;
    int n = polygon.size();
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += polygon[i].cross(polygon[next]);
    }
    
    return area; // Multiply by 2 to avoid floating point
}

// Purpose: Check if polygon vertices are in counterclockwise order
// Time: O(n)
bool isCounterClockwise(const vector<Point>& polygon) {
    return signedPolygonArea2(polygon) > 0;
}

// Purpose: Reverse polygon orientation if needed to make it counterclockwise
// Time: O(n)
void ensureCounterClockwise(vector<Point>& polygon) {
    if (!isCounterClockwise(polygon)) {
        reverse(polygon.begin(), polygon.end());
    }
}

// Purpose: Find the leftmost-bottommost point in a set of points
// Time: O(n)
int findBottomLeftPoint(const vector<Point>& points) {
    int idx = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < points[idx].y || 
           (points[i].y == points[idx].y && points[i].x < points[idx].x)) {
            idx = i;
        }
    }
    return idx;
}

// Purpose: Compare points by polar angle relative to a base point
// Time: O(1)
struct PolarAngleComparator {
    Point base;
    PolarAngleComparator(Point b) : base(b) {}
    
    bool operator()(const Point& a, const Point& b) {
        Point va = a - base;
        Point vb = b - base;
        long long cross = va.cross(vb);
        
        if (cross == 0) {
            // Same angle, sort by distance
            return va.dist2() < vb.dist2();
        }
        
        return cross > 0; // Counterclockwise order
    }
};

/*
USAGE EXAMPLES:

1. Visibility Problem (like the contest problem):
   vector<int> visible = findVisibleVertices(polygon, Point(0, 0));

2. Line Segment Intersection:
   if (segmentsIntersect(a, b, c, d)) {
       Point intersection = segmentIntersectionPoint(a, b, c, d);
   }

3. Point-to-Line Distance:
   double dist = distancePointToSegment(point, lineStart, lineEnd);

4. Polygon Orientation:
   ensureCounterClockwise(polygon);

5. Visibility within Polygon:
   bool canSee = isVisible(polygon, vertex1Index, vertex2Index);
*/



*****************************************************************************************

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point &other) const {
        if (fabs(x - other.x) > 1e-9) return x < other.x;
        return y < other.y;
    }
};

struct Line {
    double a, b, c;
};

Line getLine(double x1, double y1, double x2, double y2) {
    Line L;
    L.a = y1 - y2;
    L.b = x2 - x1;
    L.c = x1 * y2 - x2 * y1;
    return L;
}

// تحقق من تقاطع خطين
bool intersect(Line l1, Line l2, Point &p) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (fabs(det) < 1e-12) return false; // خطوط متوازية
    p.x = (l1.b * l2.c - l2.b * l1.c) / det;
    p.y = (l1.c * l2.a - l2.c * l1.a) / det;
    return true;
}

// حساب مساحة مضلع
double polygonArea(const vector<Point> &poly) {
    double A = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        int j = (i+1)%n;
        A += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return fabs(A) / 2.0;
}

// اتجاه بين نقطتين
Point dir(Point a, Point b) {
    return {b.x - a.x, b.y - a.y};
}

// cross product
double cross(Point a, Point b) {
    return a.x*b.y - a.y*b.x;
}

int main() {
    // مثال: 4 خطوط تشكل مربع 1x1
    vector<pair<Point, Point>> lines = {
        {{0,0},{1,0}}, // L1
        {{0,1},{1,1}}, // L2
        {{0,0},{0,1}}, // L3
        {{1,0},{1,1}}  // L4
    };
    
    int N = lines.size();
    vector<Line> lineForms;
    for(auto &p: lines)
        lineForms.push_back(getLine(p.first.x,p.first.y,p.second.x,p.second.y));

    // 1. إيجاد نقاط التقاطع
    set<Point> pointsSet;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            Point p;
            if(intersect(lineForms[i], lineForms[j], p))
                pointsSet.insert(p);
        }
    }
    vector<Point> points(pointsSet.begin(), pointsSet.end());
    
    // 2. بناء الرسم البياني (adjacency list)
    map<Point, vector<Point>> adj;
    for(auto &l: lines){
        vector<Point> onLine;
        for(auto &p: points){
            // تحقق إن النقطة على الخط
            double val = l.second.x - l.first.x !=0 ? (p.x - l.first.x)/(l.second.x - l.first.x) : (p.y - l.first.y)/(l.second.y - l.first.y);
            double valY = (p.y - l.first.y);
            if(fabs(valY - val*(l.second.y - l.first.y)) < 1e-9)
                onLine.push_back(p);
        }
        sort(onLine.begin(), onLine.end(), [&](Point a, Point b){
            if(fabs(a.x - b.x) > 1e-9) return a.x < b.x;
            return a.y < b.y;
        });
        for(int i=0;i+1<onLine.size();i++){
            adj[onLine[i]].push_back(onLine[i+1]);
            adj[onLine[i+1]].push_back(onLine[i]);
        }
    }
    
    // 3. Left-turn walk لاكتشاف المضلع
    map<pair<Point, Point>, bool> used;
    double minArea = 1e18;
    
    for(auto &[p, neighbors]: adj){
        for(auto &q: neighbors){
            if(used[{p,q}]) continue;
            vector<Point> face;
            Point start = p, next = q;
            Point u = start, v = next;
            while(true){
                face.push_back(u);
                used[{u,v}] = true;
                // اختيار أقصى يسار
                Point dv = dir(u,v);
                Point best;
                double bestCross = -1e18;
                for(auto &w: adj[v]){
                    if((fabs(w.x-u.x)<1e-9 && fabs(w.y-u.y)<1e-9)) continue;
                    Point dw = dir(v,w);
                    double c = cross(dv,dw);
                    if(c > bestCross){
                        bestCross = c;
                        best = w;
                    }
                }
                Point nxt = best;
                u = v; v = nxt;
                if(fabs(u.x-start.x)<1e-9 && fabs(u.y-start.y)<1e-9 && fabs(v.x-next.x)<1e-9 && fabs(v.y-next.y)<1e-9)
                    break;
            }
            double area = polygonArea(face);
            if(area>1e-9)
                minArea = min(minArea, area);
        }
    }
    
    if(minArea > 1e17) cout << -1 << endl;
    else printf("%.6f\n", minArea);

    return 0;
}

**********************************************************************************************************


// حساب مركز الدائرة الداخلية
Point incenter(Point a, Point b, Point c) {
    double ab = distance(a, b); // الضلع المقابل لـ c
    double bc = distance(b, c); // الضلع المقابل لـ a
    double ca = distance(c, a); // الضلع المقابل لـ b
    
    double perimeter = ab + bc + ca;
    
    // حساب الإحداثيات باستخدام الأوزان (أطوال الأضلاع)
    double x = (bc * a.x + ca * b.x + ab * c.x) / perimeter;
    double y = (bc * a.y + ca * b.y + ab * c.y) / perimeter;
    
    return Point(x, y);
}


***********************************************************************************************************
// USEFUL GEOMETRIC FACTS:

/*
1. Euler Line: In any triangle, the circumcenter, centroid, and orthocenter are collinear
2. Nine-point circle: Passes through 9 special points including midpoints of sides
3. Napoleon's Theorem: Constructing equilateral triangles on sides of any triangle
4. Pick's Theorem: Area = Interior_Points + Boundary_Points/2 - 1
5. Shoelace Formula: Area = |Σ(xi*yi+1 - xi+1*yi)| / 2
6. For convex polygons: sum of interior angles = (n-2) * 180°
7. Circle through 3 points has center at intersection of perpendicular bisectors
8. Incenter is intersection of angle bisectors
9. Pappus-Guldinus: Volume = Area × distance traveled by centroid
10. Law of Cosines: c² = a² + b² - 2ab*cos(C)
11. Law of Sines: a/sin(A) = b/sin(B) = c/sin(C) = 2R
12. Heron's formula: Area = √[s(s-a)(s-b)(s-c)] where s = (a+b+c)/2
*/
